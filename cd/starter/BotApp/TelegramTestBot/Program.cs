using System;
using Telegram.Bot;
namespace TelegramTestBot
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Net.ServicePointManager.SecurityProtocol = System.Net.SecurityProtocolType.Tls13;
            TelegramBotClient bot = new TelegramBotClient("1458789244:AAG8qosl8YgHH5kx1cZvKNlGl-rlGsFzkqI");
            var me = bot.GetMeAsync().Result;
            Console.WriteLine(me.Id);
            Console.ReadKey();
        }
    }
}
