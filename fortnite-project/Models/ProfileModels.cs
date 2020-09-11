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
            wins = 0;
            elims = 0;
            matches = 0;
            kdr = 0;
            image = "";
        }

        public string username { get; set; }
        public string epicname { get; set; }
        public int wins { get; set; }
        public int elims { get; set; }
        public int matches { get; set; }
        public double kdr { get; set; }
        public string image { get; set; }
    }

    public class Solo
    {
        public Solo()
        {

        }

        public int matches { get; set; } //(int)data["stats"]["p2"]["matches"]["valueInt"]
        public int elims { get; set; } //(int)data["stats"]["p2"]["kills"]["valueInt"]
    }

    public class Duo
    {
        public Duo()
        {

        }
    }

    public class Squad
    {
        public Squad()
        {

        }
    }
}
