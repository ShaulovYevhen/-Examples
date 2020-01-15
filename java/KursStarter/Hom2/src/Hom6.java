/*
6. Зчитати з консолі числа m та n. Вивести найбільше число з проміжку [m,n],
яке ділиться націло на 7 або на 9.
*/

import java.util.Scanner;
public class Hom6 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Введіть перше число та натисніть ENTER: ");
    double firstNum = scan.nextDouble();
        System.out.println("Введіть друге число та натисніть ENTER: ");
    double secondNum = scan.nextDouble();
        if (firstNum > secondNum)
        {
            while (firstNum!=secondNum)
            {double x = firstNum/7;
             double y = firstNum/9;
                if (x%1==0||y%1==0)
                {
                    System.out.println("Найбільше число з проміжку [m,n], яке ділиться націло на 7 або на 9: "+(int)(firstNum));
                    break;
                }
                firstNum--;
            }

        }
        else if (firstNum < secondNum)
        {
            while (firstNum!=secondNum)
            {double x = secondNum/7;
                double y = secondNum/9;
                if (x%1==0||y%1==0)
                {
                    System.out.println("Найбільше число з проміжку [m,n], яке ділиться націло на 7 або на 9: "+(int)(secondNum));
                    break;
                }
                secondNum--;
            }

        }
        else {System.out.println("Числа рівні");}
}
}

