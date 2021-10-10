function changeRole (event) {
    const role = event.getAttribute("data-role");
    const options = {
        headers: {"Content-Type": 'application/json'},
        body: JSON.stringify({rol: role}),
        method: "PATCH",
    };
    fetch(`http://localhost:8080/utilizatori/${event.id}`, options)
        .then(async (result) => {
            const data = await result.json();

            if (data.success) {
                event.innerText = role === "admin" ? "Retrogradează" : "Promovează";
                event.setAttribute("data-role", "admin" ? "comun" : "admin");

                const role_node = document.getElementById(`rol-${event.id}`);
                role_node.innerText = role;
            } else {
                alert("Nu a reusit");
            }
        })
        .catch((err) => {
            console.log(err);
        });
}