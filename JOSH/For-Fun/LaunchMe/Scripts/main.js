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
}

function errorOnAjax() {
    console.log("ERROR on ajax request");
}