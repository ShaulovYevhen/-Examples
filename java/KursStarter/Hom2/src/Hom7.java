/*
7. Зчитати з консолі числа m та n. Знайти суму всіх чисел з проміжку [m, n],
які діляться на 4 або на 5.
*/

import java.util.Scanner;
public class Hom7
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Введіть перше число та натисніть ENTER: ");
        double firstNum = scan.nextDouble();
        System.out.println("Введіть друге число та натисніть ENTER: ");
        double secondNum = scan.nextDouble();
        int sum=0;
        if (firstNum > secondNum)
        {
            while (firstNum!=secondNum)
            {double x = firstNum/4;
                double y = firstNum/5;
                if (x%1==0||y%1==0)
                {
                    sum = sum + (int)firstNum;
                }
                firstNum--;
            }
        }
        else if (firstNum < secondNum)
            {
                while (firstNum!=secondNum)
                {double x = secondNum/4;
                    double y = secondNum/5;
                    if (x%1==0||y%1==0)
                    {
                        sum = sum + (int)secondNum;
                    }
                    secondNum--;
                }
            }
        else {System.out.println("Числа рівні");}
    System.out.println("Сума всіх чисел з проміжку [m, n],які діляться на 4 або на 5: "+sum);
    }
}
