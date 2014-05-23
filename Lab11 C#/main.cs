using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using zolnierz;

namespace zolnierz
{
    class main
    {

        static void Main()
        {
            Animal animal = new Animal();


            System.Console.WriteLine("\nAnimal Age: " + animal.Age);
            System.Console.WriteLine("Animal Attack:" + animal.attack());
            //System.Console.WriteLine("\nAnimal Attack:" + animal.Rase);


            animal = new Cat(5, "Pers");
            System.Console.WriteLine("\nAnimal Age: " + animal.Age);
            System.Console.WriteLine("Animal Attack:" + animal.attack());
            System.Console.WriteLine("Animal Rase:" + ((Cat)(animal)).Rase);
            ((Cat)animal).Rase = "Aegean cat";
            System.Console.WriteLine("Animal Rase now:" + ((Cat)(animal)).Rase);


            Cat cat = new Cat((Cat)animal);
            cat.Age = 10;
            System.Console.WriteLine("\nAnimal Age: " + cat.Age);
            System.Console.WriteLine("Animal Attack:" + cat.attack());
            System.Console.WriteLine("Animal Rase:" + cat.Rase);


            System.Console.ReadKey();
        }
    }
}
