System.out.println("Enter Name");
					fname = sc.next();
					
					System.out.println("Enter Id");
					emp_id = sc.nextInt();
					
					var query = "insert into Employee (Emp_id,fname) values("+emp_id+",'"+fname+"')";
                    System.out.println(query);