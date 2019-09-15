
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Sodrul Amin Shaon
 */
public class Main {
    public static void main(String [] args)
    {
        while (true) {            
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
            if(n <= 0)
                break;

            String inputString = scanner. nextLine();
            System.out.println("String read from console is : \n"+inputString);
        }
        //System.out.print("Enter a string : ");
        
    }
}
