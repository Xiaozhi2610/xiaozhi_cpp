using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    abstract class Base
    { 
        internal Base() 
        {
            Console.WriteLine("Base gouzahohanshu");
        }
        internal abstract int Com();        
    }

    class Add : Base
    {
        
    }
}




namespace CSharpLearning

{
    using Test; 

    internal class Program
    {
        static void Main(string[] args)
        {   Base bas = new Base();

            bas.Test();

            Console.WriteLine(bas.MyId());
            Console.ReadKey();
        }


    }
}
