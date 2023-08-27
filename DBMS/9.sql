db.createCollection("s");


// db.s.insertMany([
//   { id: 1, name: 'Ryan', gender: 'M' },
//   { id: 2, name: 'Joanna', gender: 'F' }
// ]);


// db.s.find();

db.s.insertOne({id:1,name:"Suyog",year:"2002"});

db.s.insertMany([{id:4,name:"Atharva",year:"2002"},{id:5,name:"Manas",year:"2002"},{id:6,name:"Piyusha",year:"2001"}]);


db.s.insertOne({name:"Rohit",address:{city:"Pune",clg:"PICT"},year:"2003"});


// db.s.find().pretty();


// db.s.updateOne({id:4},{$set:{name:"Aryan"}});
// db.s.updateMany({year:"2002"},{$set:{year:1999}});
// db.s.find().pretty();


// db.s.deleteOne({name:"Rohit"});
// db.s.deleteMany({year:"2002"});


// update+insert=upsert
// db.s.updateOne({id:10},{$set:{name:"Arunima"}},{upsert:true});


// sort function
// db.s.find().sort({name:-1}).pretty();
//  db.s.find().sort({name:1}).pretty();
// db.s.find().sort({name:1}).limit(2).pretty();


// Logical Operators
// db.s.find({$or:[{name:"Piyusha"},{name:"Rohit"}]}).pretty();
// db.s.findOneAndUpdate({id:6},{$set:{year:"1990"}});


// save method depricated
// db.s.save({id:11,name:"Aniket",year:"2000"});


// gt 
// gte
// lt
// lte
// in
// nin
// db.s.find({id:{$gt:2}}).pretty();
// db.s.find ( { id: { $nin: [1,4] } } ).pretty();

// db.s.find().pretty();