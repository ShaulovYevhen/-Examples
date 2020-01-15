/*
9. Ви взяли у банку гроші на суму m (вводиться з консолі) під 20% на рік.
Через скільки років сума, яку ви повинні віддати банку, подвоється?
*/
import java.util.Scanner;
public class Hom9 {
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Введіть сумму кредиту та натисніть ENTER: ");
        double sum = scan.nextDouble();
        int i=0;
        double rez = Math.round(sum+(sum*0.2));
        while (rez <= sum*2)
        {  rez = Math.round(rez+sum*0.2);
           i++;
        }
        System.out.println("Сума подвоється через "+i+" років");
}

}
