using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Newtonsoft.Json.Linq;
using System.IO;
using System.Net;

namespace practice_proj.Controllers
{
    public class CharactersController : Controller
    {
        // GET: Characters
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult Info()
        {
            return View();
        }

        public JsonResult GetCharacters()
        {
            string json = SendRequest("https://swapi.dev/api/people");
            JObject data = JObject.Parse(json);

            GetCharacterlist list = new GetCharacterlist();

            List<GetCharacterlist> tempList = new List<GetCharacterlist>();

            for (int i = 0; i < data["results"].Count(); i++)
            {
                GetCharacterlist x = new GetCharacterlist();
                x.name = (string)data["results"][i]["name"];
                x.id = i + 1;               //id for specific characters

                tempList.Add(x);
            }

            return Json(tempList, JsonRequestBehavior.AllowGet);
        }

        //Create method in CharactersController to retrieve information of a specific Star Wars characters
        public JsonResult SpecificCharacters(string id)
        {
            string json = SendRequest("https://swapi.dev/api/people/" + id);
            JObject data = JObject.Parse(json);

            GetCharacterlist current = new GetCharacterlist();
            current.name = (string)data["name"];

            CharacterInfo x = new CharacterInfo();
            x.name = (string)data["name"];
            x.height = (string)data["height"];
            x.mass = (string)data["mass"];
            x.hair_color = (string)data["hair_color"];
            x.skin_color = (string)data["skin_color"];
            x.eye_color = (string)data["eye_color"];
            x.birth_year = (string)data["birth_year"];
            x.gender = (string)data["gender"];

            return Json(x, JsonRequestBehavior.AllowGet);
        }

        private string SendRequest(string uri)
        {
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(uri);
            /*            request.Headers.Add("Authorization", "token " + credentials);
                        request.UserAgent = username;       // Required, see: https://developer.github.com/v3/#user-agent-required
                        request.Accept = "application/json";*/

            string jsonString = null;
            // TODO: You should handle exceptions here
            using (WebResponse response = request.GetResponse())
            {
                Stream stream = response.GetResponseStream();
                StreamReader reader = new StreamReader(stream);
                jsonString = reader.ReadToEnd();
                reader.Close();
                stream.Close();
            }
            return jsonString;
        }
    }
    public class GetCharacterlist
    {
        public string name;
        public int id;
    }

    public class CharacterInfo
    {
        public string name;
        public string height;
        public string mass;
        public string hair_color;
        public string skin_color;
        public string eye_color;
        public string birth_year;
        public string gender;
    }
}