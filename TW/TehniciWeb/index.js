//cu require includem pachetele folosite in proiect
const express = require('express');
const fs = require('fs');
const path = require('path');
const sharp = require('sharp');
const {Client} =require('pg');
const url = require('url');
const { exec } = require("child_process");
const ejs=require('ejs');
const session = require('express-session');
const formidable = require('formidable');
const crypto = require('crypto');
const nodemailer = require("nodemailer");
const xmljs = require('xml-js');
const request = require('request');
const html_to_pdf = require('html-pdf-node');
const bodyParser = require('body-parser');

/*Puteti decomenta codul de mai jos pentru a crea un pdf chiar la pornirea programului
pe baza fisierului test.html
*/
// let options = { format: 'A4' };
// let file = { content: fs.readFileSync("./resurse/html/factura-exemplu.html").toString("utf-8") };
// html_to_pdf.generatePdf(file, options).then(function(pdf) {
//   var numefis="temp/test"+(new Date()).getTime()+".pdf";
//   fs.writeFileSync(numefis,pdf);
//   trimitefactura("Le prof", "profprofprof007@gmail.com", numefis);
// });


var app = express(); //am creat serverul
app.use(["/produse_cos","/cumpara"],express.json({limit:'2mb'}));//obligatoriu de setat pt request body de tip json
//trec mai jos paginile cu cereri post pe care vreau sa le tratez cu req.body si nu cu formidable
//app.use(["/contact"], express.urlencoded({extended:true}));---la mine nu

app.use(bodyParser.json())

//setez o sesiune
app.use(session({
    secret: 'abcdefg',//folosit de express session pentru criptarea id-ului de sesiune
    resave: true,
    saveUninitialized: false
}));
  
  //functii utile

function getUtiliz(req){
	var utiliz;
    
    if(req.session){
		utiliz = req.session.utilizator
	} else {
        utiliz = null
    }
	return utiliz;
}


async function trimiteMail(user_data, mesaj = null){
	var transp= nodemailer.createTransport({
		service: "gmail",
		secure: false,
		auth:{//date login 
			user:"tehniciweb2001@gmail.com",
			pass:"TehniciWeb2001!"
		},
		tls:{
			rejectUnauthorized:false
		}
    });
    const mesaj_default = "<h1>Salut!</h1><p>Username-ul tau este " + user_data.username + " pe site-ul <span style='font-weight:bold; font-style: italic; text-decoration: underline;'>PetMania</span></p>";
	//genereaza html
	await transp.sendMail({
		from: "tehniciweb2001@gmail.com",
		to: user_data.email,
		subject: `Salut, stimate ${user_data.nume}`,
		html: mesaj ? mesaj : mesaj_default,
	})
    console.log("trimis mail");
}

async function trimitefactura(username, email,numefis){
	var transp= nodemailer.createTransport({
		service: "gmail",
		secure: false,
		auth:{//date login 
			user:"tehniciweb2001@gmail.com",
			pass:"TehniciWeb2001!"
		},
		tls:{
			rejectUnauthorized:false
		}
	});
	//genereaza html
	await transp.sendMail({
		from:"tehniciweb2001@gmail.com",
		to:email,
		subject:"Factură",
		text:"Stimate "+username+", aveți atașată factura",
		html:"<h1>Salut!</h1><p>Stimate "+username+", aveți atașată factura</p>",
        attachments: [
            {   // utf-8 string as an attachment
                filename: 'factura.pdf',
                content: fs.readFileSync(numefis)
            }]
	})
	console.log("trimis mail");
}

var d = new Date();
var minute = d.getMinutes();
const imagini = verificaImagini();

//setam datele clentului PostgreSQL
//trebuie sa inlocuiti cu username-ul vostru si parola voastra pentru userul creat special pentru acest proiect
const client = new Client({
    host: 'localhost',
    user: 'test',
    password: 'postgres',
    database: 'db_test',
    port: 5432
})

client.connect()

async function getTipuri () {
    return client.query("select unnest(enum_range( null::tipuri)) as tip");
}

let tipuri = [];

// IIFE Immediately Invoked Function Expression deoarece avem nevoie de un context asincron pentru a "astepta" preluarea tippurilor inainte de a defini rutele
(async () => { 
    const tipuri_raw = await getTipuri();
    tipuri = tipuri_raw.rows || [];
})();

