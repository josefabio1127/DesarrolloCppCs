using System;
using System.Collections.Generic;

namespace Ejercicio8
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<float> scores = new List<float>();
            while (true)
            {
                float score = 0;
                string score_str = "";
                Console.WriteLine("Type the score: ");
                score_str = Console.ReadLine();
                score = Convert.ToInt32(score_str);
                if (score < 0 || score > 100)
                {
                    break;
                }
                else
                {
                    scores.Add(score);
                }
            }
            float suma = 0;
            float max = 0;
            float min = 100;
            for(int i = 0; i < scores.Count; i++)
            {
                suma+= scores[i];
                if (scores[i]<min)
                {
                    min = scores[i];
                }
                if (scores[i]>max)
                {
                    max = scores[i];
                }
            }

            float prom = suma / scores.Count;

            string msg_average = string.Format("The average score is {0}", prom);
            string msg_max = string.Format("The maximum score is {0}", max);
            string msg_min = string.Format("The minimum score is {0}", min);
            Console.WriteLine(msg_average);
            Console.WriteLine(msg_max);
            Console.WriteLine(msg_min);
        }
    }
}