namespace Final1.Models
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    public partial class VideoTag
    {
        public int ID { get; set; }

        public int VideoID { get; set; }

        public int TagID { get; set; }

        public virtual Tag Tag { get; set; }

        public virtual Video Video { get; set; }
    }
}
