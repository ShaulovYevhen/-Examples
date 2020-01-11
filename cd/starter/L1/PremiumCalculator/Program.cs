using System;
namespace PremiumCalculator
{
    class Program
    {
        static void Main(string[] args)
        {
            link2:
            int salary;
            Console.WriteLine("Введите размер заработной платы - целое число больше 0");
            while (!int.TryParse(Console.ReadLine(), out salary))
            {
                Console.WriteLine("Ошибка ввода! Размер заработной платы - целое число больше 0");
            }
            if (salary < 0)
            {
                Console.WriteLine("Ошибка ввода! Размер заработной платы - целое число больше 0");
                goto link2;
            }
            int serviceLenght;
            Console.WriteLine("Введите сколько лет сотрудник прораболтал (Введите целое чиcло меньше 100)");
            link1:
            while (!int.TryParse(Console.ReadLine(), out serviceLenght))
            {
                Console.WriteLine("Ошибка ввода! (Введите целое чиcло меньше 100)");
            }
            if (serviceLenght > 100)
            {
                Console.WriteLine("Ошибка ввода! (Введите целое чиcло меньше 100)");
                goto link1; 
            }
            if (serviceLenght < 5)
            {
                Console.WriteLine("Премия : " +(salary*0.10)+" у.е.");
            }
            else if (serviceLenght >= 5 && serviceLenght < 10)
            {
                Console.WriteLine("Премия : " + (salary * 0.15) + " у.е.");
            }
            else if (serviceLenght >= 10 && serviceLenght < 15)
            {
                Console.WriteLine("Премия : " + (salary * 0.25) + " у.е.");
            }
            else if (serviceLenght >= 15 && serviceLenght < 20)
            {
                Console.WriteLine("Премия : " + (salary * 0.35) + " у.е.");
            }
            else if (serviceLenght >= 20 && serviceLenght < 25)
            {
                Console.WriteLine("Премия : " + (salary * 0.45) + " у.е.");
            } 
            else 
            {
                Console.WriteLine("Премия : " + (salary * 0.5) + " у.е.");
            }
            Console.WriteLine("Чтобы продолжить введите 1 и нажмите ENTER. Для выхода введите любой другой символ");
            try 
            {
                int n = Convert.ToInt32(Console.ReadLine()); 
                if (n == 1) 
                {
                goto link2;
                } 
                else
                {
                Environment.Exit(0);
                }
            }  
            catch (System.FormatException)
            {
                Environment.Exit(0);
            }
        }
    }
}
