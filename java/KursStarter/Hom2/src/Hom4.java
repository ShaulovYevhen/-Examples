/*
4. Зчитати з клавіатури числа k та n. Вивести в консоль числа в проміжку [k,n].
*/

import java.util.Scanner;
public class Hom4 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Введіть перше число та натисніть ENTER: ");
        int firstNum = scan.nextInt();
        System.out.println("Введіть друге число та натисніть ENTER: ");
        int secondNum = scan.nextInt();
        if (firstNum > secondNum)
        {
            while (firstNum!=secondNum)
            {
                secondNum++;
                if (firstNum==secondNum) {break;}
                System.out.println(secondNum);
            }
        }
        else if (firstNum < secondNum)
        {
            while (firstNum!=secondNum)
            {
                firstNum++;
                if (firstNum==secondNum) {break;}
                System.out.println(firstNum);
            }
        }
        else {System.out.println("Числа рівні");}
}
}
