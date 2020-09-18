const data = [(1, 1), (2, 2), (10, 10), (20, 20), (30, 30), (40, 40)]

$(document).ready(function () {
    $('#stat-graph').empty();

    var trace1 = {
        x: ['solos', 'duos', 'squads'],
        y: [200, 100, 250],
        type: 'bar',
        name: 'matches',
        marker: { size: 10 }
    };

    var trace2 = {
        x: ['solos', 'duos', 'squads'],
        y: [143, 123, 331],
        type: 'bar',
        name: 'eliminations',
        marker: { size: 10 }
    };

    var trace3 = {
        x: ['solos', 'duos', 'squads'],
        y: [10, 20, 30],
        type: 'bar',
        name: 'wins',
        marker: { size: 10 }
    };

    var layout = {
        barmode: 'stack',
        title: {
            text: "Player Stats",
            font: { size: 24 },
        },
        xaxis: {
            title: {
                text: 'Game Mode',
                font: { size: 18 }
            },
        },
        yaxis: {
            title: {
                text: '',
                font: { size: 18 }
            }
        }
    };

    let data = [trace1, trace2, trace3];

    Plotly.newPlot('stat-graph', data, layout);
    console.log("Plotted Graph");
});