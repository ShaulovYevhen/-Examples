/*
3. Створіть масив з 4 випадкових цілих чисел з відрізка [10; 99],
виведіть його на екран у рядок.
Визначити і вивести на екран повідомлення про те, чи є масив строго
зростаючою послідовністю (кожен наступний елемент більший за попередній).
*/

public class hom3
{
    public static void main(String[] args)
    {
        int[] myArray= new int[4];
        boolean y=true;
        for (int i = 0; i <  myArray.length; i++)
        {
            myArray[i]=(int)(Math.random()*(99-10+1)+10);
            System.out.print(myArray[i] + " ");
            if (i!=0&& myArray[i]<myArray[i-1])
            {
                y=false;
            }
        }
        System.out.println();
        if (y) {System.out.println("кожен наступний елемент більший за попередній");}
        else {System.out.println("Масив не являється строго зростаючою послiдовнiстю");}
    }
}
