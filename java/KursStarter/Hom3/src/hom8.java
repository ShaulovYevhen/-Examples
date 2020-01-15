/*8. Зчитати з клавіатури число n. Вивести в консоль порожній квадрат з діагоналлю. Для прикладу, при n=6:
        * * * * * *
        * *       *
        *   *     *
        *     *   *
        *       * *
        * * * * * */
import java.util.Scanner;
public class hom8 {
    public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int n = 0;
    System.out.println("Введіть n та натисніть ENTER: ");
    n = scan.nextInt();

        for(int i=0; i < n; i++)
        {
            for(int k=0; k < n; k++)
            {

                if(k==0 || k==n-1 || i==0 || i==n-1 || k==i )
                {
                    System.out.print("*");
                }
                else
                {
                    System.out.print(" ");
                }
            }

            System.out.println();
        }
}
}
