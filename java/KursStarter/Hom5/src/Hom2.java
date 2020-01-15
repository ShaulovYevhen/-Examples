//Задача 2
//Створіть метод, який визначає, скільки грошей отримує працівник в тиждень.
//Mетод має приймати на вхід мінімум 2 параметри: зарплата за годину, кількість пропрацьованих годин.
//Умова:
//1) Кожна година після 40 рахується за півтори.
//2) Працівник не може працювати більше 60 годин на тиждень.
//3) Працівник не може отримувати менше 8 доларів за годину.
import java.util.Scanner;
public class Hom2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double salary = inputSalary(scanner);
        int hour = inputHour(scanner);
        System.out.println("В тиждень працівник отримує :" +Math.round(salary*hour)+" $");
    }
    public static double inputSalary(Scanner scanner) {
        System.out.println("Введіть зарплату за годину(повинна бути більше 8):");
        if(scanner.hasNextDouble()) {
            double res = scanner.nextDouble();
            if (res < 8) {
                System.out.println("Число не коректне!");
                scanner.nextLine();
                return inputSalary(scanner);
            }
            else {
                scanner.nextLine();
                return res;
            }
        } else {
            System.out.println("Число не коректне!");
            scanner.nextLine();
            return inputSalary(scanner);
        }
    }
    public static int inputHour(Scanner scanner) {
        System.out.println("Введіть години (не більше 60):");
        if(scanner.hasNextInt()) {
            int res = scanner.nextInt();
            if (res > 60 || res<0) {
                System.out.println("Число не коректне!");
                scanner.nextLine();
                return inputHour(scanner);
            }
            else {
                scanner.nextLine();
                if (res>40){
                    res+=Math.round(res/2);
                }
                return res;
            }
        } else {
            System.out.println("Число не коректне!");
            scanner.nextLine();
            return inputHour(scanner);
        }
    }
}
