/*
5. Зчитати з клавіатури число k. Вивести в ряд k зірочок.
*/
import java.util.Scanner;
public class Hom5 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Введіть число та натисніть ENTER: ");
        int firstNum = scan.nextInt();
        while (firstNum!=0)
        {
            System.out.println("*");
            firstNum--;
        }
}
}
