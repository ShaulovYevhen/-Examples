/*
8. Знайти суму всіх додатніх двозначних чисел, кратних 17
*/

public class Hom8 {
    public static void main(String[] args)
    {int sum=0;
        double i=0;
        while (i<100)
        {
            if ((i/17)%1==0&&i>=0)
            {sum = sum+(int)i;
            }
            i++;
        }
        System.out.println(sum);
    }
}
