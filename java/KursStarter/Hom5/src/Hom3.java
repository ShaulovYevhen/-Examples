//Задача 3
//==================
//Написати метод, який циклічно зсовує масив вправо або вліво на вказане число позицій.
//Зсув також повинен бути кільцевим,тобто ті елементи, які йдуть вправо або вліво за межі масиву,
//повинні додаватися з іншого його кінця.
//Наприклад, дано масив:
//1 2 3 4 5 6
//Кільцевий зсув вправо на 2 одиниці:
//5 6 1 2 3 4

import java.util.Scanner;
public class Hom3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = inputNumber(scanner);// кількість зссувів
        int a[] = new int[10];
        for (int i=0; i<a.length; i++){
            System.out.print(i+" ");
            a[i]=i;
        }
        System.out.println();
        if (inputSide(scanner)){
            System.out.println();
            a=exchangeLeft(a,num);
        }
        else {
            a=exchangeRight(a,num);
        }
        for (int i=0; i<a.length; i++){
            System.out.print(a[i]+" ");
        }
    }
    public static int[] exchangeLeft(int[] incomingArray, int shift){
        for (int j=0;j<shift;j++){
            int t=incomingArray[0];
            for (int i=0;i<incomingArray.length; i++) {
                if(i+1<incomingArray.length) {
                    incomingArray[i]=t;
                    incomingArray[i]=incomingArray[i+1];
                    incomingArray[i+1]=t;
                }
                else {
                    incomingArray[i]=j;
                }
            }
        } return incomingArray;
    }
    public static int[] exchangeRight(int[] incomingArray, int shift){
        for (int n = 0; n < shift; n++) {
            int buffer = incomingArray[0];
            incomingArray[0] = incomingArray[incomingArray.length - 1];
            for (int j = 1; j < incomingArray.length - 1; j++) {
                incomingArray[incomingArray.length - j] = incomingArray[incomingArray.length - j - 1];
            }
            incomingArray[1] = buffer;
        }
        return incomingArray;
    }
    public static int inputNumber(Scanner scanner) {
        System.out.println("Введіть число:");
        if(scanner.hasNextDouble()) {
            int res = scanner.nextInt();
            scanner.nextLine();
            return res;
        } else {
            System.out.println("Число не коректне!");
            scanner.nextLine();
            return inputNumber(scanner);
        }
    }
    public static boolean inputSide(Scanner scanner){
        System.out.println("Введіть сторону (вліво або вправо) та натисніть Enter:");
        String side=scanner.nextLine();
        if(side.equals("вліво")){
            return true;
        }
        else if (side.equals("вправо")){
            return false;
        }
        else {
           System.out.println("Неправильне значення! Введіть вліво або вправо та натисніть Enter:");
           return inputSide(scanner);
        }
    }
}
//        int temp = a[0];
//        int secondTemp = a[0];
//        for (int i=0;i<a.length; i++){
//            if(i+1<a.length){
//                temp = a[i];
//                a[i] = a[i+1];
//                a[i+1] = temp;
//            }
//            System.out.print(a[i]+ " ");
//        }