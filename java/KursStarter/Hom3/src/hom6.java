/*
6. Користувач вводить з клавіатури натуральне число більше 3, яке зберігається в змінну n.
Якщо користувач ввів не підходяще число, то програма повинна попросити користувача повторно ввести число.
Створити масив з n випадкових цілих чисел з відрізка [0, n] і вивести його на екран.
Створити другий масив тільки з парних елементів першого масиву, якщо вони там є, і вивести його на екран.
*/
import java.util.Scanner;
public class hom6 {
    public static void main(String[] args)
{
    Scanner scan = new Scanner(System.in);
    int n=0;
    int lenSecMass=0;
    do
    {
        System.out.println("Введіть натуральне число більше 3 та натисніть ENTER: ");
        n= scan.nextInt();
    } while (n<=3);
    int[] myArray;
    myArray = new int[n];
    for (int i = 0; i < myArray.length; i++)
    {
        myArray[i] = (int) (Math.random() * (n + 1));
        System.out.print(myArray[i] + " ");
        if (myArray[i] % 2 == 0 && myArray[i]!=0)
        {
            lenSecMass++;
        }
    } System.out.println();
    if (lenSecMass==0) {System.out.println("Парні елементи відсутні");}
    else
    {
        int[] secondArray;
        secondArray = new int[lenSecMass];
        int j=0;
        for (int i = 0; i <myArray.length; i++)
        {
            if (myArray[i] % 2 == 0 && myArray[i]!=0)
            {
                secondArray[j] = myArray[i];
                System.out.print(secondArray[j] + " ");
                j++;
            }
        }
    }
}
}