$('#tagName').on("change", function (e) {

    var selectedItemValue = this.value;
    //console.log("text: " + selectedItemText + " value: " + selectedItemValue);
    $('#videosList').empty();

    console.log(selectedItemValue);

    $.ajax({
        type: "GET",
        dataType: "json",
        url: "videos/tag?tagName=" + selectedItemValue,
        success: displayVideos,
        error: errorOnAjax
    });
});

function errorOnAjax() {
       console.log("ERROR on ajax call")
}

$('#tagData').ready(function () {
    console.log("Hello");
});

function displayVideos(data) {
    //console.log(data);
    var headerRow = document.createElement('tr'); //tr stands for a table row// td means table data
    var headerName = document.createElement('th');//th stands for a table header
    var heaaderText = document.createTextNode("Videos with Current Tag: ");
    headerName.appendChild(heaaderText);
    headerRow.appendChild(headerName);

    $('#videosList').append(headerRow);

    for (var i = 0; i < data.length; i++) {

        var videoRow = document.createElement('tr');
        var videoName = document.createElement('td');
        var videoNameText = document.createTextNode(data[i]);
        videoName.appendChild(videoNameText);

        videoRow.append(videoName);

        $('#videosList').append(videoRow);
        var thybreak = document.createElement('br');// separate the data and make it look nice
        $('#videosList').append(thybreak);

    }

}