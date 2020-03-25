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

        //first stage(cores)
        public string coreSerial;

        //Second Stage (payloads)
        public string payloadID;
        public string reused;
        //Customers
        public string customers;
        public string nationality;
        public string manufacturer;
        public string payloadMassKG;
        public string payloadMassLB;

        //Orbit
        public string orbit;
        public string referenceSystem;
        public string regime;
        public string longitude;
        public string epoch;
        public double meanMotion;
        public double raan;
        public double emiMajorAkisKM;
        public double eccentricity;
        public double periapsisKM;
        public double apoapsisKM;
        public double inclinationDeg;
        public double periodMin;
        public double argPericenter;
        public double meanAnom;

        //Launch Details
        public string siteName; //site_name_long
        public string launchDetails;

        //References
        public string missionPatch;
        public string articleLink;
        public string videoLink;

    }

    public class OtherLaunch
    {
        public int flightNum;
        public string missName;
        public string missID; //List

        public int launchYear;
        public int launchDateUnix;
        public string launchDateUTC;
        public string launchDateLocal;
        public string tent;
        public string tentMaxPrecise;
        //tbd
        //launch_window

        //ROCKET
        public string rocketID;
        public string rocketName;
        public string rocketType;

        //FIRST STAGE
        //Cores
        public string coreSerial;
        public int flight;
        public int block;
        public bool gridfins;
        public bool legs;
        public bool reused;
        public bool landSuccess;
        public bool landIntent;
        public string landType;
        public string landVeh;

        //SECOND STAGE
        public int block2;
        //Payloads List
        public string payloadID;
        public int noradID; //List
        public string capSerial;
        public string customers; //List
        public string nationality;
        public string manufac;
        public string payloadType;
        public double plmkg;
        public double plmlb;
        public string orbit;
        //Orbit Params
        public string refSys;
        public string regime;
        //longitude
        public double semiMajorAxisKM;
        public double eccentricity;
        public double periKm;
        public double apoKm;
        public double inclinDeg;
        public double periodMin;
        //lifespan
        public string epoch;
        public double meanMotion;
        public double raan;
        public double argPericenter;
        public double meanAnomoly;
        //mass returned
        //mass returned lb
        public int flightTime; //Seconds
        public string uid; //IDK if i should add this

        public string ships; //list
        public string telemetry; //Link to flightclub

        //LAUNCH SITE
        public string siteID;
        public string locName;
        public string locLong;

        public bool launchSuccess;

        //Links
        public string patch;
        public string patchSmall;
        public string redditCampaign;
        public string redditLaunch;
        public string redditRecovery;
        public string redditMedia;
        public string presskit;
        public string articleLink;
        public string wikipedia;
        public string videoLink;
        public string ytID;

        public List<string> images;
        public string details;
        public bool upcoming;
        public string statFireDateUTC;
        public string statFireDaeUnix;

        //TIMELINE
        public int webcastLiftoff;
        public int goForPropLoading;
        public int rp1Load;
        public int s1LoxLoad;
        public int s2LoxLoad;
        public int engineChill;
        public int prelaunchCheck;
        public int propellantPressurization;
        public int goForLaunch;
        public int ignition;
        public int liftoff;
        public int maxq;
        public int meco;
        public int stageSep;
        public int secStageIgnition;
        public int firstStageEntryBurn;
        public int seco1;
        public int firstStageLandingBurn;
        public int firstStageLanding;
        public int dragonSeparation;

        public string crew;
    }
}