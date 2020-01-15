/*
1. Створити масив на 20 елементів. Заповнити його випадковими цілии числами
в діапазоні [-25,25]. Замінити всі непарні елементи масива на 0. Вивести новий масив на екран.
*/

public class hom1 {
    public static void main(String[] args)
    {
        int[] myArray;
        myArray = new int[20];
        for (int i = 0; i <  myArray.length; i++)
        {
           int el =(int)(Math.random()*(25+1))-(int)(Math.random()*(25+1));
           if (el%2==0)
              {
              myArray[i] = el;
              }
           else{myArray[i]=0;}
           System.out.print(myArray[i] + ", ");
        }
    }
}
