/*
3. Зчитати з консолі 2 числа у 2 змінні. Обміняти місцями значення змінних і вивести в косоль.
*/

import java.util.Scanner;
public class Hom3 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Введіть перше число та натисніть ENTER: ");
        float firstNum = scan.nextFloat();
        System.out.println("Введіть друге число та натисніть ENTER: ");
        float secondNum = scan.nextFloat();
        float y = firstNum;
        firstNum = secondNum;
        secondNum = y;
        System.out.println("Значення першої змінної після обміну " + firstNum);
        System.out.println("Значення другої змінної після обміну " + secondNum);
    }
}
