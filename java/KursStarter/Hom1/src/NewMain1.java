/*
3. Ввести з консолі дробове число. Вивести цілу частину.
 */

import java.util.Scanner;
public class NewMain1 {
    public static void main(String[] args) {
       Scanner scan = new Scanner(System.in);
       
       System.out.println ("Введіть дробове число та натисніть Enter:");
       double n = scan.nextDouble();
       System.out.println((int)(n));
    }
}
