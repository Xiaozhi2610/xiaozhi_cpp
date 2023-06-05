using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace Test
{

    interface Test00
    {
        void Test01();
    }

    class Parent : Test00
    {
        public void Test01()
        {
            Console.WriteLine();
        }
    }
}




namespace CSharpLearning
{
    using Test;

    internal class Program : Test00
    {
        static void Main(string[] args)
        {
            
            Console.ReadKey();
        }

        public void Test01()
        {

        }
    }
}
