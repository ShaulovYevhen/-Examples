//Задача 4
//Створіть метод, який перетворює рядок з двійковим числом в десяткове число.
//На вхід він має приймати String з двійковим числом (наприклад, "001001110"),
//а на виході має видавати десяткове число.
import java.util.Scanner;
public class Hom4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String doubleNum = inputNumber(scanner);
        System.out.println(ToInt(doubleNum));
    }
    public static String inputNumber(Scanner scanner) {
        System.out.println("Введіть двійкове число");
        String doubleNum= scanner.nextLine();
        if (doubleNum.length()>30){
            System.out.println("Помилка вводу");
            return inputNumber(scanner);
        }
        char[] num = new char[doubleNum.length()];
        System.out.println();
        for (int i=0; i<num.length; i++){
            num[i]=doubleNum.charAt(i);
            if (num[i]=='1'|| num[i]=='0'){
            }
            else {
                System.out.println("Помилка вводу");
                return inputNumber(scanner);
            }
        }return doubleNum;
    }
    public static int ToInt(String doubleNum){
        int rez=0;
        for (int i=0;i<doubleNum.length();i++){
            rez=rez*2+Character.getNumericValue(doubleNum.charAt(i));
        }
        return rez;
    }

    //System.out.println(Integer.toBinaryString(232));число в двоичной системе
    //System.out.println(Integer.parseInt(doubleNum, 2));//перевод из двоичной системы в десятичную
}
