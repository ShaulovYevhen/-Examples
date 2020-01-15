/*
10. Зчитати з консолі число m. Вивести число під номером m, яке ділиться на 3 або на 4.
Наприклад:
m = 6
Числа, що діляться на 3 або на 4:
3,   4,    6,   8,   9,   12,   15, 16, 18, 20, 21...
[1], [2], [3], [4], [5],  [6],  [7]
Під номером 6 число 12.
*/
import java.util.Scanner;
public class Hom10
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Введіть число, що ділиться на 3 або на 4 та натисніть ENTER: ");
        double m = scan.nextDouble();
        int rez=0;
        if ((m/3)%1==0 || (m/4)%1==0)
            {double i = 3;
             while (i>=0)
                {double x=i/3;
                 double y=i/4;
                    if (x%1==0)
                    {
                    rez++;
                        if (rez==(int)m)
                        {
                            System.out.println("rez="+i); break;
                        }
                    }
                    else if (y%1==0)
                    {
                    rez++;
                        if (rez==(int)m)
                        {
                            System.out.println("rez="+i); break;
                        }
                    }
                    i++;
                }
            }
        else{System.out.println("Число не ділиться ні на 3 ні на 4");}
    }
}
