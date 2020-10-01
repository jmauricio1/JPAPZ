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

            if ((string)data["error"] == "Player Not Found")
            {
                Debug.WriteLine("No data to display");
                string temp = "No data to display";
                return Json(temp, JsonRequestBehavior.AllowGet);
            }

            int totalElims =
                (int)data["stats"]["p2"]["kills"]["valueInt"] +
                (int)data["stats"]["p10"]["kills"]["valueInt"] +
                (int)data["stats"]["p9"]["kills"]["valueInt"];

            int totalWins =
                (int)data["stats"]["p2"]["top1"]["valueInt"] +
                (int)data["stats"]["p10"]["top1"]["valueInt"] +
                (int)data["stats"]["p9"]["top1"]["valueInt"];

            int totalMatches =
                (int)data["stats"]["p2"]["matches"]["valueInt"] +
                (int)data["stats"]["p10"]["matches"]["valueInt"] +
                (int)data["stats"]["p9"]["matches"]["valueInt"];

            PlayerStats playerStats = new PlayerStats();
            playerStats.soloWins = (int)data["stats"]["p2"]["top1"]["valueInt"];
            playerStats.soloTop10 = (int)data["stats"]["p2"]["top10"]["valueInt"];
            playerStats.soloTop25 = (int)data["stats"]["p2"]["top25"]["valueInt"];
            playerStats.soloMatches = (int)data["stats"]["p2"]["matches"]["valueInt"];
            playerStats.soloElims = (int)data["stats"]["p2"]["kills"]["valueInt"];

            playerStats.duoWins = (int)data["stats"]["p10"]["top1"]["valueInt"];
            playerStats.duoTop5 = (int)data["stats"]["p10"]["top10"]["valueInt"];
            playerStats.duoTop12 = (int)data["stats"]["p10"]["top25"]["valueInt"];
            playerStats.duoMatches = (int)data["stats"]["p10"]["matches"]["valueInt"];
            playerStats.duoElims = (int)data["stats"]["p10"]["kills"]["valueInt"];

            playerStats.squadWins = (int)data["stats"]["p9"]["top1"]["valueInt"];
            playerStats.squadsTop3 = (int)data["stats"]["p9"]["top10"]["valueInt"];
            playerStats.squadsTop6 = (int)data["stats"]["p9"]["top25"]["valueInt"];
            playerStats.squadsMatches = (int)data["stats"]["p9"]["matches"]["valueInt"];
            playerStats.squadElims = (int)data["stats"]["p9"]["kills"]["valueInt"];

            playerStats.username = username;
            playerStats.wins = playerStats.soloWins + playerStats.duoWins + playerStats.squadWins;//totalWins; /*(int)data["lifeTimeStats"][8]["value"];*/
            playerStats.matches = totalMatches; /*(int)data["lifeTimeStats"][7]["value"];*/
            playerStats.elims = totalElims; /*(int)data["lifeTimeStats"][10]["value"];*/
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
        public int wins;
        public int matches;
        public int elims;
        public double kd;

        /* Solos Information*/
        public int soloWins; //Solo Wins
        public int soloTop10;
        public int soloTop25;
        public int soloMatches;
        public int soloElims;

        /* Duos Information*/
        public int duoWins; //Duo Wins
        public int duoTop5;
        public int duoTop12;
        public int duoMatches;
        public int duoElims;

        /* Squads Information*/
        public int squadWins;
        public int squadsTop3;
        public int squadsTop6;
        public int squadsMatches;
        public int squadElims;
    }
}