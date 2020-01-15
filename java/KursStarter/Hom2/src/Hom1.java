/*1. Зчитати з консолі число. Визначити:
        1) Це цифра (0-9) чи число;
        2) Це додатнє, від'ємне чи 0
        Вивести в консоль результат перевірки (наприклад, "Ви ввели додатню цифру 6" або
        "Ви ввели від'ємне число 42").*/

import java.util.Scanner;
public class Hom1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println ("Введіть число та натисніть ENTER: ");
        int x = scan.nextInt();
        if (x<10&&x>0)
            {System.out.println("Ви ввлели додатню цифру " + x);
            }
        else if (-x>=10&&x<0)
            {System.out.println("Ви ввлели від'ємне число " + x);
            }
        else
            {System.out.println("Число не підпадає під умови");
            }
    }

}
