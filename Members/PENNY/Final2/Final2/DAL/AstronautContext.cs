namespace Final2.DAL
{
    using System;
    using System.Data.Entity;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;
    using Final2.Models;

    public partial class AstronautContext : DbContext
    {
        public AstronautContext()
            : base("name=AstronautContext")
        {
        }

        public virtual DbSet<Astronaut> Astronauts { get; set; }
        public virtual DbSet<Country> Countries { get; set; }
        public virtual DbSet<Crew> Crews { get; set; }
        public virtual DbSet<Mission> Missions { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Astronaut>()
                .HasMany(e => e.Crews)
                .WithRequired(e => e.Astronaut)
                .WillCascadeOnDelete(false);

            modelBuilder.Entity<Country>()
                .HasMany(e => e.Astronauts)
                .WithRequired(e => e.Country)
                .WillCascadeOnDelete(false);

            modelBuilder.Entity<Mission>()
                .HasMany(e => e.Crews)
                .WithRequired(e => e.Mission)
                .WillCascadeOnDelete(false);
        }
    }
}
