const http = require('http');
var XMLHttpRequest = require("xmlhttprequest").XMLHttpRequest;
const express = require('express')
const path = require('path')
var app = express();
var bodyParser = require('body-parser');
const PORT = process.env.PORT || 5000

app.use(function (req, res, next) {
    res.setHeader('Access-Control-Allow-Origin', '*');
    res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE');
    res.setHeader('Access-Control-Allow-Headers', 'X-Requested-With,content-type');
    res.setHeader('Access-Control-Allow-Credentials', true);
    next();
});

app.use(bodyParser.json());

app.set('views', __dirname + '/public');
app.engine('html', require('ejs').renderFile);
app.use('/', express.static(__dirname + '/public'));

var action_jarvis = "";
var action_friday = "";
var action_virgil = "";

app.get('/', function(req, res) {
    res.render('index.html');
});

app.post('/jarvis', function(req, res){
    console.log('POST /');
    console.dir(req.body);
    action_jarvis = req.body.value;
    res.writeHead(200, {'Content-Type': 'text/html'});
});

app.post('/friday', function(req, res){
    console.log('POST /');
    console.dir(req.body);
    action_friday = req.body.value;
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end('thanks');
});

app.post('/virgil', function(req, res){
    console.log('POST /');
    console.dir(req.body);
    action_virgil = req.body.value;
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end('thanks');
});

app.get('/get_jarvis', function(req, res) {
    res.send(action_jarvis)
});
app.get('/get_friday', function(req, res) {
    res.send(action_friday)
});
app.get('/get_virgil', function(req, res) {
    res.send(action_virgil)
});

app.listen(PORT, function() { console.log("Listening on port " + PORT)});