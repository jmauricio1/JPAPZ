using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Final1.DAL;
//using Final1.DAL;//maybe add this ,not sure for now
using Final1.Models;//Add this for the ajax call function 
using Newtonsoft.Json;//Add this for the json and content return part



namespace Final1.Controllers
{
    public class HomeController : Controller

    {
        VideoContext db = new VideoContext();//ADD THE VideoContext here (very important)
        public ActionResult Index()
        {
            ViewBag.TagNames = db.Tags.Select(s => s.TagName);//
            return View();
        }

        public ActionResult Video(string tagName)
        {
            var videosTagged = db.VideoTags.Where(s => s.Tag.TagName.Contains(tagName)).Select(s => s.Video.Title);//add your own query
            string jsonString = JsonConvert.SerializeObject(videosTagged, Formatting.Indented);//new add

            return new ContentResult// copy this format down
            {
                Content = jsonString,// copy this format down
                ContentType = "application/json",// copy this format down
                ContentEncoding = System.Text.Encoding.UTF8// copy this format down
            };// copy this format down

        }// copy this format down


    }
}