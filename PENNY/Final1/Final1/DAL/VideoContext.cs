namespace Final1.DAL
{
    using System;
    using System.Data.Entity;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;
    using Final1.Models;


    public partial class VideoContext : DbContext
    {
        public VideoContext()
            : base("name=VideoContext")
        {
        }

        public virtual DbSet<Encoding> Encodings { get; set; }
        public virtual DbSet<Tag> Tags { get; set; }
        public virtual DbSet<Video> Videos { get; set; }
        public virtual DbSet<VideoTag> VideoTags { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Encoding>()
                .HasMany(e => e.Videos)
                .WithRequired(e => e.Encoding)
                .WillCascadeOnDelete(false);

            modelBuilder.Entity<Tag>()
                .HasMany(e => e.VideoTags)
                .WithRequired(e => e.Tag)
                .WillCascadeOnDelete(false);

            modelBuilder.Entity<Video>()
                .Property(e => e.MyDescription)
                .IsUnicode(false);

            modelBuilder.Entity<Video>()
                .HasMany(e => e.VideoTags)
                .WithRequired(e => e.Video)
                .WillCascadeOnDelete(false);
        }
    }
}
