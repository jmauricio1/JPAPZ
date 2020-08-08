using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

/* Hello Joshua!
 */

namespace practice_proj.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()//This is penny's comment.
        {
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();      //create a pull request from Kim!
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page."; 

            return View();      //create a pull request from Kim!
        }
    }
}