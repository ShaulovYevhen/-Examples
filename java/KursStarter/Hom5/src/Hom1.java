//Задача 1
//Напишіть метод, який визначає, число просте чи ні
//(прості числа діляться націло тільки на 1 і самі на себе, наприклад, 3,7,11...).
//Виведіть всі прості числа від 1 до 100.

public class Hom1 {

    public static void main(String[] args) {
        System.out.print("Прості числа від 1 до 100 : ");
        for (int i=1; i<101; i++){
            if(IsSimple(i)){
                System.out.print(i+" ");
            }
        }
    }
    public static boolean IsSimple(int value)
    {
        for (int i = 2; i < value; i++){  //бежим по циклу начиная от 2 и до самого числа не включительно
            if (value % i == 0){  //если остаток от деления числа на значение шага цикла равен нулю, то
                return false;  //вернуть false, переданное число простым не является
            }
        }
        return true;
    }
}