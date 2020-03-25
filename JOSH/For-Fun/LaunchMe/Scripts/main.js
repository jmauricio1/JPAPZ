$(document).ready(function () {
    $.ajax({
        type: "GET",
        dataType: "json",
        url: "/api/launchlist",
        success: displayList,
        error: errorOnAjax
    });
});



function displayList(data) {
    console.log(data);
    for (var i = 0; i < data.length; i++) {
        var row = document.createElement('div');
        row.className = "row";

        var section = document.createElement('div');
        section.id = "launch-section";
        section.className = "col-lg-4 col-md-6 col-sm-6 col-xs-12";

        var missname = document.createElement('h2');
        var link = document.createElement('a');
        var missText = document.createTextNode( data[i]["missionName"]);
        //missname.append('@Html.ActionLink("' + data[i]["missionName"] + '", "Details", "LaunchList", new { id = ' + data[i]["flightNum"] + '})');
        var newLink = '/LaunchList/Details?id=' + data[i]["flightNum"];
        link.href = newLink;
        link.append(missText);
        link.className = "launch-detail-link";
        missname.append(link);

        missname.className = "section-name";

        var success = document.createElement('h4');
        if (data[i]["launchSuccess"] == "True") {
            success.append("Successful");
            success.className = "success-text";
        }
        else if (data[i]["launchSuccess"] == null) {
            success.append("Not Yet Launched");
            success.className = "null-text";
        }
        else {
            success.append("Unsuccessful");
            success.className = "fail-text";
        }

        var missyear = document.createElement('p');
        var yearText = document.createTextNode(data[i]["launchYear"]);
        missyear.append(yearText);

        var fnum = document.createElement('p');
        var launchText = document.createTextNode(data[i]["flightNum"]);
        //fnum.append("Launch Number: " + data[i]["flight_number"]);fnum.appendChild(launchText);
        fnum.appendChild(launchText);

        section.appendChild(missname);
        section.appendChild(success);
        section.appendChild(missyear);
        section.appendChild(fnum);

        var otherDiv = document.createElement('div');
        otherDiv.appendChild(section);
        /*row.append(missname);
        row.append(fnum);*/
        $('#launch-list').append(otherDiv);
    }
}

function displayLaunches2(data) {
    console.log(data);
    for (var i = 0; i < data.length; i++) {
        var current = document.createElement('p');
        var currentNum = document.createTextNode("Launch Numbers: " + data[i]["flightNum"]);
        current.appendChild(currentNum);
        current.className = "tag";

        $('#launch-list').append(current);
    }
}

function displayLaunches(data) {
    console.log(data);
    for (var i = 0; i < data.length; i++) {
        var row = document.createElement('div');
        row.className = "row";

        var section = document.createElement('div');
        section.id = "launch-section";
        section.className = "col-lg-4 col-md-6 col-sm-6 col-xs-12";

        var missname = document.createElement('h2');
        var missText = document.createTextNode(data[i]["missionName"]);
        missname.append(missText);
        missname.className = "section-name";

        var success = document.createElement('h4');
        if (data[i]["launchSuccess"].toString() == "True") {
            success.append("Successful");
            success.className = "success-text";
        }
        else {
            success.append("Unsuccessful");
            success.className = "fail-text";
        }

        var fnum = document.createElement('p');
        var launchText = document.createTextNode("Launch Number: " + data[i]["flightNum"]);
        //fnum.append("Launch Number: " + data[i]["flight_number"]);fnum.appendChild(launchText);
        fnum.appendChild(launchText);

        var time = document.createElement('p');
        time.append(data[i]["launchTime"]);

        var missyear = document.createElement('p');
        var yearText = document.createTextNode("Year: " + data[i]["launchYear"]);
        missyear.append(yearText);

        var rocketInfoHeader = document.createElement('h3');
        var headerInfo = document.createTextNode("Rocket Information");
        rocketInfoHeader.className = "rocket-info-header";
        rocketInfoHeader.append(headerInfo);

        var rockname = document.createElement('p');
        rockname.append("Rocket Name: " + data[i]["rocketName"]);

        var details = document.createElement('p');
        details.className = "rocket-details-section";
        details.append(data[i]["launchDetails"]);

        section.appendChild(missname);
        section.appendChild(success);
        section.appendChild(fnum);
        section.appendChild(time);
        section.appendChild(missyear);
        section.appendChild(rocketInfoHeader);
        section.appendChild(rockname);
        section.appendChild(details);

        var otherDiv = document.createElement('div');
        otherDiv.appendChild(section);
        /*row.append(missname);
        row.append(fnum);*/
        $('#launch-list').append(otherDiv);
    }
}

function errorOnAjax() {
    console.log("ERROR on ajax request");
}