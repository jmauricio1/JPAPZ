$(document).ready(function () {
    $('#more-stats').hide();

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

    TestChart();
});

function displayPlayerStats(data) {
    console.log(data);

    if (data == "No data to display") {
        $("#player-stats").empty();
        $("#does-not-exist").append("Please enter a valid Epic username.");
        $('#more-stats').hide();
    }
    else {
        $("#player-stats").empty();
        $("#does-not-exist").empty();
        $('#more-stats').show();

        $("#solo-wins-count").empty();
        $("#solo-elim-count").empty();
        $("#solo-matches-count").empty();
        $("#solo-kd").empty();
        $("#duo-wins-count").empty();
        $("#duo-elim-count").empty();
        $("#duo-matches-count").empty();
        $("#duo-kd").empty();
        $("#squad-wins-count").empty();
        $("#squad-elim-count").empty();
        $("#squad-matches-count").empty();
        $("#squad-kd").empty();

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

        $("#solo-wins-count").append(data["soloWins"]);
        $("#solo-elim-count").append(data["soloElims"]);
        $("#solo-matches-count").append(data["soloMatches"]);

        let lump = (data["soloElims"] / data["soloMatches"]).toFixed(2);
        $("#solo-kd").append(lump);

        $("#duo-wins-count").append(data["duoWins"]);
        $("#duo-elim-count").append(data["duoElims"]);
        $("#duo-matches-count").append(data["duoMatches"]);

        lump = (data["duoElims"] / data["duoMatches"]).toFixed(2);
        $("#duo-kd").append(lump);

        $("#squad-wins-count").append(data["squadWins"]);
        $("#squad-elim-count").append(data["squadElims"]);
        $("#squad-matches-count").append(data["squadsMatches"]);

        lump = (data["squadElims"] / data["squadsMatches"]).toFixed(2);
        $("#squad-kd").append(lump);
    }
}

function TestChart() {
    var Chart = require('chart.js');

    var ctx = document.getElementById('myChart');
    var myChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: ['Red', 'Blue', 'Yellow', 'Green', 'Purple', 'Orange'],
            datasets: [{
                label: '# of Votes',
                data: [12, 19, 3, 5, 2, 3],
                backgroundColor: [
                    'rgba(255, 99, 132, 0.2)',
                    'rgba(54, 162, 235, 0.2)',
                    'rgba(255, 206, 86, 0.2)',
                    'rgba(75, 192, 192, 0.2)',
                    'rgba(153, 102, 255, 0.2)',
                    'rgba(255, 159, 64, 0.2)'
                ],
                borderColor: [
                    'rgba(255, 99, 132, 1)',
                    'rgba(54, 162, 235, 1)',
                    'rgba(255, 206, 86, 1)',
                    'rgba(75, 192, 192, 1)',
                    'rgba(153, 102, 255, 1)',
                    'rgba(255, 159, 64, 1)'
                ],
                borderWidth: 1
            }]
        },
        options: {
            scales: {
                yAxes: [{
                    ticks: {
                        beginAtZero: true
                    }
                }]
            }
        }
    });
}