setInterval(function(){
    let comanda= `delete from logs where now() - data_accesare > interval '10 minutes'`;
    //console.log(comanda);
    client.query(comanda, function(err, rez) {
        if(err) console.log(err);
    });
},10*60*1000)


app.use(function(req, res, next) {
    let comanda_param= `insert into logs(ip, user_id, pagina) values ($1::text, $2,  $3::text)`;
    //console.log(comanda);
    if (req.ip){
        var id_utiliz=req.session.utilizator?req.session.utilizator.id:null;
        // console.log("id_utiliz", id_utiliz);
        client.query(comanda_param, [req.ip, id_utiliz, req.url], function(err, rez){
            if(err) console.log(err);
        });
    }
    next();
});

function verificaImagini(){ 
    var jsi = require("./resurse/galerie.json"); //citeste tot fisierul

	var caleGalerie = jsi.cale_galerie;
    let vectImagini=[]
	for (let im of jsi.imagini){
		var imVeche= path.join(caleGalerie, im.cale_imagine);//obtin claea completa (im.fisier are doar numele fisierului din folderul caleGalerie)
        //console.log(imVeche)
        
        var ext = path.extname(im.cale_imagine);//obtin extensia
		var numeFisier =path.basename(im.cale_imagine,ext)//obtin numele fara extensie
		let imNoua=path.join(caleGalerie+"/mic/", numeFisier+"-mic"+".webp");//creez cale apentru imaginea noua; prin extensia wbp stabilesc si tipul ei
        let imNoua2=path.join(caleGalerie+"/mediu/", numeFisier+"-mediu"+".png");//pt MEDIU
        //let imNoua1=path.join(caleGalerie+"/mediu/", numeFisier+"mediu"+.)
        //console.log(imNoua);
        const mic = ("images/galerie/mic/"+ numeFisier+"-mic"+".webp")
        const mare = ("images/galerie/"+ numeFisier + ext)
        const mediu = ("images/galerie/mediu/"+ numeFisier+"-mediu"+".png")

        //console.log(mare);
        vectImagini.push({mare:mare, mic:mic, mediu:mediu, descriere:im.descriere, sfert_ora: im.sfert_ora}); //adauga in vector un element
		if (!fs.existsSync(imNoua))//daca nu exista imaginea, mai jos o voi crea
		sharp(imVeche)
		  .resize(150) //daca dau doar width(primul param) atunci height-ul e proportional
		  .toFile(imNoua, function(err) {
              if(err)
			    console.log("eroare conversie",imVeche, "->", imNoua, err);
          });
          
        if (!fs.existsSync(imNoua2))//daca nu exista imaginea, mai jos o voi crea    PT MEDIU
		sharp(imVeche)
		  .resize(200) //daca dau doar width(primul param) atunci height-ul e proportional
		  .toFile(imNoua2, function(err) {
              if(err)
			    console.log("eroare conversie",imVeche, "->", imNoua2, err);
		  });
	}
    // [ {mare:cale_img_mare, mic:cale_img_mica, descriere:text, sfert_ora:sfert_ora}, {mare:cale_img_mare, mic:cale_img_mica, descriere:text, sfert_ora:sfert_ora}, {mare:cale_img_mare, mic:cale_img_mica, descriere:text,  sfert_ora:sfert_ora}  ]
    return vectImagini;
}

/*SELECTAM DOAR POZELE CARE SE POTRIVESC LA TIMP*/
function poze_sfert_ora(value){
    if(minute <= 15)
        return value.sfert_ora == 1;
    else if(minute <=30)
        return value.sfert_ora == 2;    
    else if(minute <= 45)
        return value.sfert_ora == 3;
    else
        return value.sfert_ora == 4;
}
const imagini_final = imagini.filter(poze_sfert_ora).slice(0,10);


// console.log(imagini_final);
// console.log("TOATE IMAGINILE");
// console.log(imagini);

app.set("view engine", "ejs"); //setez ca motor de template ejs

app.get("/galerie.json", (request, response) => {// am pus aici ca sa nu am inca folderul static
    response.status(403).render("pagini/403", {tipuri, user: getUtiliz(req)});
});

app.use(express.static(__dirname + "/resurse")); //setez folderul de resurse ca static, ca sa caute fisierele in el, in urma cererilor
app.use("/poze_uploadate", express.static(__dirname + "/poze_uploadate"));

