//Задача 6
//Задати з консолі числа m, n.
//Створити двомірний масив розміром m на n.
//Заповнити його випадковими цілими числами в діапазоні [13:41].
//Порахувати суму елементів у кожному рядку.
//Вивести індекс рядка, де ця сума найбільша.

import java.util.Scanner;
public class hom6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        int m;
        System.out.println("Введіть m та натисныть Enter: ");
        m = scanner.nextInt();
        System.out.println("Введіть n та натисныть Enter: ");
        n = scanner.nextInt();
        int[] sumArr = new int[m];
        int sum=0;
        int[][] twoDimArray = new int[m][n];
        for (int i = 0; i < m; i++) {  //идём по строкам
            for (int j = 0; j < n; j++) {//идём по столбцам
                twoDimArray[i][j]=(int)(Math.random()*(41-13+1)+13);// (int)(Math.random()*(max-min+1)+min))
                System.out.print(" " + twoDimArray[i][j] + " "); //вывод элемента
                sum+=twoDimArray[i][j];
            }
            System.out.println("Сума= "+sum);//перенос строки ради визуального сохранения табличной формы
            sumArr[i]=sum;
            sum=0;
        }
        int r=sumArr[0];
        int rez=0;
        for (int i = 0; i < m; i++) {
            if (r<sumArr[i]){
                r=sumArr[i];
                rez=i+1;
            }
        }
        System.out.println("індекс рядка, де сума найбільша: "+rez);
    }
}
