//Задача 8
//Потрібно зберігати оцінки m студентів по n предметам.
//Кількість студентів і оцінки можуть вводитися,
//генеруватися випадковим чином або задаватися фіксовано (на ваш вибір). Потрібно:
//вивести середній бал кожного студента
//вивести студентів, які не отримали жодної 5
//вивести студентів-відмінників (тільки 5)
//иванов 1 |1 1 1 1 1 1
//петров 2 |2 2 2 2 2 2
//сидоро 3 |4 4 4 4 4 4

public class hom8 {
    public static void main(String[] args) {
        int student=12;
        int subject=5;
        boolean noFive = true;
        int[][] arr = new int[student][subject];
        int gpa=0;
        for (int i = 0; i < student; i++) {  //идём по строкам
            for (int j = 0; j < subject; j++) {//идём по столбцам
                arr[i][j] = (int) (Math.random() * (5 - 3 + 1) + 3);
                System.out.print(" " + arr[i][j] + " "); //вывод оценки
                gpa += arr[i][j];
                if (arr[i][j]==5 ){
                    noFive=false;
                }
            }
            gpa = Math.round(gpa / subject);
            System.out.print("Сeреднiй бал= " + gpa + "; ");
            if (gpa == 5) {
                System.out.print("Студент під номерном " + (i + 1) + " відмінник");
            }
            if(noFive){
                System.out.print("Студент під номерном " + (i + 1) + " не отрмав жодної пятірки");
            }
            System.out.println();//перенос строки ради визуального сохранения табличной формы
            gpa = 0;
            noFive = true;
        }
    }
}

