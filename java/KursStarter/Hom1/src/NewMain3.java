/*
5. Ввести ціну товару (dоulе) і суму ваших грошей (dоule). Визначити, яку
цілу кількість товарів можна купити на ваші гроші і яка буде здача.
 */
import java.util.Scanner;
public class NewMain3 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println ("Введіть ціну товару та натисніть Enter:");
        double price = scan.nextDouble();
        System.out.println ("Введіть кількість грошей та натисніть Enter:");
        double money = scan.nextDouble();
        
        int rez = (int)(price/money);
        System.out.println ("Кількість товару, яку ви можете купити: " + rez);
        double rez1 = (int)((price%money)*100)/100.0;
        System.out.println ("Ваша здача: " + rez1);
    }
    
}
