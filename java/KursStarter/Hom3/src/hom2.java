/*
2. Створіть 2 масиви з 5 випадкових цілих чисел з відрізка [0; 5] кожен.
Виведіть масиви на екран в двох окремих рядках.
Порахуйте середнє арифметичне елементів кожного масиву і виведіть,
для якого з масивів це значення виявилося більше
(або повідомте, що їхнє середні арифметичні рівні).
*/
public class hom2
{
    public static void main(String[] args)
    {
        int[] firstArray;
        int[] secondArray;
        int x=0;
        int y=0;
        firstArray = new int[5];
        secondArray = new int[5];
        for (int i = 0; i <  firstArray.length; i++)
        {
            firstArray[i] = (int)(Math.random()*(6));
            x+=firstArray[i];
            System.out.print(firstArray[i] + ", ");
        } x=Math.round(x/firstArray.length);
        System.out.println();
        for (int i = 0; i <  secondArray.length; i++)
        {
            secondArray[i] = (int) (Math.random() * (6));
            y+=secondArray[i];
            System.out.print(secondArray[i] + ", ");
        } y=(y/secondArray.length);
        System.out.println();
        if (x>y)
        {
            System.out.println("Середнє арифметичне першого масиву більше: "+x);
        } else if (x<y)
        {
            System.out.println("Середнє арифметичне дугого масиву більше: "+y);
        } else {System.out.println("Середнє арифметичне масивів рівне: "+y);}
    }
}
