$(document).ready(function () {
    $("#but").click(function () {
        console.log("Hello World! The button was clicked!");

        let x = $("#city-list").val();

        $.ajax({
            type: "GET",
            dataType: "json",
            url: "/Home/GetWeather",
            data: {wid: x},
            success: displayData,
            error: viewError
        });
    });
});

function displayData(data) {
    $("#weathers").empty(); //Empty whatever is curently in that section

    let name = document.createElement("h1");
    name.append(data.cityName)
    name.className = "text-center"; //

    $("#weathers").append(name);

    for (var i = 0; i < data.list.length; i++) {

        let date = document.createElement("h3");
        date.append(data["list"][i]["date"]);
        date.className = "text-center";

        let weather = document.createElement("p");
        weather.append(data["list"][i]["weatherStateName"]);
        weather.className = "text-center";

        let brick = document.createElement("br");

        $("#weathers").append(date); //<h3 class="text-center">[Whatever the date is]</h3>
        $("#weathers").append(weather);
        $("#weathers").append(brick);
    }
}

function viewError() {
    console.log("Error on AJAX");
}