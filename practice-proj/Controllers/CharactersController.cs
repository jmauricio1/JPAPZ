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


        public JsonResult GetCharacters()
        {
            string json = SendRequest("https://swapi.dev/api/people");
            JObject data = JObject.Parse(json);

            GetCharacterlist list = new GetCharacterlist();

            List<GetCharacterlist> tempList = new List<GetCharacterlist>();

            for(int i = 0; i < data["results"].Count(); i++)
            {
                GetCharacterlist x = new GetCharacterlist();
                x.name = (string)data["results"][i]["name"];
                x.height = (string)data["results"][i]["height"];
              
                

                tempList.Add(x);
            }

            return Json(tempList, JsonRequestBehavior.AllowGet);
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
        //public string height;
        //public List<GetCharacterlist> list;
    }




}