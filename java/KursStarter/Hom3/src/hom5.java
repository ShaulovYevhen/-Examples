/*
5. Зчитати з консолі 2 числа: n та m. Створити масив на n елементів.
Заповнити його послідовністю, вигляду m, m-2, m-4, m-6 і т.д.
Вивести результуючий масив на екран.
*/
import java.util.Scanner;
public class hom5 {
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Введіть перше число та натисніть ENTER: ");
        int n= scan.nextInt();
        System.out.println("Введіть друге число та натисніть ENTER: ");
        int m = scan.nextInt();
        int[] myArray;
        myArray = new int[n];
        for (int i = 0; i < myArray.length; i++)
        {
            myArray[i] = m-(i*2);
            System.out.print(myArray[i] + " ");
        }
    }
}
