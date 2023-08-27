import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.util.Scanner;

public class a8
{
	public static void main(String[] args)
	{
		try {
			Scanner sc=new Scanner(System.in);
			
			int emp_id = 0;
			String fname = "";
			

			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/MJ", "MJ", "Mysql@123");
			System.out.println("Connection successfull\n");
			Statement st=con.createStatement();
			
			while(true) {
				System.out.println("1.insert\n2.update\n3.delete\n4.exit");
				System.out.println("Enter Choice : ");
				int ch=sc.nextInt();
				
				if(ch == 4) break;
				
				switch(ch) {
				case 1:
					
					System.out.println("Enter Name");
					fname = sc.next();
					
					System.out.println("Enter Id");
					emp_id = sc.nextInt();
					
					var query = "insert into Employee (Emp_id,fname) values("+emp_id+",'"+fname+"')";

					st.executeUpdate(query);
					
					break;
					
				}
				
			}
			
			
		}catch(Exception e) {
			System.out.println(e);
		}
	}
}{

}
