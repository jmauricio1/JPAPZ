namespace fortnite_project.DAL
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    public partial class Group
    {
        public int ID { get; set; }

        [StringLength(128)]
        public string Postee { get; set; }

        public DateTime? PostDate { get; set; }

        [Required]
        [StringLength(64)]
        public string Title { get; set; }

        [StringLength(128)]
        public string Desc { get; set; }

        [Required]
        [StringLength(16)]
        public string PlatPref { get; set; }

        [Required]
        [StringLength(16)]
        public string SkillPref { get; set; }

        public virtual AspNetUser AspNetUser { get; set; }
    }
}
