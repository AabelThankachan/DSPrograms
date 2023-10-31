import java.util.*;
class area_calculate
{
     double area;
     final double pi=3.14;
     double Area(int radius)
     {
        area=pi*radius*radius;
        return area;
     }
   
     double Area(int length,int breadth)
     {
        area=length*breadth;
        return area;
     }
 
     double Area(int base,int height,int width)
     {
        area=0.5*base*height;
        return area;
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
            int r=s.nextInt();
            System.out.println("Area of circle is: ");
            area_calculate.Area(r);
            break;
        case 2:
            System.out.println("Enter length:");
            int l=s.nextInt();
            System.out.println("Enter breadth:");
            int b=s.nextInt();
            System.out.println("Area of rectangle is:");
            area_calculate.Area(l,b);
            break;
        case 3:
            System.out.println("Enter base:");
            int base=s.nextInt();
            System.out.println("Enter height:");
            int h=s.nextInt();
            System.out.println("Area of rectangle is:");
            area_calculate.Area(base,h,0);
            break;
        default:
            System.out.println("Invalid choice");
      }
    }
}




  
             














  
              
     

