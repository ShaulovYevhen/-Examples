//зчитати хвилини, години, секунди і вивести час через 1 секунду
import java.util.Scanner;
public class zad {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int sec;
        int min;
        int hou;
do
    {
    System.out.println("Введіть секунди та натисніть ENTER: ");
    sec = scan.nextInt();
    if (sec > 60 || sec < 0) {
        System.out.println("Неправильне значення"); break;
    }

    System.out.println("Введіть хвилини та натисніть ENTER: ");
    min = scan.nextInt();
    if (min > 60 || min < 0) {
        System.out.println("Неправильне значення XB<60"); break;
    }

    System.out.println("Введіть години та натисніть ENTER: ");
    hou = scan.nextInt();
    if (hou > 24 || hou < 0) {
        System.out.println("Неправильне значення XB<60"); break;
    }
        sec++;
        {
            if (sec>59){
                sec=0;
                min++;
            }
            if (min>59)
            {
                min=0;
                hou++;
                if (hou>23) {
                    hou=0;
                }
            }
        }
        System.out.println("Секунди "+sec+" Хвилини "+min+" Години "+hou);
     }while (sec>60||min>60||hou>24);
    }
}