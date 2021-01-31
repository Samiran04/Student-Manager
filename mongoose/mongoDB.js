const mongoose = require('mongoose');

//connecting mongoose with mongoDB
mongoose.connect('mongodb://localhost/MyToDoList', {useNewUrlParser: true, useUnifiedTopology: true});

//taking the connection
const db = mongoose.connection;

//checking if any error
db.on('error', console.error.bind(console, 'connection error:'));

//opening db
db.once('open', function() {
    console.log(`MongoDB Server is running fine`);
});

module.exports=db;