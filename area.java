import java.util.*;
class area_calculate
{
     static double area;
     static final double pi=3.14;
     static void Area(double radius)
     {
        area=pi*radius*radius;
        System.out.println(area);
     }
   
     static void Area(double length,double breadth)
     {
        area=length*breadth;
        System.out.println(area);
     }
 
     static void Area(double base,double height,double width)
     {
        area=0.5*base*height;
        System.out.println(area);
     }
}

class area  
{
     public static void main(String args[])
     {
      Scanner s=new Scanner(System.in);
      area_calculate ar=new area_calculate();
      System.out.println("Enter choice: 1 for Circle, 2 for Rectangle, 3 for Triangle");
      int choice=s.nextInt();
      switch(choice)
      {
        case 1:
            System.out.println("Enter radius: ");
            double r=s.nextDouble();
            System.out.println("Area of circle is: ");
            ar.Area(r);
            break;
        case 2:
            System.out.println("Enter length:");
            double l=s.nextDouble();
            System.out.println("Enter breadth:");
            double b=s.nextDouble();
            System.out.println("Area of rectangle is:");
            ar.Area(l,b);
            break;
        case 3:
            System.out.println("Enter base:");
            double base=s.nextDouble();
            System.out.println("Enter height:");
            double h=s.nextDouble();
            System.out.println("Area of rectangle is:");
            ar.Area(base,h,0);
            break;
        default:
            System.out.println("Invalid choice");
      }
    }
}




  
             














  
              
     

