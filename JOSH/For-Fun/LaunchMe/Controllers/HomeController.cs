using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;

namespace LaunchMe.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        public JsonResult ViewLaunches()
        {
            string json = SendRequest("https://api.spacexdata.com/v3/launches");

            JArray data = JArray.Parse(json);
            List<Launch> launches= new List<Launch>();

            for(int i = 0; i < data.Count; i++)
            {
                Launch launch = new Launch();

                /*if(String.IsNullOrEmpty((string)data[i]["flight_number"]) == true)
                {
                    launch.flightNum = -1;
                }
                else
                {*/
                    launch.flightNum = (int)data[i]["flight_number"];
                //}

                launch.missionName = (string)data[i]["mission_name"];
                launch.launchYear = (int)data[i]["launch_year"];
                launch.rocketName = (string)data[i]["rocket"]["rocket_name"];
                launch.rocketType = (string)data[i]["rocket"]["rocket_type"];
                launch.launchSuccess = (string)data[i]["launch_success"];
                //launch.launchFailureDetails = (string)data[i]["launch_failure_details"]["reason"];
                launch.rocketID = (string)data[i]["rocket"]["rocket_id"];
                launch.launchDetails = (string)data[i]["details"];

                launches.Add(launch);
            }

            return Json(launches, JsonRequestBehavior.AllowGet);
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

        public class Launch {
            public int flightNum;
            public string missionName;
            public int launchYear;
            public string rocketName;
            public string rocketType;
            public string launchSuccess;
            //public string launchFailureDetails;
            public string rocketID;
            public string launchDetails;
        }
    }
}