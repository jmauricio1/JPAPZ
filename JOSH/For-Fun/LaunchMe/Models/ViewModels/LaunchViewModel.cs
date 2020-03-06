using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using LaunchMe.Models;

namespace LaunchMe.Models.ViewModels
{
    public class LaunchViewModel
    {
        public LaunchViewModel(Launch launch)
        {
            missionName = launch.missionName;
            launchSuccess = launch.launchSuccess;
            flightNum = launch.flightNum;
            launchTime = launch.launchTime;
            launchYear = launch.launchYear;

            rocketName = launch.rocketName;
            rocketType = launch.rocketType;
            rocketID = launch.rocketID;
            launchDetails = launch.launchDetails;
        }

        public string missionName { get; set; }
        public string launchSuccess { get; set; }
        public int flightNum { get; set; }
        public string launchTime { get; set; }
        public int launchYear { get; set; }
        public string rocketName { get; set; }
        public string rocketType { get; set; }
        public string rocketID {get; set;}
        public string launchDetails { get; set; }
    }
}