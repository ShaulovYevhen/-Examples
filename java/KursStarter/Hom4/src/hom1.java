//Задача 1
//З консолі вводиться число m. Потрібно видалити з тексту всі слова довжини m.
import java.util.Scanner;
public class hom1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int m;
        String text= "кожен мисливець бажає знати де сидить фазан";
        System.out.println("Введіть m ");
        m= scan.nextInt();
        String[] words = text.split(" ");
        for (int i = 0; i <  words.length; i++){
            if (words[i].length()==m) {
                words[i]=" ";
            }
        }
        text= "";
        for (int i = 0; i <  words.length; i++) {
            if (words[i].equals(" "))
            {
            } else {
                text=text+words[i]+" ";
            }
        }
        System.out.println();
        System.out.println(text);
    }
}
