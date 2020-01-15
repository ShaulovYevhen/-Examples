//Задача 2
//У змінній text знаходиться текст. Потрібно: замінити всі найкоротші слова у тексті,
// якщо таких декілька, на одне із найдовших.
// Найдовше слово для заміни обирається випадковим чином серед всіх слів найбільшої довжини.

public class hom2 {
    public static void main(String[] args) {
        String text= "Найдовше слово для заміни обирається випадковим чином серед всіх слів найбільшої довжини три";
        String[] words = text.split(" ");
        String[] biggerLenght;
        String biggerWord;
        biggerLenght = new String[words.length];
        biggerWord = words[0];
        System.out.println(text);
        text= "";
        for (int i = 0; i <  words.length; i++){
            if (biggerWord.length()<words[i].length()) {
                biggerWord=words[i];
            }
        }
        String lessWord=words[0];
       // System.out.println(biggerWord);
        int j=0;
        for (int i = 0; i <  words.length; i++){
            if (lessWord.length()>words[i].length()){
                lessWord=words[i];
            }
            if (biggerWord.length()==words[i].length()){
                biggerLenght[j]=words[i];
                j++;
            }
        }
        biggerWord=biggerLenght[(int)(Math.random()*j)];
        // System.out.println(biggerLenght[(int)(Math.random()*j)]);
        for (int i = 0; i <  words.length; i++){
            if (words[i].length()==lessWord.length()){
                text=text+biggerWord+" ";
            }else {
                text=text+words[i]+" ";
            }
        }
        System.out.println("Текст: "+text);
    }

}
