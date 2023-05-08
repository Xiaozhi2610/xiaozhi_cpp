using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace xiaozhi_c_
{
    internal class Program
    {
        static int Main(string[] args)
        {
            int age = 100;
            float age2 = 10.2f;
            System.Double a = 12.3;
            System.Double b = 12.3;
            int age3 = (int)age2;
            Consume consume = new Consume();
            consume.Record();


            Console.WriteLine(age3);
            Console.Read();
            return 0;
        }
    }


    class card
    {
        public string Money { get; set; }
    }

    class Consume
    {
        public void Record ()
        {
            Console.WriteLine("信用卡消费记录\n");
            card pCard = new card() {Money = "8000" };
            Console.WriteLine("信用卡总额度: " + pCard.Money);
            card pCard2 = pCard;
            pCard.Money = "3000";
            Console.WriteLine("信用卡消费记录: " + pCard.Money);

        }
    }



}


