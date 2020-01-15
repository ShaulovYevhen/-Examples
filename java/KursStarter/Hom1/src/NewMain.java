/*2. Зчитати з консолі послідовно Ваше ім'я, потім Ваше прізвище, 
потім ваш вік. Вивести в консоль фразу "Моє ім'я: {ім'я}. 
Моє прізвище {прізвище}. Мені {вік} років".*/

import java.util.Scanner;
public class NewMain {
    public static void main(String[] args) {
       Scanner scan = new Scanner(System.in);
        
       System.out.println ("Ваше ім'я: ");
       String firstName = scan.nextLine();
       
       System.out.println ("Ваше прізвище: ");
       String secondName = scan.nextLine();
       
       System.out.println ("Ваш вік: ");
       int age = scan.nextInt();
       
       System.out.println("Моє ім'я: " + firstName);
       System.out.println("Моє прізвище: " + secondName);
       System.out.println("Мені: " + age + " років");
    }
    
}
