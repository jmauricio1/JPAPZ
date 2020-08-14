namespace practice_proj.DAL
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    public partial class Sample
    {
        public int ID { get; set; }

        [Required]
        [StringLength(128)]
        public string Word { get; set; }
    }
}
