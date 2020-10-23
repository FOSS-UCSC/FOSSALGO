using System;

public static class LargestSumContiguousSubArray
{
    public static int DoLargestSumContiguousSubArray(int[] arr)
    {
        int max = int.MinValue, maxEnd = 0;

        foreach (int num in arr)
        {
            maxEnd = maxEnd + num;

            if (max < maxEnd) {
                max = maxEnd;
            }

            if (maxEnd < 0) {
                maxEnd = 0;
            }
        }

        return max;
    }

    public static void Main()
    {
        int[] arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        DoLargestSumContiguousSubArray(arr);
    }
}
