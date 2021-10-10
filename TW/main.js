const nodemailer = require("nodemailer");


async function trimiteMail(username, email){
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
		subject:"Te-ai inregistrat cu succes",
		text:"Username-ul tau este "+username,
		html:"<h1>Salut!</h1><p>Username-ul tau este "+username+"</p>",
	})
	console.log("trimis mail");
}

(async () => {
    try {
        await trimiteMail("victor", "pejow67176@pigicorn.com");
        console.log("trimis")
    } catch (err) {
        console.log(err);
    }
})();