var xhr = new XMLHttpRequest();
var selected_robot = "jarvis";

function get_endpoint() {
	var endpoint = "https://makeharvard-mk1.herokuapp.com/" + selected_robot;
	return endpoint
}

function send_post(action) {
	var endpoint = get_endpoint();
	xhr.open("POST", endpoint, true);
	xhr.setRequestHeader('Content-Type', 'application/json');
	xhr.send(JSON.stringify({
	    value: action
	}));
	console.log(action);
}

//---------------------------------------------------------------

var jarvis = document.getElementById("jarvis");
jarvis.onclick = function() {
	selected_robot = "jarvis";
}
var friday = document.getElementById("friday");
friday.onclick = function() {
	selected_robot = "friday";
}
var virgil = document.getElementById("virgil");
virgil.onclick = function() {
	selected_robot = "virgil";
}
var homer = document.getElementById("homer");
virgil.onclick = function() {
	selected_robot = "homer";
}
var plato = document.getElementById("plato");
virgil.onclick = function() {
	selected_robot = "plato";
}
var jokasta = document.getElementById("jokasta");
virgil.onclick = function() {
	selected_robot = "jokasta";
}
var helen = document.getElementById("helen");
virgil.onclick = function() {
	selected_robot = "helen";
}