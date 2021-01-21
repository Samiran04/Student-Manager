const mongoose = require('mongoose');
mongoose.connect('mongodb://localhost/MyToDoList', {useNewUrlParser: true, useUnifiedTopology: true});
const db = mongoose.connection;
db.on('error', console.error.bind(console, 'connection error:'));
db.once('open', function() {
    console.log(`MongoDB Server is running fine`);
});