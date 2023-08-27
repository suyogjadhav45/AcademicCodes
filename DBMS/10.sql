

db.createCollection("a");
db.a.insertMany([
  { id: 4, name: 'Ryan', gender: 'M' },
  { id: 2, name: 'Joanna', gender: 'F' },
  { id: 3, name: 'Joanna2', gender: 'F' }
]);
db.a.insertOne({id:1, name:'sj'});


//INDEXING 
// db.a.createIndex({id:1});
// // db.a.explain().find({id:1});
// db.a.getIndexes();
// db.a.createIndex({id:1,name:1});
// db.a.getIndexes();
// db.a.createIndex({name:1},{unique:true});
// db.a.getIndexes();
db.Student.insert({_id:1, rollNo:101, regNo:100001, name:"Vidyut", dept:"Computer", 
marks:[95, 90, 92, 91, 93]});
db.Student.insert({_id:2, rollNo:102, regNo:100002, name:"Pratap", dept:"IT", 
marks:[92, 91, 92, 91, 90]});
 db.Student.insert({_id:3, rollNo:103, regNo:100003, name:"Kailash", dept:"E&TC", 
marks:[90, 98, 97, 96, 99]});
db.Student.insert({_id:4, rollNo:104, regNo:100004,address:{city:"Pune",clg:"coep"}, name:"Mukund", 
dept:"Mechanical", marks:[95, 94, 93, 90, 90]});
 db.Student.insert({_id:5, rollNo:105, regNo:100005,address:{city:"Pune",clg:"PICT"}, name:"Girish", dept:"Civil", 
marks:[92, 98, 94, 96, 93]});
db.Student.insert({_id:6, rollNo:106, regNo:100006, address:{city:"Pune",clg:"PICT"}, name:"Neeraj", 
dept:"Electrical", marks:[98, 96, 94, 93, 92]});

db.Student.insert({_id:7, rollNo:107, regNo:100007, name:"Prashant", dept:"E&TC", 
marks:[98, 99, 97, 93, 92]});


// db.Student.count();
// db.Student.distinct("rollNo");

// db.Student.aggregate({$match:{dept:"E&TC"}});
// db.Student.aggregate({$match:{rollNo:{"$gt":103}}});
// db.Student.aggregate({$match:{marks:{"$size":5}}});


// db.Student.aggregate({$group:{_id:"$rollNo"}});
// db.Student.aggregate({$group:{_id:"$dept"}});
// db.Student.aggregate({$group:{_id:{rollNo:"$rollNo",address:"$address.clg"}}});
// db.Student.aggregate({$group:{_id:"$address.city"}});

//  db.Student.aggregate({$sort:{name:1}});
// db.Student.aggregate([{$match:{dept:"E&TC"}},{$group:{_id:{rollNo:"$rollNo",regNo:"$regNo"}}}]);

 

//  db.Student.aggregate([
//      {$unwind:"$marks"},
//      {$group:{_id:"$rollNo", total_Score:{$sum:"$marks"}}}
//      ]);

//  db.Student.aggregate([
//      {$unwind:"$marks"},
//      {$group:{_id:"$rollNo", total_Score:{$sum:"$marks"}}},
//      {$sort:{"total_Score":-1}}
//      ]);
    
//  db.Student.aggregate([
//      {$unwind:"$marks"},
//      {$group:{_id:"$rollNo", total_Score:{$sum:"$marks"}}},
//      {$sort:{_id:1}}
//      ]);


// Display the total marks of 'Computer' department students in decreasing order.
// db.Student.aggregate([{$unwind:"$marks"}, {$match:{dept:"E&TC"}}, 
// {$group:{"_id":"$rollNo", "total_Score":{$sum:"$marks"}}}, {$sort:{"total_Score":-1}}]);


// Find the highest scorer in 'Computer' department.
// db.Student.aggregate([{$unwind:"$marks"}, {$match:{dept:"Comp"}}, 
// {$group:{"_id":"$rollNo", "total_Score":{$sum:"$marks"}}}, {$sort:{"total_Score":-1}},{$limit:1}]);


// db.Student.aggregate({$project:{rollNo:1,name:1,dept:1}});

     
    



// db.Student.find().pretty();


// db.a.find();








