using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace MathExample.Controllers
{
    public class HomeController : Controller
    {
        [HttpGet]
        public ActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Index(int? x, int? y)
        {
            //Check to see if values are coming in
            Debug.WriteLine("X Value Input:" + x);
            Debug.WriteLine("Y Value Input:" + y);

            //Do something with data
            int? z = x + y;
            double? thing = Math.Pow(7, 7);
            Debug.WriteLine("Z Value Ouput:" + z);

            //Return the data to the view
            /*
             * ViewBags
             * Models
             */
            ViewBag.ZValue = z;


            double a = 3;
            double b = 4;
            double c = 5;

            double tempSQRT = Math.Sqrt((b * b) - (4 * a * c));
            Debug.WriteLine("Temp SQRT: " + tempSQRT);
            double res1 = ((b * -1) + tempSQRT) / (2 * a);
            double res2 = ((b * -1) - tempSQRT) / (2 * a);

            Debug.WriteLine("Result 1: " + res1);
            Debug.WriteLine("Result 2: " + res2);

            return View();
        }
    }
}