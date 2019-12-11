$('#missionDesignation').on("change", function (e)
{
    var selectedItemValue = this.value;
    $('#membersList').empty();

    console.log(selectedItemValue);

    $.ajax({
        type: "GET",
        dataType: "json",
        url: "crew/mission?missionDesignation=" + selectedItemValue,
        success: displayMembers,
        error: errorOnAjax

    });
});

function errorOnAjax() {
    console.log("ERROR on ajax call")
}

$('#missionDesignation').ready(function () {
   // console.log("Hakuna");
});

function displayMembers(data) {

    var headerRow = document.createElement('tr');
    var headerName = document.createElement('th');
    var headerText = document.createTextNode("Members' Names and Nationalities:  ");
    headerName.appendChild(headerText);
    headerRow.appendChild(headerName);

    $('#membersList').append(headerRow);
    //$('#missionDesignation').append(headerRow);

    for (var i = 0; i < data.length; i++) {

        var memberRow = document.createElement('tr');
        var memberName = document.createElement('td');
        var memberNameText = document.createTextNode(data[i]["AName"]);
        memberName.appendChild(memberNameText);
        memberRow.append(memberName);

        var memberNat = document.createElement('td');
        var memberNatText = document.createTextNode(data[i]["ANat"]);
        memberNat.appendChild(memberNatText);
        memberRow.append(memberNat);

        var space = document.createElement('br');

        $('#membersList').append(memberRow);
        var thybreak = document.createElement('br');
        $('#membersList').append(thybreak);




    }

}