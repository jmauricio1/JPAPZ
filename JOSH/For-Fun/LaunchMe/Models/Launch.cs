using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace LaunchMe.Models
{
    public class Launch
    {
        //Launch Information
        public string missionName;
        public string launchSuccess;
        public int flightNum;
        public string launchTime;
        public int launchYear;

        //Rocket Information
        public string rocketName;
        public string rocketType;
        public string rocketID;
        public string launchDetails;
    }
}