var greet = document.getElementById("greet");
var dance = document.getElementById("dance");
var scare = document.getElementById("scare");

var xhr = new XMLHttpRequest();

var endpoint = "https://radiant-taiga-82724.herokuapp.com/perform_action"

function send_post(action) {
	xhr.open("POST", endpoint, true);
	xhr.setRequestHeader('Content-Type', 'application/json');
	xhr.send(JSON.stringify({
	    value: action
	}));
	console.log(action);
}

greet.onclick = function() {
	send_post("greet");
}

dance.onclick = function() {
	send_post("dance");
}

scare.onclick = function() {
	send_post("scare");
}