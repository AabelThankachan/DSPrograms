import java.util.*;
class Employee
{
    String name;
    int age;
    String phone_no;
    String address;
    double salary;

    double print_Salary()
    {
       return salary;
    } 
}

class Officer extends Employee
{
   String specialization;
   public static void main(String args[])
   {
      Scanner s=new Scanner(System.in);
      Officer o=new Officer();
      System.out.println("Officer details:");
      System.out.println("Enter name:");
      o.name=s.nextLine();
      System.out.println("Enter age:");
      o.age=s.nextInt();
      s.nextLine();
      System.out.println("Enter phone number:");
      o.phone_no=s.nextLine();
      System.out.println("Enter address:");
      o.address=s.nextLine();
      System.out.println("Enter salary:");
      o.salary=s.nextDouble();
      s.nextLine();
      System.out.println("Officer details:");
      System.out.println("Name is: "+o.name);  
      System.out.println("Age is: "+o.age);  
      System.out.println("Phone number is: "+o.phone_no);  
      System.out.println("Address is: "+o.address);  
      System.out.println("Salary is: "+o.salary);  
      System.out.println("Name is: "+o.name);
   }
}

class Manager extends Employee
{
   String department;
   public static void main(String args[])
   {
      Scanner s=new Scanner(System.in);
      Manager m=new Manager();
      System.out.println("Manager details:");
      System.out.println("Enter name:");
      m.name=s.nextLine();
      System.out.println("Enter age:");
      m.age=s.nextInt();
      s.nextLine();
      System.out.println("Enter phone number:");
      m.phone_no=s.nextLine();
      System.out.println("Enter address:");
      m.address=s.nextLine();
      System.out.println("Enter salary:");
      m.salary=s.nextDouble();
      s.nextLine();
      System.out.println("Manager details:");
      System.out.println("Name is: "+m.name);  
      System.out.println("Age is: "+m.age);  
      System.out.println("Phone number is: "+m.phone_no);  
      System.out.println("Address is: "+m.address);  
      System.out.println("Salary is: "+m.salary);  
   }
}
  















      
