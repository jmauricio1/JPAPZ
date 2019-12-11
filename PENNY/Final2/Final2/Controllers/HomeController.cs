using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Final2.DAL;
using Final2.Models;
using Newtonsoft.Json;

namespace Final2.Controllers
{
    public class HomeController : Controller
    {
        AstronautContext db = new AstronautContext();
        public ActionResult Index()
        {
            ViewBag.Designations = db.Missions.Select(s => s.Designation);
            return View();
        }

        public ActionResult MissionCrew(string missionDesignation)
        {
            var astronautsCrew = db.Crews.Where(s => s.Mission.Designation.Contains(missionDesignation)).Select(s => new { AName = s.Astronaut.AstronautName, ANat = s.Astronaut.Country.Nationality }); 
            string jsonString = JsonConvert.SerializeObject(astronautsCrew, Formatting.Indented);

            return new ContentResult
            {
                Content = jsonString,
                ContentType = "application/json",
                ContentEncoding = System.Text.Encoding.UTF8
            };
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
    }
}