using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using LaunchMe.Models;
using LaunchMe.Models.ViewModels;

namespace LaunchMe.Controllers
{
    public class LaunchListController : Controller
    {
        // GET: LaunchList
        public ActionResult Index()
        {
            return View();
        }
        /*public class Launch
        {
            //Launch Information
            public string missionName;
            public string launchSuccess;
            public int flightNum;
            public string launchTime;
            public int launchYear;

            //Rocket Information
            public string rocketName;
            public string rocketType;
            public string rocketID;
            public string launchDetails;
        }*/
        public JsonResult ViewList()
        {
            string json = SendRequest("https://api.spacexdata.com/v3/launches");

            JArray data = JArray.Parse(json);
            List<Launch> launches = new List<Launch>();

            for (int i = 0; i < data.Count; i++)
            {
                Launch launch = new Launch();

                launch.missionName = (string)data[i]["mission_name"];
                launch.flightNum = (int)data[i]["flight_number"];
                launch.launchSuccess = (string)data[i]["launch_success"];
                launch.launchYear = (int)data[i]["launch_year"];

                launches.Add(launch);
            }

            return Json(launches, JsonRequestBehavior.AllowGet);
        }
        public JsonResult ViewLaunches()
        {
            string json = SendRequest("https://api.spacexdata.com/v3/launches");

            JArray data = JArray.Parse(json);
            List<Launch> launches = new List<Launch>();

            for (int i = 0; i < data.Count; i++)
            {
                Launch launch = new Launch();

                launch.missionName = (string)data[i]["mission_name"];
                launch.launchSuccess = (string)data[i]["launch_success"];
                launch.flightNum = (int)data[i]["flight_number"];
                launch.launchTime = (string)data[i]["launch_date_utc"];
                launch.launchYear = (int)data[i]["launch_year"];

                launch.rocketName = (string)data[i]["rocket"]["rocket_name"];
                launch.rocketType = (string)data[i]["rocket"]["rocket_type"];
                launch.rocketID = (string)data[i]["rocket"]["rocket_id"];
                launch.launchDetails = (string)data[i]["details"];

                launches.Add(launch);
            }

            return Json(launches, JsonRequestBehavior.AllowGet);
        }

        public ActionResult Details(int? id)
        {
            string json = SendRequest("https://api.spacexdata.com/v3/launches");
            JArray data = JArray.Parse(json);

            Launch launchDetails = new Launch();

            id--;
            launchDetails.missionName = (string)data[id]["mission_name"];
            launchDetails.launchSuccess = (string)data[id]["launch_success"];
            launchDetails.flightNum = (int)data[id]["flight_number"];
            launchDetails.launchTime = (string)data[id]["launch_date_utc"];
            launchDetails.launchYear = (int)data[id]["launch_year"];

            launchDetails.rocketName = (string)data[id]["rocket"]["rocket_name"];
            launchDetails.rocketType = (string)data[id]["rocket"]["rocket_type"];
            launchDetails.rocketID = (string)data[id]["rocket"]["rocket_id"];
            launchDetails.launchDetails = (string)data[id]["details"];

            ViewBag.Success = true;

            LaunchViewModel viewModel = new LaunchViewModel(launchDetails);
            return View(viewModel);
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
}