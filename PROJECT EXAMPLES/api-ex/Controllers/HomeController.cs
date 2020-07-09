using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Security.Cryptography.X509Certificates;
using System.Web;
using System.Web.Mvc;

namespace api_ex.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }

        public JsonResult GetWeather(string city)
        {
            string json = SendRequest("https://www.metaweather.com/api/location/search/?query=" + city);
            JArray data = JArray.Parse(json);

            List<int> WOEID = new List<int>();

            for(int i = 0; i < data.Count(); i++)
            {
                WOEID.Add((int)data[i]["woeid"]);
            }

            json = SendRequest("https://www.metaweather.com/api/location/" + WOEID[0]);

            JObject info = JObject.Parse(json);

            Location location = new Location();
            location.name = (string)info["title"];

            for(int i = 0; i < info["consolidated_weather"].Count(); i++)
            {
                Weather temp = new Weather();

                temp.weatherStateName = (string)info["consolidated_weather"][i]["weather_state_name"];
                temp.minTemp = (string)info["consolidated_weather"][i]["min_temp"];
                temp.maxTemp = (string)info["consolidated_weather"][i]["max_temp"];
                temp.date = (string)info["consolidated_weather"][i]["applicable_date"];

                location.weathers.Add(temp);
            }

            return Json(location, JsonRequestBehavior.AllowGet);
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

    public class Location
    {
        public string name; //title
        public List<Weather> weathers = new List<Weather>();
    }

    public class Weather
    {
        public string weatherStateName;
        public string minTemp;
        public string maxTemp;
        public string date;
    }
}