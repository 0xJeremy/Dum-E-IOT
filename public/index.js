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

//---------------------------------------------------------------

var b90 = document.getElementById("b90");
b90.onclick = function() {
	send_post("b90");
}

var bn90 = document.getElementById("bn90");
bn90.onclick = function() {
	send_post("b90");
}

var b180 = document.getElementById("b180");
b180.onclick = function() {
	send_post("b180");
}

var bn180 = document.getElementById("bn180");
bn180.onclick = function() {
	send_post("bn180");
}

//---------------------------------------------------------------

var p0 = document.getElementById("p0");
p0.onclick = function() {
	send_post("p0");
}

var p45 = document.getElementById("p45");
p45.onclick = function() {
	send_post("p45");
}

var p90 = document.getElementById("p90");
p90.onclick = function() {
	send_post("p90");
}

//---------------------------------------------------------------

var gopen = document.getElementById("gopen");
gopen.onclick = function() {
	send_post("gopen");
}

var gclose = document.getElementById("gclose");
gclose.onclick = function() {
	send_post("gclose");
}