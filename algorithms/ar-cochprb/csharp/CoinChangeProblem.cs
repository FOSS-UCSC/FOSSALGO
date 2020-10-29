using System;

public static class CoinChange
{
    public static int DoCoinChangeWithDynamicProgramming(int[] coins, int totalAmount)
    {
        // This array will finally contain the number of possibilities for an amount i at index i.
        var possibilities = new int[totalAmount + 1];

        // For an amount of 0 there is only one possibility:
        // Take no coin at all.
        possibilities[0] = 1;

        // Taking one coin at a time brings new possibilities for certain amounts.
        foreach (int coin in coins)
        {
            // In fact only for those amounts greater or equal to the coin itself.
            for (int amount = coin; amount <= totalAmount; amount++)
            {
                possibilities[amount] += possibilities[amount - coin];
            }
        }

        return possibilities[totalAmount];
    }

    public static void Main()
    {
        // var coins = new [] {1,2};
        // var amount = 3;
        // // => possibilites = 2;

        var coins = new [] {6,2,3};
        var amount = 8;
        // => possibilites = 3;
        
        int possibilities = DoCoinChangeWithDynamicProgramming(coins, amount);
        
        // Print the value here
        // Console.WriteLine($"There are {possibilities} possibilities");
    }
}