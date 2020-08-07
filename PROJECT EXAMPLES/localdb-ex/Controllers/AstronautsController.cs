using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Diagnostics;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using localdb_ex.DAL;
using localdb_ex.Models;

namespace localdb_ex.Controllers
{
    public class AstronautsController : Controller
    {
        private DatabaseContext db = new DatabaseContext(); //Mocking our database --> Variable that gives us access to the database

        public ActionResult Testing()
        {
            var names = db.Astronauts.Where(s => s.Name.Contains("a")).Select(s => s.Name).ToList(); //Creates the list of names of astronauts that contain the letter "a"
            var positions = db.Crews.Where(s => s.Mission.Desig == "Expedition 53").Select(s => s.Position).ToList(); //Selecting position of astronauts that are in the "Expedition 53" mission
            var astronames = db.Crews.Where(s => s.Mission.ID == 1).Select(s => s.Astronaut.Name).ToList();
            
            Debug.WriteLine("\nNAMES WITH A:\n");
            for(int i = 0; i < names.Count(); i++)
            {
                Debug.WriteLine(names[i]);
            }

            Debug.WriteLine("\nPositions:\n");
            for (int i = 0; i < positions.Count(); i++)
            {
                Debug.WriteLine(positions[i]);
            }

            Debug.WriteLine("\nAstronaut Names in in MID 1:\n");
            for (int i = 0; i < astronames.Count(); i++)
            {
                Debug.WriteLine(astronames[i]);
            }

            return View();
        }

        public ActionResult AstroProf()
        {
            AstronautProfile currentProfile = new AstronautProfile(); //View Model

            currentProfile.AstronautName = db.Astronauts.Where(s => s.ID == 1).Select(s => s.Name).FirstOrDefault();
            currentProfile.AstronautCountry = db.Astronauts.Where(s => s.ID == 1).Select(s => s.Country.Name).FirstOrDefault();

            Debug.WriteLine(currentProfile.AstronautName + "\n" + currentProfile.AstronautCountry);

            return View(currentProfile);
        }

        // GET: Astronauts
        public ActionResult Index()
        {
            var astronauts = db.Astronauts.Include(a => a.Country);
            return View(astronauts.ToList());
        }

        // GET: Astronauts/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Astronaut astronaut = db.Astronauts.Find(id);
            if (astronaut == null)
            {
                return HttpNotFound();
            }
            return View(astronaut);
        }

        // GET: Astronauts/Create
        public ActionResult Create()
        {
            ViewBag.NID = new SelectList(db.Countries, "ID", "Name");
            return View();
        }

        // POST: Astronauts/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "ID,Name,BDate,NID")] Astronaut astronaut)
        {
            if (ModelState.IsValid)
            {
                db.Astronauts.Add(astronaut);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            ViewBag.NID = new SelectList(db.Countries, "ID", "Name", astronaut.NID);
            return View(astronaut);
        }

        // GET: Astronauts/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Astronaut astronaut = db.Astronauts.Find(id);
            if (astronaut == null)
            {
                return HttpNotFound();
            }
            ViewBag.NID = new SelectList(db.Countries, "ID", "Name", astronaut.NID);
            return View(astronaut);
        }

        // POST: Astronauts/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "ID,Name,BDate,NID")] Astronaut astronaut)
        {
            if (ModelState.IsValid)
            {
                db.Entry(astronaut).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            ViewBag.NID = new SelectList(db.Countries, "ID", "Name", astronaut.NID);
            return View(astronaut);
        }

        // GET: Astronauts/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Astronaut astronaut = db.Astronauts.Find(id);
            if (astronaut == null)
            {
                return HttpNotFound();
            }
            return View(astronaut);
        }

        // POST: Astronauts/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Astronaut astronaut = db.Astronauts.Find(id);
            db.Astronauts.Remove(astronaut);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