app.get(["/","/index"], (req, res) => { //ca sa pot accesa pagina principala si cu localhost:8080 si cu localhost:8080/index
    const ip = req.headers['x-forwarded-for'] || req.connection.remoteAddress;//aici e cazul doar de req.connection.remoteAdress
    
    client.query("select distinct u.id, nume, prenume from users u right join logs l on l.user_id = u.id", function(err, db_result) {
        if (err) {
            console.error(err);
            return res.status(404).render("pagini/404", {user: getUtiliz(req)});
        }

        res.render("pagini/index", {ip, imagini_final, imagini, minute, tipuri, user: getUtiliz(req), utilizatori_activi: db_result ? db_result.rows : []});
    });
});

app.get("/galerie", (req, res) => { 
    res.render("pagini/galerie", {imagini_final, minute, tipuri, user: getUtiliz(req)});
});

app.get("/animale", function(req, res) {
    const {
        tip,
        talie,
    } = req.query;
    let conditie = "";

    if (tip) {
        conditie = " where tip='" + tip + "'";

        if (talie) {
            conditie += " and talie='" + talie + "'";
        }
    }
    
    client.query("select id, nume, descriere, imagine, pret, greutate, tip, talie, culoare, temperament, dresat, data_adaugare from animale" + conditie, function(err, db_result) {
        if (err) {
            console.error(err);
        }

        if (!db_result) {
            return res.status(404).render("pagini/404", {user: getUtiliz(req)});
        }

        console.log(tipuri)

        res.render("pagini/animale", {
            animale: db_result.rows,
            tipuri, 
            user: getUtiliz(req),
        });
    });
});

app.get("/animale/:id_animal", function(req, res) {
    const {
        id_animal,
    } = req.params;
    
    client.query("select id, nume, descriere, imagine, pret, greutate, tip, talie, culoare, temperament, dresat, data_adaugare from animale where id='" + id_animal + "'", function(err, db_result) {
        if (err) {
            console.error(err);
        }

        if (!db_result || !db_result.rows.length) {
            return res.status(404).render("pagini/404", {tipuri, user: getUtiliz(req)});
        }

        res.render("pagini/animal", {
            animal: db_result.rows[0],
            tipuri,
        });
    });
});

let parolaServer="TehniciWeb";
app.post("/inreg",function(req, res){ 
    console.log("primit date");
    var username;
    let formular= formidable.IncomingForm();

    //nr ordine: 4
    
    formular.parse(req, function(err, campuriText, campuriFisier){
        console.log(campuriText);
		let eroare ="";
		if(campuriText.username=="" || !campuriText.username.match("^[A-Za-z0-9]+$")){
			eroare+="Username gresit. ";
        }
        if(campuriText.nume=="" ){
			eroare+="Introduceti nume. ";
        }
        if(campuriText.prenume=="" ){
			eroare+="Introduceti prenume. ";
        }
        if(campuriText.email=="" ){
			eroare+="Introduceti email. ";
        }
        if(campuriText.parola=="" ){
			eroare+="Introduceti parola. ";
        }
        if(campuriText.rparola=="" ){
			eroare+="Reintroduceti parola. ";
        }
        if (campuriText.telefon && !campuriText.telefon.match(/^\+?0[0-9]{9}[0-9]*$/)) {
            eroare+="Reintroduceti telefon. ";
        }

        
		if (eroare) {
            return res.render("pagini/inregistrare",{err:"Eroare formular. " + eroare, raspuns: "", tipuri});
        }

        let parolaCriptata = crypto.scryptSync(campuriText.parola, parolaServer, 32).toString('hex');
        const {
            username,
            nume,
            prenume,
            email,
            telefon,
        } = campuriText;
        const comanda= `insert into users (username, nume, prenume, parola, email, telefon, imagine_profil) values ($1, $2, $3, $4, $5, $6, $7)`;
        const poza = campuriFisier.poza ? `/poze_uploadate/${username}/${campuriFisier.poza.name}` : null;
        client.query(comanda, [username, nume, prenume, parolaCriptata, email, telefon, poza], function(err, rez){
            if (err){
                console.log(err);
                let err_msg = "";
                if (err.code === "23505" && err.constraint === "users_username_key") {
                    err_msg = "Username existent!";
                } else {
                    err_msg = "Eroare baza date! Reveniti mai tarziu";
                }
                return res.render("pagini/inregistrare",{err: err_msg, raspuns:"Datele nu au fost introduse.", tipuri});
            }
            
            res.render("pagini/inregistrare",{err:"", raspuns:"Totu bine!", tipuri, user: getUtiliz(req)});
            trimiteMail(campuriText);
            console.log(campuriText.email);
        });
    });
	
	//nr ordine: 2
	formular.on("fileBegin", function (name,campFisier){
		console.log("inceput upload: ", campFisier);
		if(campFisier && campFisier.name!=""){
			//am  fisier transmis
			var cale=__dirname+"/poze_uploadate/"+username
			if (!fs.existsSync(cale))
				fs.mkdirSync(cale);
			campFisier.path=cale+"/"+campFisier.name;
			console.log(campFisier.path);
		}
	});
	
	//nr ordine: 1
	formular.on("field", function(name,field){
		if(name=='username')
			username=field;
		console.log("camp - field:", name)
	});
	
	//nr ordine: 3
	formular.on("file", function(name,field){
		console.log("final upload: ", name);
	});
});

