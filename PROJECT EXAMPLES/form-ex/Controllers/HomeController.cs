using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace form_ex.Controllers
{
    public class HomeController : Controller
    {
        [HttpGet]
        public ActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Index(string noun1, string verb, string noun2)
        {
            string output = "";
            string other = "";
            //NO Helper Functions
            if (noun1 != null && verb != null && noun2!= null)
            {
                output = "A " + noun1 + " tried to " + verb + " with a " + noun2 + ".";
            }
            else
            {
                output = "Please enter valid inputs.";
            }

            //With Helper Functions
            if(CheckInput(noun1) && CheckInput(verb) && CheckInput(noun2))
            {
                other = "A " + noun1 + " tried to " + verb + " with a " + noun2 + ".";
            }
            else
            {
                other = "Please enter valid inputs.";
            }

            ViewBag.Sentence1 = output;
            ViewBag.Sentence2 = other;
            return View();
        }

        public bool CheckInput(string input)
        {
            bool valid = false;
            if(input != null && input != "")
            {
                valid = true;
            }
            return valid;
        }
    }
}