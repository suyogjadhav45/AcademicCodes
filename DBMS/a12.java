import java.util.*;

import org.bson.Document;

import com.mongodb.MongoClient;
import com.mongodb.MongoCredential;
import com.mongodb.client.FindIterable;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;

public class connect
{
	public static void main(String[] args)
	{
		try 
		{
			MongoClient mongo = new MongoClient("localhost" , 27017);
			
//			MongoCredential credential;
//			credential = MongoCredential.createCredential("t31235","t31235db" , "t31235".toCharArray());
			
			
			MongoDatabase database = mongo.getDatabase("admin");
			MongoCollection<Document> collection = database.getCollection("CRUDCollection");
			
			System.out.println("Connected to Db");
			
			Scanner sc = new Scanner(System.in);
			while(true) {
				System.out.println("1.InsertDoc\n2.UpdateDoc\n3.DeleteDoc\n4.Display\n5.EXIT\n\n");
				System.out.println("Enter choice : ");
				int ch = sc.nextInt();
				
				if(ch == 5) {
					System.out.println("Exited Success");
					mongo.close();
					break;
				}
				
				switch(ch) {
				
				case 1:
					System.out.println("Enter Name : ");
					String name = sc.next();
					
					System.out.println("Enter Age : ");
					int age = sc.nextInt();
					
					Document doc1 = new Document("name" , name).append("age",age);
					collection.insertOne(doc1);
					
					System.out.println("Entered Succesfully");
					
					break;
					
				case 2:
					System.out.println("Enter Name : ");
					name = sc.next();
					
					System.out.println("Enter Updated Age : ");
					age = sc.nextInt();
					
					Document doc2 = new Document("name" , name);
					Document doc3 = new Document("age" , age);
					Document doc4 = new Document("$set" , doc3);
					
					collection.updateMany(doc2, doc4);
					
					System.out.println("Updated Succesfully");
					break;
					
				case 3:
					System.out.println("Enter Name : ");
					name = sc.next();
					
					Document doc5 = new Document("name" , name);
					
					collection.deleteOne(doc5);
					
					System.out.println("Deleted Succesfully");
					break;
				
				case 4:
					System.out.println("Documets in collection are : \n");
					
					FindIterable<Document> iterDoc = collection.find();
					Iterator<Document> It = iterDoc.iterator();
					
					while(It.hasNext()) 
					{
						System.out.println(It.next());
					}
					break;
					
				default : 
					System.out.println("Enter correct choice : \n");
					ch = sc.nextInt();
				}
			}
		}catch(Exception e) {
			System.out.println(e);
		}
	}
}