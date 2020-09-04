using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace fortnite_project.Models
{
    public class ProfileModels
    {
        public ProfileModels()
        {
            username = "";
            epicname = "";
            elims = 0;
            matches = 0;
            kdr = 0;
        }

        public string username { get; set; }
        public string epicname { get; set; }
        public int elims { get; set; }
        public int matches { get; set; }
        public double kdr { get; set; }

    }
}