app.post("/login", function (req, res) {
    const formular = formidable.IncomingForm();
    formular.parse(req, function (err, campuriText) {
        //console.log(campuriText);
        let parolaCriptata = crypto.scryptSync(campuriText.parola, parolaServer, 32).toString('hex');
        //let comanda= `select username, nume,email, culoare_chat, rol from utilizatori where username= '${campuriText.username}' and parola='${parolaCriptata}'`;
        let comanda_param = `select id, username, nume, rol, email, telefon, imagine_profil from users where username= $1::text and parola=$2::text`;
        //console.log(comanda);
        
        client.query(comanda_param, [campuriText.username, parolaCriptata], function (err, rez) {
            // console.log(err, rez)
        //client.query(comanda, function(err, rez){
            if (!err){
                // console.log(rez);
                if (rez.rows.length === 1) {
                    req.session.utilizator = {
                        id:rez.rows[0].id,
                        username:rez.rows[0].username,
                        nume:rez.rows[0].nume,
                        email:rez.rows[0].email,
                        rol:rez.rows[0].rol,
                        telefon:rez.rows[0].telefon,
                        imagine_profil:rez.rows[0].imagine_profil,
                    }
                }
            }
            res.redirect("/index");
        });
    }); 
})

app.get("/logout", function (req, res) {
    req.session.utilizator = null;  
    res.redirect("/index");
})

app.get("/utilizatori", function (req, res) {
    const query = "select id, username, nume, rol, prenume from users where username != $1::text";
    const username = req.session.utilizator ? req.session.utilizator.username : null;

    if (!username) {
        return res.redirect("/index");
    }
    
    client.query(query, [username], function (err, rez) {
        if (err || !rez.rows.length) {
            return res.redirect("/index");
        }

        res.render("pagini/utilizatori", {tipuri, user: getUtiliz(req), utilizatori: rez.rows});
    });
})

app.patch("/utilizatori/:id", function (req, res) {
    const query = "update users set rol = $1 where id = $2";
    const rol = req.body.rol;
    const id = req.params.id;
    
    client.query(query, [rol, id], function (err, rez) {
        if (err) {
            console.log(err);
            return res.json({success: 0});
        }

        client.query("select nume, email, rol from users where id = $1", [id], function(err, db_result) {
            if (err || !db_result) {
                return res.json({success: 0});
            }
    
            const message = `Ai fost ${rol === "admin" ? "promovat" : "retrogradat"} la rolul ${rol}`;
            trimiteMail(db_result.rows[0], message);

            res.json({success: 1});
        });
    });
})


app.get(["/inregistrare", "/contact"], (request, response) => {
    response.render(`pagini${request.url}`, {tipuri, user: getUtiliz(request)}, (error, content) => {
        if (error) {
            if (error.message.includes("Failed to lookup view")) {
                return response.status(404).render("pagini/404", {tipuri, user: getUtiliz(request)});
            }
        }

        response.send(content);
        response.end();
    });
});


app.listen(8080, () => {
    console.log("serverul a pornit!");
});



// function x () {}
// const x = () => {}