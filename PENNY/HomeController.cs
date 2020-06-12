using HW6.DAL;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;


namespace HW6.Controllers
{
    public class HomeController : Controller
    {
        private WWIContext db = new WWIContext();
       
        // I intially put my return viewn in the StockItemsController which is the wrong controller.
        //This return will not do anything in stockitem controller because this is the initial page (When we first visit the site)
        //return View(db.StockItems.Where(s => s.StockItemName.Contains(name)).ToList());

        /*
         * PROBLEM: When typing something in the search and clicking the search button, the list does not display
         * SOLUTION:
         * We need ActionResult For an HttpPost (Make name of this action result the same as the one above)
         * In this ActionResult, it needs a paramter that will take in the thing we're searching for
         * Then we create a LINQ query that grabs the items with that name
         * For reference, go to HW4 to learn how to take something in for a post request
         * In order to diplay the list, go to HW5 to see how to get names out of DB with a for loop
         * To make each result into a link, within the same for loop to display item from DB, use with an HTML.ActionLink
         */
        [HttpPost] // for the search, we will use a Post Request here 
         public ActionResult Index(string search)//In this ActionResult, it needs a paramter that will take in the thing we're searching for
        {
            var items = db.StockItems.Where(n => n.StockItemName.Contains(search));// using contains to find the itemname
            ViewBag.Success = true;// matching in index page ViewBag.Succeess
            return View(items.ToList());// Return a list
        }
        
    }
}





