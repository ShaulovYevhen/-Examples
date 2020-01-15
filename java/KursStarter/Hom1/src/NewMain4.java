    /**
    6. Ввести ціле двозначне число. Вивести першу цифру на екран.
     */
import java.util.Scanner;
public class NewMain4 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println ("Введіть ціле двозначне число та натисніть Enter:");
        int a = scan.nextInt();
        
        int rez = (int)(a/10);
        System.out.println (rez);
    }
    
}
