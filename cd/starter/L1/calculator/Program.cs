using System;
namespace calculator
{
    class Program
    {
        static void Main(string[] args)
        {
            Random x = new Random();
            double operand1 = Convert.ToDouble(x.Next(-100, 100) / 10.0), 
                   operand2 = Convert.ToDouble(x.Next(-100, 100) / 10.0);
            link1:
            Console.WriteLine("Введите знак арифметической операции:");
            string sign = Console.ReadLine();
            switch (sign)
            {
                case "+":
                {
                    Console.WriteLine(Math.Round(operand1 + operand2,2));   
                    break;
                }
                case "-":
                {
                    Console.WriteLine(Math.Round(operand1 - operand2, 2));
                    break;
                }
                case "*":
                {
                    Console.WriteLine(Math.Round(operand1 * operand2, 2));
                        break;
                }
                case "/":
                {
                    try
                    {
                        Console.WriteLine(Math.Round(operand1 / operand2, 2));
                    }
                    catch (DivideByZeroException)
                    {
                        Console.WriteLine("На ноль не делим!");
                    }
                    break;
                }
                default:
                {
                    Console.WriteLine("Неправильный ввод:"); 
                    goto link1;
                    break;
                }
            }
            Console.ReadKey();
        }
    }
}
