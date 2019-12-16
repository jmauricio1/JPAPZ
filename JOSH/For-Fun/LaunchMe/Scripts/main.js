$(document).ready(function () {
    $.ajax({
        type: "GET",
        dataType: "json",
        url: "api/launches",
        success: displayLaunches,
        error: errorOnAjax
    });
});

function displayLaunches(data) {
    console.log(data);
    for (var i = 0; i < data.length; i++) {
        console.log(data[i]["flight_number"]);
        var section = document.createElement('div');
        section.id = "launch-section";
        section.className = "col-lg-4";

        var fnum = document.createElement('p');
        var launchText = document.createTextNode("Launch Number: " + data[i]["flightNum"]);
        //fnum.append("Launch Number: " + data[i]["flight_number"]);fnum.appendChild(launchText);
        fnum.appendChild(launchText);

        var missname = document.createElement('p');
        var missText = document.createTextNode("Mission Name: " + data[i]["missionName"]);
        missname.append(missText);

        var missyear = document.createElement('p');
        var yearText = document.createTextNode("Year: " + data[i]["launchYear"]);
        missyear.append(yearText);

        var rockname = document.createElement('p');
        rockname.append("Rocket Name: " + data[i]["rocketName"]);


        section.appendChild(fnum);
        section.appendChild(missname);
        section.appendChild(missyear);
        section.appendChild(rockname);

        var otherDiv = document.createElement('div');
        otherDiv.appendChild(section);

        $('#launch-list').append(otherDiv);
    }
}

function errorOnAjax() {
    console.log("ERROR on ajax request");
}