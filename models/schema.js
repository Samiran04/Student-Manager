const mongoose=require('mongoose');
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
const Model=mongoose.model('Model',schema);
module.exports=Model;