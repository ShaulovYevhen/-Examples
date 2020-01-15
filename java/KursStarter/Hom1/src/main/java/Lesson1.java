/*1. Зчитати ціле число з консолі, потім зчитати друге ціле число 
з консолі. Вивести в консоль спочатку друге число, а потім перше. */

import java.util.Scanner;
public class Lesson1 {
    public static void main(String[] args) {
       Scanner scan = new Scanner(System.in);
       
       System.out.println ("Введіть перше число: ");
       int x = scan.nextInt();
       
       System.out.println ("Введіть друге число: ");
       int y = scan.nextInt();
              
       System.out.println(y);
       System.out.println(x);
    }
}
