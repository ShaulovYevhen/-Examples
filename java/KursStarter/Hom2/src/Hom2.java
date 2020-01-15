/*
2. Зчитати з консолі 2 числа. Вивести в консоль більше із них.
*/

import java.util.Scanner;
public class Hom2
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Введіть перше число та натисніть ENTER: ");
        float firstNum = scan.nextFloat();
        System.out.println("Введіть друге число та натисніть ENTER: ");
        float secondNum = scan.nextFloat();
            if (firstNum > secondNum)
            {System.out.println(firstNum);}
            else
            {System.out.println(secondNum);}
    }
}