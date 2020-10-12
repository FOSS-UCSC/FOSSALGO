using System;
using System.Diagnostics;

namespace BubbleSort
{
    public class BubbleSort
    {
        public static int[] GetBubbleSortedArray(int[] array)
        {
            int temp;
            for (int i = 0; i < array.Length; i++)
            {
                for (int j = 0; j < array.Length - 1; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        temp = array[j + 1];
                        array[j + 1] = array[j];
                        array[j] = temp;
                    }
                }
            }

            return array;
        }

        public static void Main()
        {
            var array = new int[] { 2, 3, 0, 4, 1, 9, 6, 8, 5, 7 };

            Console.WriteLine("Initial array:");
            foreach (var element in array)
                Console.Write(element + " ");

            var stopwatch = new Stopwatch();
            stopwatch.Start();

            var sortedArray = GetBubbleSortedArray(array);

            stopwatch.Stop();

            Console.WriteLine(Environment.NewLine + "Sorted array:");
            foreach (var element in sortedArray)
                Console.Write(element + " ");

            Console.WriteLine(Environment.NewLine + "Sorting time (ms): " + stopwatch.ElapsedMilliseconds);
        }
    }
}
