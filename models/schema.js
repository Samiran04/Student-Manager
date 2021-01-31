const mongoose=require('mongoose');

//creating our Schema
const schema=new mongoose.Schema({
    dis:{
        type:String,
        required:true
    },
    cat:{
        type:String,
    },
    date:{
        type:String,
        required:true
    }
});

//creating out model with schema
const Model=mongoose.model('Model',schema);


module.exports=Model;