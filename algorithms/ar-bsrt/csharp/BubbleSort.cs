using System;
using System.Diagnostics;

namespace BubbleSort
{
    public static class BubbleSort
    {
        public static void DoBubbleSortArray(int[] array)
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
        }

        public static void Main()
        {
            var array = new [] { 2, 3, 0, 4, 1, 9, 6, 8, 5, 7 };
            DoBubbleSortArray(array);
        }
    }
}