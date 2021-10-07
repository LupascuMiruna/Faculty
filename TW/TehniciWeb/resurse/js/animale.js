
function getTempCondition(str, temperamente){
    if (!temperamente.length) {
        return true;
    }

    const realTemperament = str.trim().split(",");
    for (let temp of temperamente) {
        if (realTemperament.includes(temp)) {
            return true;
        }
    }
    return false;
}
//PANA LA 1:22
///VA TREBUI ADD EVENT LISTENER CAND VA MERGE DARK THEME
window.onload=function(){

    var rng=document.getElementById("inp-pret");
	rng.parentNode.insertBefore(document.createTextNode(rng.min),rng);
	rng.parentNode.appendChild(document.createTextNode(rng.max));
    let spval=document.createElement("span");
	rng.parentNode.appendChild(spval)
    rng.value=0;
    spval.innerHTML=" ("+rng.value+")";
    rng.onchange= function() {
        rng.nextSibling.nextSibling.innerHTML=" ("+this.value+")";
    }

    let btn = document.getElementById("filtrare");
    btn.onclick=function(){
        let dresat_select=document.querySelector('input[name=dresat]:checked').value;
        
        inp=document.getElementById("inp-pret");
        let minPret=parseFloat(inp.value)

        let sel=document.getElementById("inp-tip");
        let tipSel=sel.value

        const culoare_select = document.getElementById("inp-culoare").value.trim();
        
        let talii_select = Array.from(document.getElementsByClassName('inp-talie'));
        let talii = talii_select.filter((talie) => talie.checked).map((talie) => talie.value);

        const descriere_select = document.getElementById("inp-descriere").value.trim();
        
        const temperament_select = Array.from(document.getElementById("inp-temperament").selectedOptions);
        const temperamente = temperament_select.map(temp => temp.value);

        var produse=document.getElementsByClassName("animal");
    
        for (let prod of produse){
            prod.style.display = "none";

            let talie = prod.getElementsByClassName("val-talie")[0].innerHTML
            let conditie1 = (talii.includes(talie) || talii.includes("toate"));
            // console.log("_"+talie+"_")
            
            let pret= parseFloat(prod.getElementsByClassName("val-pret")[0].innerHTML)
            let conditie2= pret>=minPret

            let tipArt= prod.getElementsByClassName("val-tip")[0].innerHTML
            let conditie3= (tipArt==tipSel ||tipSel=="toate");

            let dresat = prod.getElementsByClassName("val-dresat")[0].innerHTML;
            let conditie4= (dresat == dresat_select ||dresat_select =="toate");

            let descriere = prod.getElementsByClassName("val-descriere")[0].innerHTML;
            let conditie5 = (descriere_select == descriere || descriere_select == "");

            let temperament = prod.getElementsByClassName("val-temperament")[0].innerHTML;
            let conditie6 = getTempCondition(temperament, temperamente);

            let culoare = prod.getElementsByClassName("val-culoare")[0].innerHTML;
            let conditie7 = (culoare_select == culoare || culoare_select == "");

            let conditieFinala=conditie2 && conditie3 && conditie1 && conditie4 && conditie5 && conditie6 && conditie7;
            if (conditieFinala)
                prod.style.display = "grid";
        }
    }


    function sortArticole(factor){
        
        var produse=document.getElementsByClassName("animal");
        let arrayProduse=Array.from(produse);
        arrayProduse.sort(function(art1,art2){
            let pret1=art1.getElementsByClassName("val-pret")[0].innerHTML;
            let pret2=art2.getElementsByClassName("val-pret")[0].innerHTML;

            let tip1=art1.getElementsByClassName("val-tip")[0].innerHTML;
            let tip2=art2.getElementsByClassName("val-tip")[0].innerHTML;

           
            let rez=factor*(pret1-pret2)
            if (rez==0)
                return factor*tip1.localeCompare(tip2)   
            return rez;
            
            /*
           
            let rez=factor*nume1.localeCompare(nume2)
            if (rez==0)
                retrun factor*(pret1-pret2)
            return rez;
            */
        });
        console.log(arrayProduse); 
        for (let prod of arrayProduse){
            prod.parentNode.appendChild(prod);
        }
    }

    btn=document.getElementById("sortCrescPret");
    btn.onclick=function(){
        sortArticole(1);
    }
    btn=document.getElementById("sortDescrescPret");
    btn.onclick=function(){
        sortArticole(-1);
    }

    btn=document.getElementById("resetare");
    btn.onclick=function(){
        
        var produse=document.getElementsByClassName("animal");
    
        for (let prod of produse){
            prod.style.display="block";
        }
    }



    window.onkeydown=function(e){
        
       
        if (e.key=="c" && e.altKey){
            e.preventDefault();
            var produse=document.getElementsByClassName("animal");
            sumaArt=0;
            for (let prod of produse){
                sumaArt+=parseInt(prod.getElementsByClassName("val-pret")[0].innerHTML);
            }
            let infoSuma=document.createElement("p");//<p></p>
            infoSuma.innerHTML="Suma: "+sumaArt;//<p>...</p>
            infoSuma.className="info-produse";
            let p=document.getElementById("p-suma")
            p.parentNode.insertBefore(infoSuma,p.nextSibling);
            setTimeout(function(){infoSuma.remove()}, 2000);
        }
    }

    btn = document.getElementById("calcSuma");
    btn.onclick=function(){
            
            var produse=document.getElementsByClassName("animal");
            sumaArt=0;
            for (let prod of produse){
                sumaArt+=parseInt(prod.getElementsByClassName("val-pret")[0].innerHTML);
            }
            let infoSuma=document.createElement("p");//<p></p>
            infoSuma.innerHTML="Suma: "+sumaArt;//<p>...</p>
            infoSuma.className="info-produse";
            let p=document.getElementById("calcSuma")
            p.parentNode.insertBefore(infoSuma,p.nextSibling);
            setTimeout(function(){infoSuma.remove()}, 2000);
        }
   


}