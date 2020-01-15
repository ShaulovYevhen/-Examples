//Задача 5
//        Сортувати слова в тексті за алфавітом.
// якщо в тексті слово починається з великої букви сортування працює не коректно
import java.util.Arrays;
public class hom5 {
    public static void main(String[] args) {
        String text = "найдовше слово для заміни обирається випадковим чином серед всіх слів найбільшої довжини індія їжак сааа яблуко";
        String[] words = text.split(" ");
        text="";
//        Arrays.sort(words);
//        for (int j = 0; j < words.length; j++) {
//            text=text+words[j]+" ";
//        }
        for (int j = 0; j < words.length; j++) {
            for (int i = j + 1; i < words.length; i++) {
                if (words[i].compareTo(words[j]) < 0) {
                    String k = words[j];
                    words[j] = words[i];
                    words[i] = k;
                }
            }
            text=text+words[j]+" ";
        }
        System.out.println("Текст: "+text);
    }
}
