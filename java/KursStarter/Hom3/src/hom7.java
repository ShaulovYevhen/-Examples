/*
7. Зчитати число n з консолі.
Створити масив з n елементів.
Заповнити масив числами: посередині 0, потім вправо і вліво збільшуємо на 1, далі вправо і вліво на збільшуємо на 2.
Якщо кількість елементів парна, то всередині мають бути 2 нулі. Вивести масив на екран.
Приклад 11: 5,4,3,2,1,0,1,2,3,4,5
Приклад 8: 3, 2, 1, 0, 0, 1, 2, 3
*/
import java.util.Scanner;
public class hom7
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        int n = 0;
        System.out.println("Введіть n та натисніть ENTER: ");
        n = scan.nextInt();
        if (n%2!=0)
        {
            int[] myArray;
            myArray = new int[n];
            n=n/2;
            for (int i = 0; i < myArray.length; i++)
            {
                myArray[i] = n-i;
                if (myArray[i]<0)
                {
                    myArray[i]=myArray[i]*-1;
                }
                System.out.print(myArray[i] + " ");
            }
        }
        else
        {
            int[] myArray;
            myArray = new int[n];
            for (int i = 0; i < myArray.length; i++)
            {
                myArray[i] = (n/2-i)-1;
                if (myArray[i]<0){break;}
                System.out.print(myArray[i] + " ");
            }
            for (int i = n-1; i>0; i--)
            {
                if (i==n/2-1){break;}
                myArray[i]=(n-i)-1;
                System.out.print(myArray[i] + " ");
            }
        }
    }
}