using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;

namespace fortnite_project.Controllers
{
    public class APIController : Controller
    {
        // GET: API
        public ActionResult Index()
        {
            return View();
        }

        public JsonResult GetPlayerStats(string username)
        {
            string json = SendRequest("https://api.fortnitetracker.com/v1/profile/pc/" + username);
            JObject data = JObject.Parse(json);

            Debug.WriteLine("Something");
            Debug.WriteLine(data);

            PlayerStats playerStats = new PlayerStats();
            playerStats.username = username;
            playerStats.matches = (int)data["lifeTimeStats"][7]["value"];
            playerStats.elims = (int)data["lifeTimeStats"][10]["value"];
            playerStats.kd = Math.Round(((double)playerStats.elims / (double)playerStats.matches), 2);
            return Json(playerStats, JsonRequestBehavior.AllowGet);
        }

        private string SendRequest(string uri)
        {
            Debug.WriteLine("URI: " + uri);
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(uri);
            /*            request.Headers.Add("Authorization", "token " + credentials);
                        request.UserAgent = username;       // Required, see: https://developer.github.com/v3/#user-agent-required
                        request.Accept = "application/json";*/
            request.Headers.Add("TRN-Api-Key", "c4c101dd-2b29-43f9-813f-051c6cda16e5");

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

    public class PlayerStats
    {
        public string username;
        public int matches;
        public int elims;
        public double kd;
    }
}