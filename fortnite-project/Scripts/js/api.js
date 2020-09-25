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

    if (data == "No data to display") {
        $("#player-stats").empty();
        $("#does-not-exist").append("Please enter a valid Epic username.");
    }
    else {
        $("#player-stats").empty();
        $("#does-not-exist").empty();

        let username = document.createElement("h1");
        username.append(data["username"]);

        let row = document.createElement("div");
        row.className = "row";

        let col0 = document.createElement('div');
        col0.className = "col-lg-3 win-color";

        let wins = document.createElement('h2');
        wins.append(data["wins"]);
        col0.append(wins);

        let temp = document.createElement('h3');
        temp.append("Wins");
        col0.append(temp);
        row.append(col0);

        let col1 = document.createElement('div');
        col1.className = "col-lg-3 elim-color middle-col mid-col-left";

        let elimNumber = document.createElement('h2');
        elimNumber.append(data["elims"]);
        elimNumber.id = "elim-number";
        elimNumber.className = "stat-number";
        col1.append(elimNumber);

        let elims = document.createElement('h3');
        elims.append("Eliminations");
        col1.append(elims);
        row.append(col1);

        let col2 = document.createElement("div");
        col2.className = "col-lg-3 matches-color middle-col mid-col-right";

        let matchesNumber = document.createElement("h2");
        matchesNumber.append(data["matches"]);
        matchesNumber.id = "matches-number";
        matchesNumber.className = "stat-number";

        let matches = document.createElement("h3");
        matches.append("Matches");

        col2.append(matchesNumber);
        col2.append(matches)
        row.append(col2);

        let col3 = document.createElement("div");
        col3.className = "col-lg-3 kdr-color";

        let kdNumber = document.createElement("h2");
        kdNumber.append(data["kd"]);
        kdNumber.id = "kd-number";
        kdNumber.className = "stat-number";

        let kd = document.createElement("h3");
        kd.append("K/D");

        col3.append(kdNumber);
        col3.append(kd);
        row.append(col3);

        $("#player-stats").append(username);
        $("#player-stats").append(row);
    }
}