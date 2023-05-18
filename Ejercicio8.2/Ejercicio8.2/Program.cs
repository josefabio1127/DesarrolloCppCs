

using static System.Formats.Asn1.AsnWriter;

namespace Ejercicio8_2
{
    internal class Program
    {
        static void Main()
        {
            int first = 0;
            int last =  0;
            int step = 0;
            string first_str = "";
            string last_str = "";
            string step_str = "";

            Console.WriteLine("Type the begining of the range: ");
            first_str = Console.ReadLine();
            first = Convert.ToInt32(first_str);

            Console.WriteLine("Type the end of the range: ");
            last_str = Console.ReadLine();
            last = Convert.ToInt32(last_str);

            Console.WriteLine("Type the step: ");
            step_str = Console.ReadLine();
            step = Convert.ToInt32(step_str);

            float celsius = 0.00f;
            Console.WriteLine("Farenheit\tCelsius");
            Console.WriteLine("-----------------------");
            while (first <= last)
            {

                celsius = (first - 32.00f) * 5.00f / 9.00f;
                Console.WriteLine("{0}\t\t{1}", first, celsius.ToString("0.00"));
                first += step;
            }
        }
    }
}