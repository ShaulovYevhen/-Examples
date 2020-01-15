//Задача 7
//Задати з консолі числа m, n.
//Створити двомірний масив розміром m на n.
//Заповнити його випадковими цілими числами в діапазоні [-11:11].
//Замінити всі додатні числа в згенерованому масиві на їхні квадрати,
//а всі від'ємні замінити на нулі.
import java.util.Scanner;
public class hom7 {
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
                twoDimArray[i][j]=(int)(Math.random()*22)-11; // (int)(Math.random()*22)-11)
                if (twoDimArray[i][j]<0){
                    twoDimArray[i][j]=0;
                }
                else {
                    twoDimArray[i][j]=twoDimArray[i][j]*twoDimArray[i][j];
                }
                System.out.print(" " + twoDimArray[i][j] + " "); //вывод элемента
            }
            System.out.println();//перенос строки ради визуального сохранения табличной формы
        }
    }
}
