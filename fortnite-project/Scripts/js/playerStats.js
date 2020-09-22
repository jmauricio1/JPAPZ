$(document).ready(function () {
    GetPlayerStats();
    DisplayStatGraph();
});

function GetPlayerStats() {

}

function DisplayStatGraph() {
    $('#stat-graph').empty();

    var trace1 = {
        x: ['solos', 'duos', 'squads'],
        y: [200, 100, 250],
        type: 'bar',
        name: 'matches',
        marker: {
            size: 10,
            color: '#F6E8EA'
        }
    };

    var trace2 = {
        x: ['solos', 'duos', 'squads'],
        y: [143, 123, 331],
        type: 'bar',
        name: 'eliminations',
        marker: {
            size: 10,
            color: '#84DCCF'
        }
    };

    var trace3 = {
        x: ['solos', 'duos', 'squads'],
        y: [10, 20, 30],
        type: 'bar',
        name: 'wins',
        marker: {
            size: 10,
            color: '#52f25d'
        }
    };

    var layout = {
        barmode: 'stack',
        bg_color: '#000',
        paper_bgcolor: '#000',
        plot_bgcolor: '#000',
        xaxis: {
            title: {
                text: '',
                font: { size: 18 }
            },
        },
        yaxis: {
            visible: false
        }
    };

    let data = [trace1, trace2, trace3];

    Plotly.newPlot('stat-graph', data, layout);
    console.log("Plotted Graph");
}