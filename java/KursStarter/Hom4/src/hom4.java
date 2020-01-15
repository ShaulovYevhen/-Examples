//Задача 4
//        Перетворити текст у camel case, тобто пробіли між словами видалити,
//        а першу букву наступного слова зробити великою.
//        Для прикладу:
//        Початковий рядок - "Я любю мову Java"
//        На виході - "ЯЛюблюМовуJava"
public class hom4 {
    public static void main(String[] args) {
        String text = "Найдовше    слово для заміни обирається випадковим чином серед всіх слів найбільшої довжини";
        //text=text.replaceAll("\\s+"," ");// убрать пробелы \\s - знак пробела; \\s+ - 1 и больше пробелов
        String[] words = text.split(" ");
        text="";
        for (int i=0; i<words.length; i++){
            if (words[i].equals("")) {
            }
            else {
                words[i] = words[i].replace(words[i].charAt(0), Character.toUpperCase(words[i].charAt(0)));
                text += words[i];
            }
        }
        System.out.println("Текст: "+text);
    }//toUpperCase()

}
