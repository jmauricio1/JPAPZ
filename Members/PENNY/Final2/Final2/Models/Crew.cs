namespace Final2.Models
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    public partial class Crew
    {
        public int ID { get; set; }

        [Required]
        [StringLength(50)]
        public string Position { get; set; }

        public int AstronautID { get; set; }

        public int MissionID { get; set; }

        public virtual Astronaut Astronaut { get; set; }

        public virtual Mission Mission { get; set; }
    }
}
