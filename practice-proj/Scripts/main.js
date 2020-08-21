$(document).ready(function () {

    $.ajax({
        type: "GET",
        dataType: "json",
        url: "/Characters/GetCharacters",
        success: displayCharacterList
    });
});

function displayCharacterList(data) {
    console.log(data);

    for (let i = 0; i < data.length; i++) {
        let temp = document.createElement('h3');
        temp.append(data[i]["name"]);
        //temp.append(data[i]["height"]);
       

        $("#character-list").append(temp);
    }

}