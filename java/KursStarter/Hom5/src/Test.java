public class Test {
    public static void main(String[] args) {
        int a[] = new int[10];
        for (int i = 0; i < a.length; i++) {
            System.out.print(i + " ");
            a[i] = i;
        }
        System.out.println();
        int shift = 2;
        for (int n = 0; n < shift; n++) {
            int buffer = a[0];
            a[0] = a[a.length - 1];
            for (int j = 1; j < a.length - 1; j++) {
                a[a.length - j] = a[a.length - j - 1];
            }
            a[1] = buffer;
        }
//        for (int i = 0; i < a.length; i++) {
//            System.out.print(a[i] + " ");
//        }
    }

    public static int[] shiftArray(int[] incomingArray, int shift) {
        if(shift != 0){
            // Любой сдвиг больше длины массива можно оптимизировать до меньшего сдвига
            // через деление по модулю
            int finalShift;
            if (shift > incomingArray.length){
                shift = Math.abs(shift % incomingArray.length);
            }
            else {
                finalShift = shift;
            }
            // в зависимости от знака сдвига движение будет происходить
            // слева направо при положительном сдвиге
            // справа налево при отрицательном
            if (shift > 0) {
                for (int n = 0; n < shift; n++) {
                    // убираем первый элемент в буфер, а на его место ставим хвостовой элемент
                    int buffer = incomingArray[0];
                    incomingArray[0] = incomingArray[incomingArray.length - 1];
                    // циклично сдвигаем весь массив
                    for (int j = 1; j < incomingArray.length - 1; j++) {
                        incomingArray[incomingArray.length - j] = incomingArray[incomingArray.length - j - 1];
                    }
                    // ставим буферный элемент в 1 ячейку
                    incomingArray[1] = buffer;
                }
            }
            else if (shift < 0) {
                for (int i = 0; i > shift; i--) {
                    int buffer = incomingArray[incomingArray.length - 1];
                    incomingArray[incomingArray.length - 1] = incomingArray[0];

                    for (int j = 1; j < incomingArray.length - 1; j++) {
                        incomingArray[j - 1] = incomingArray[j];
                    }
                    incomingArray[incomingArray.length - 2] = buffer;
                }
            }
        }
        return incomingArray;
    }
}