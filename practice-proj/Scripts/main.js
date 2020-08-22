$(document).ready(function () {

    $.ajax({
        type: "GET",
        dataType: "json",
        url: "/Characters/GetCharacters",
        success: displayCharacterList
    });
});

$(document).ready(function () {

    $("#button").click(function () {
        console.log("The button was clicked!");

        let x = $("#character-info").val();
        console.log(x);

        $.ajax({
            type: "GET",
            dataType: "json",
            url: "/Characters/SpecificCharacters",
            data: { id: x },
            success: displaySpecificCharacter
        });
    });
});

function displayCharacterList(data) {
    //console.log(data);

    $("#character-list").empty()
    for (let i = 0; i < data.length; i++) {
        let temp = document.createElement('a');
        temp.append(data[i]["name"]);
        temp.val = i + 1;             //id for specific characters

        $("#character-list").append(temp);
    }

}

function displaySpecificCharacter(data) {
    //console.log(data);

    $("#specific-character").empty()

    let name = document.createElement("h2");
    name.append(data.name);
    name.className = "text-center";

    $("#specific-character").append(name);

    let height = document.createElement('p');
    height.append(data["height"]);
    height.className = "text-center";

    let mass = document.createElement('p');
    mass.append(data["mass"]);
    mass.className = "text-center";

    let hair_color = document.createElement('p');
    hair_color.append(data["hair_color"]);
    hair_color.className = "text-center";

    let skin_color = document.createElement('p');
    skin_color.append(data["skin_color"]);
    skin_color.className = "text-center";

    let eye_color = document.createElement('p');
    eye_color.append(data["eye_color"]);
    eye_color.className = "text-center";

    let birth_year = document.createElement('p');
    birth_year.append(data["birth_year"]);
    birth_year.className = "text-center";

    let gender = document.createElement('p');
    gender.append(data["gender"]);
    gender.className = "text-center";

    $("#specific-character").append(height);
    $("#specific-character").append(mass);
    $("#specific-character").append(hair_color);
    $("#specific-character").append(skin_color);
    $("#specific-character").append(eye_color);
    $("#specific-character").append(birth_year);
    $("#specific-character").append(gender);

}