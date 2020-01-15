/*
7. Ввести дробове число. Вивести першу цифру після коми на екран.
 */

import java.util.Scanner;
public class NewMain5 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println ("Введіть дробове число та натисніть Enter:");
        double a = scan.nextDouble();  // 1,23
        double rez = (int)(a*10); // 12.0
        double rez1 = (rez/10); //1.2
        // int rez2 = (int)((rez1%1)*10); // 1.999999999996
        int rez2 = (int)((rez1%1+0.000001)*10); // 2
        System.out.println ("Перша цифра після коми: "+ rez2);
            }
    
}
