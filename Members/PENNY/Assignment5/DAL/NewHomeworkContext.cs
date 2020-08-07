using Assignment5.Models;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;

namespace Assignment5.DAL
{

    // Class that gives us access to a DB
    public class NewHomeworkContext : DbContext
    {
        // Which database to connect to (details in web.config)
        public NewHomeworkContext() : base("name=AssignmentDB")
        {
            Database.SetInitializer<NewHomeworkContext>(null);
        }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);
            modelBuilder.Entity<Homework>().ToTable("newHomeworks");
        }

        // Access to our Users table
        public virtual DbSet<Homework> Homeworks { get; set; }
    }

}