/*
4. Створіть масив з 12 випадкових цілих чисел з відрізка [-15; 15].
Визначте який елемент є в цьому масиві максимальним і виведіть індекс його останнього входження в масив.
Наприклaд, при згенерованому масиві [1, 2, 3, 4, 12, 5, 6, 7, 8, 9, 12, 10]
                                     0  1  2  3  4   5  6  7  8  9  10  11
має бути: масимальний елемент 12, індекс останнього входження 10.
*/

public class hom4 {
    public static void main(String[] args)
    {
        int[] myArray = new int[12];
        int ind=0;
        int y = 0;
        for (int i = 0; i < myArray.length; i++)
        {
            myArray[i] = (int)(Math.random()*31)-15;
            System.out.print(myArray[i] + " ");
            if (i==0)
            {
                y=myArray[i];
            }
            if ( y<=myArray[i] )
            {
                y=myArray[i];
                ind=i;
            }
        }
        System.out.println();
        System.out.println("масимальний елемент = "+ y +", індекс останнього входження: " + ind);
    }
}