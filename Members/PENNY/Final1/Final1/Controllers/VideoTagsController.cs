using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using Final1.DAL;
using Final1.Models;

namespace Final1.Controllers
{
    public class VideoTagsController : Controller
    {
        private VideoContext db = new VideoContext();

        // GET: VideoTags
        public ActionResult Index()
        {
            var videoTags = db.VideoTags.Include(v => v.Tag).Include(v => v.Video);
            return View(videoTags.ToList());
        }

        // GET: VideoTags/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            VideoTag videoTag = db.VideoTags.Find(id);
            if (videoTag == null)
            {
                return HttpNotFound();
            }
            return View(videoTag);
        }

        // GET: VideoTags/Create
        public ActionResult Create()
        {
            ViewBag.TagID = new SelectList(db.Tags, "ID", "TagName");
            ViewBag.VideoID = new SelectList(db.Videos, "ID", "Title");
            return View();
        }

        // POST: VideoTags/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "ID,VideoID,TagID")] VideoTag videoTag)
        {
            if (ModelState.IsValid)
            {
                db.VideoTags.Add(videoTag);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            ViewBag.TagID = new SelectList(db.Tags, "ID", "TagName", videoTag.TagID);
            ViewBag.VideoID = new SelectList(db.Videos, "ID", "Title", videoTag.VideoID);
            return View(videoTag);
        }

        // GET: VideoTags/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            VideoTag videoTag = db.VideoTags.Find(id);
            if (videoTag == null)
            {
                return HttpNotFound();
            }
            ViewBag.TagID = new SelectList(db.Tags, "ID", "TagName", videoTag.TagID);
            ViewBag.VideoID = new SelectList(db.Videos, "ID", "Title", videoTag.VideoID);
            return View(videoTag);
        }

        // POST: VideoTags/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "ID,VideoID,TagID")] VideoTag videoTag)
        {
            if (ModelState.IsValid)
            {
                db.Entry(videoTag).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            ViewBag.TagID = new SelectList(db.Tags, "ID", "TagName", videoTag.TagID);
            ViewBag.VideoID = new SelectList(db.Videos, "ID", "Title", videoTag.VideoID);
            return View(videoTag);
        }

        // GET: VideoTags/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            VideoTag videoTag = db.VideoTags.Find(id);
            if (videoTag == null)
            {
                return HttpNotFound();
            }
            return View(videoTag);
        }

        // POST: VideoTags/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            VideoTag videoTag = db.VideoTags.Find(id);
            db.VideoTags.Remove(videoTag);
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
