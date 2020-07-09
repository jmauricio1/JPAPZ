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

function displayData(data) {
    $("#weathers").empty();

    let name = document.createElement("h1");
    name.append(data.name)
    name.className = "text-center";

    $("#weathers").append(name);
    //console.log(data.weathers.length);

    for (var i = 0; i < data.weathers.length; i++) {
        console.log("Entering loop");
        let date = document.createElement("h3");
        date.append(data["weathers"][i]["date"]);
        date.className = "text-center";

        let weather = document.createElement("p");
        weather.append(data["weathers"][i]["weatherStateName"]);
        weather.className = "text-center";

        let min = document.createElement("p");
        min.append(data["weathers"][i]["minTemp"]);
        min.className = "text-center";

        let max = document.createElement("p");
        max.append(data["weathers"][i]["maxTemp"]);
        max.className = "text-center";

        let brick = document.createElement("br");

        $("#weathers").append(date);
        $("#weathers").append(weather);
        $("#weathers").append(min);
        $("#weathers").append(max);
        $("#weathers").append(brick);
        $("#weathers").append(brick);
    }
}

function errorOnAjax() {
    console.log("Error on AJAX request");
}