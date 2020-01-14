using System;

namespace CalculatorApp
{
    class Program
    {
        static void Add(float firstNum, float secondNum)
        {
            Console.WriteLine(firstNum + secondNum);
        }

        static void Sub(float firstNum, float secondNum)
        {
            Console.WriteLine(firstNum - secondNum);
        }

        static void Div(float firstNum, float secondNum)
        {
            if (secondNum == 0)
            {
                Console.WriteLine("Division by zero");
            }
            else
            {
                Console.WriteLine(firstNum / secondNum);
            }
        }
        
        static void Mul(float firstNum, float secondNum)
        {
            Console.WriteLine(firstNum * secondNum);
        }
        static float Input()
        {
            float Num;
            while (!float.TryParse(Console.ReadLine(), out Num))
            {
                Console.WriteLine("Error!Enter number");
            }
            return Num;
        }

       static void Main(string[] args)
       { 
           float firstNum, secondNum;
           bool flag = true;
           do
           {
               Console.WriteLine("Enter first number: ");
               firstNum = Input();
               Console.WriteLine("Enter second number: ");
               secondNum = Input();
               Console.WriteLine("Enter the arithmetic operation: + - * /. Or input anything else to exit.");
               string sign = Console.ReadLine();
               switch (sign)
               {
                    case "+": Add(firstNum, secondNum); break;
                    case "-": Sub(firstNum, secondNum); break;
                    case "*": Mul(firstNum, secondNum); break;
                    case "/": Div(firstNum, secondNum); break;
                    default: flag = false; break;
               }
           } while (flag);
       }
    }
}