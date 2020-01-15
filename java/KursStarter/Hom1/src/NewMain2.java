/*
4. Ввести дробове число грошей в грн з клавіатури (тип double). 
Вивести ціле значення копійок.
 */
import java.util.Scanner;
public class NewMain2 { 
    public static void main(String[] args) {
       Scanner scan = new Scanner(System.in);
       
       System.out.println ("Введіть дробове число грошей в грн та натисніть Enter:");
       double n = scan.nextDouble();
       int res = (int)n;
       double res2 = (int)((n - res)*100)/100.0;
// int rez= Match.round(n*100)%100;       
       System.out.println(res2);
    }
}
