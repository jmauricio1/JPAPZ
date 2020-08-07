$(document).ready(function () {
    $("#weather-submit").click(function () {
        let theCity = $("#city-list").val();

        console.log("City Chosen: " + theCity);

        $.ajax({
            type: "GET",
            dataType: "json",
            url: "/Home/GetWeather",
            data: { city: theCity },
            success: displayData,
            error: errorOnAjax
        });
    });
});

function errorOnAjax() {
    console.log("Error on AJAX request");
}

function displayData(data) {
    $("#weathers").empty();

    let name = document.createElement("h1");
    name.append(data.name)
    name.className = "text-center";

    $("#weathers").append(name);
    //console.log(data.weathers.length);

    for (var i = 0; i < data.weathers.length; i++) {
        console.log("Entering loop");
        let brick = document.createElement("br");

        $("#weathers").append(createModule(data["weathers"][i]));
        $("#weathers").append(brick);
        $("#weathers").append(brick);

        //data["weathers"][i]
    }
}

function createModule(object) {
    var thing = document.createElement("div");
    this.className = "text-center";

    let date = document.createElement("h3");
    date.append(object["date"]);

    let weather = document.createElement("p");
    weather.append(object["weatherStateName"]);

    let min = document.createElement("p");
    min.append(object["minTemp"]);

    let max = document.createElement("p");
    max.append(object["maxTemp"]);

    thing.append(date);
    thing.append(weather);
    thing.append(min);
    thing.append(max);

    //console.log("Module Created!")

    return thing;
}