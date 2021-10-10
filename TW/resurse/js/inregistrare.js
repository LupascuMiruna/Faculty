
function verificareParola (parl) {
    for (let caracter of parl) {
        if(parseInt(caracter)) {
            return true
        }
    }
    return false;
}

function onSubmit () {
    const username = document.getElementById("username").value;
    const parl = document.getElementById("parl").value;
    const telefon = document.getElementById("telefon").value || null;

    if (parl != document.getElementById("rparl").value){
        alert("Nu ai reintrodus bine parola!");
        return false;
    }

    if(!verificareParola(parl)) {
        alert("Parola trebuie sa contina cel putin o cifra!");
        return false;
    }

    if (username === "" ) {
        alert("Nu ai introdus username!");
        return false;
    }
    if (!username.match("^[A-Za-z0-9]+$")) {
        alert("Nu ai introdus username corect!");
        return false;

    }
    if (username.length < 3){
        alert("Username-ul trebuie sa aiba minim 3 caractere!");
        return false;
    }
    if (document.getElementById("nume").value === ""){
        alert("Nu ai introdus nume!");
        return false;
    }
    if (document.getElementById("prenume").value === ""){
        alert("Nu ai introdus prenume!");
        return false;
    }

    if (document.getElementById("email").value === ""){
        alert("Nu ai introdus email!");
        return false;
    }
    if (telefon && !telefon.match(/^\+?0[0-9]{9}[0-9]*$/)){
        alert("Nu ai reintrodus bine numarul de telefon!");
        return false;
    }
    return true;
}

window.addEventListener("load", function () {
    document.getElementById("form_inreg").onsubmit = onSubmit;
});