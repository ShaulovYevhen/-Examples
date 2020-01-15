/*
8. Ввести чотиризначне число. Вивести першу цифру, другу цифру, 
третю цифру і четверту цифру в консоль. Кожна з нового рядка
 */
import java.util.Scanner;
public class NewMain6 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println ("Введіть чотиризначне число та натисніть Enter:");
        int a = scan.nextInt();
        
        int first = (int)(a/1000);
        System.out.println (first);
        
        int second = (int)((a - (first*1000))/100); 
        System.out.println (second);
        
        int third = ((int)(a/10))%10;
        System.out.println (third);  
        
        int fourth = (int)(a%10); 
        System.out.println (fourth);
     
    }
    
}
