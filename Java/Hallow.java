/*
 * Name:
 * Date: 
 * Description:
 */

import java.util.Scanner;

public class Hallow
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        
        //prompt and read the length of the side from the user
        System.out.print("Enter length of side: ");
        int stars = input.nextInt(); //number of stars on a side
        
        if(stars < 1)
        {
            stars = 1;
            System.out.printf("Invalid Input%nUsing default value 1%n");
        }
        else if(stars > 20)
        {
            stars = 20;
            System.out.printf("Invalid Input%nUsing default value 20%n");
        }
        
        int row = 1; //current row of the square printed
        
        //repeat for as many rows as the user entered
        while (row <= stars)
        {
            int column = 1; //current column of the square
            
            //and for as many columns as rows
            while(column <= stars)
            {
                if(row == 1)
                {
                    System.out.print("*");
                }
                else if(row == stars)
                {
                    System.out.print("*");
                }
                else if(column == 1)
                {
                    System.out.print("*");
                }
                else if(column == stars)
                {
                    System.out.print("*");
                }
                else
                {
                    System.out.print(" ");
                }
                
                column++;
            }
            
            System.out.println();
            row++;
        }
    }
    
}
