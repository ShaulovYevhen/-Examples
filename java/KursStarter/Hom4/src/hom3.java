//Задача 3
// Знайти у тексті найдовше слово/слова і замінити в ньому/в них всі буква "а", "о", "у" на символ "%".
public class hom3 {
    public static void main(String[] args) {
        String text= "Найдовше слово для заміни обираєтася випадковим чином серед всіх слів найбільшої довжини";
        String[] words = text.split(" ");
        System.out.println(text);
        String[] biggerLenght;
        String biggerWord;
        biggerLenght = new String[words.length];
        biggerWord = words[0];
        text= "";
        int j=0;
        for (int i = 0; i <  words.length; i++){
            if (biggerWord.length()<words[i].length()) {
                biggerWord=words[i];
            }
        }
        for (int i =0; i<words.length; i++) {
            if (words[i].length()==biggerWord.length()){
                biggerLenght[j]=words[i].replace('а', '%').replace('о', '%').replace('у', '%');;
                text=text+biggerLenght[j]+" ";
               // System.out.println(biggerLenght[j]);
                j++;
            }
            else {
                text+=words[i]+" ";
            }

        }
        System.out.println("Текст: "+text);
    }
}

