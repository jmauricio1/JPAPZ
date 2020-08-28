$(document).ready(function () {
    $("#player-search-button").click(function () {

        let name = $("#epic-username-input").val();

        $.ajax({
            type: "GET",
            dataType: "json",
            url: "/API/GetPlayerStats",
            data: {username: name},
            success: displayPlayerStats
        });
    });
});

function displayPlayerStats(data) {
    console.log(data);

    $("#player-stats").empty();

    let username = document.createElement("h2");
    username.append(data["username"]);

    let row = document.createElement("div");
    row.className = "row";

    let col1 = document.createElement("div");
    col1.className = "col-lg-4";

    let elims = document.createElement("p");
    elims.append("Eliminations: ");

    let elimNumber = document.createElement("span");
    elimNumber.append(data["elims"]);
    elimNumber.id = "elim-number";
    elimNumber.className = "stat-number";
    elims.append(elimNumber);
    col1.append(elims);
    row.append(col1);

    let col2 = document.createElement("div");
    col2.className = "col-lg-4";

    let matches = document.createElement("p");
    matches.append("Matches: ");

    let matchesNumber = document.createElement("span");
    matchesNumber.append(data["matches"]);
    matchesNumber.id = "matches-number";
    matchesNumber.className = "stat-number";
    matches.append(matchesNumber);
    col2.append(matches);
    row.append(col2);

    let col3 = document.createElement("div");
    col3.className = "col-lg-4";

    let kd = document.createElement("p");
    kd.append("K/D: ");

    let kdNumber = document.createElement("span");
    kdNumber.append(data["kd"]);
    kdNumber.id = "kd-number";
    kdNumber.className = "stat-number";
    kd.append(kdNumber);
    col3.append(kd);
    row.append(col3);

    $("#player-stats").append(username);
    $("#player-stats").append(row);
}