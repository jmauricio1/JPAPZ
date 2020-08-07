using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using HW6.DAL;
using HW6.Models;
using HW6.Models.ViewModels;

namespace HW6.Controllers
{
    public class StockItemsController : Controller
    {
        

        // GET: StockItems
        private WWIContext db = new WWIContext();
        /*
         * IMPORTANT!
         * What is this ActionResult doing?
         * This is the same thing as the Index in HomeController
         */
        public ActionResult Index()
        {

            return View();
        }

        // GET: StockItems/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            StockItem stockItem = db.StockItems.Find(id);
            if (stockItem == null)
            {
                return HttpNotFound();
            }
            StockItemDetailsViewModel viewModel = new StockItemDetailsViewModel(stockItem);
            return View(viewModel);//passing the viewmodel here
        }

    }
}