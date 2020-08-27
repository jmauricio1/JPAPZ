$(document).ready(function () {
    $.ajax({
        type: "GET",
        dataType: "json",
        url: "/API/GetPlayerStats",
        success: displayPlayerStats
    });
});

function displayPlayerStats(data) {
    console.log(data);
}