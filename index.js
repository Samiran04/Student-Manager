const express=require('express');
const app=express();
const port=8000;
const mongoose=require('./mongoose/mongoDB');
const Model=require('./models/schema');

app.use(express.static('./assets'));
app.use(express.urlencoded({entended:false}));

app.set('view engine','ejs');
app.set('views','./views');

app.get('/',function (req,res){
    Model.find({},function(err,My_list){
        if(err)
        {
            console.log(`Error while fetching data ${err}`);
            return;
        }
        return res.render('home',{
            title:'TODO App',
            MyList:My_list
        });
    });
});

app.get('/Delete-data',function(req,res){
    const id=req.query.id;
    Model.findByIdAndDelete(id,function(err){
        if(err)
        {
            console.log(`Error while deleting data ${err}`);
            return;
        }
        return res.redirect('back');
    });
});

app.post('/Enter-data',function (req,res){
    Model.create({
        dis:req.body.dis,
        cat:req.body.cat,
        date:req.body.date
    },function (err,MyObj){
        if(err)
        {
            console.log(`Error while entering data ${err}`);
            return;
        }
        console.log(MyObj);
        res.redirect('back');
    });
});

app.listen(port,function(err){
    if(err)
    {
        console.log(`Error while runnig server ${err}`);
        return;
    }
    console.log(`Server is running on port ${port}`);
});