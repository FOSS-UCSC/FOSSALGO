using System;
using System.Collections.Generic;

public static class BinSort{

    //This function will pass in an array of float type, in the size of n.
    public static void DoBinSort(float[] arr, int n){ 
        if(n > 0){	
			//Create empty bins to the size of n.
			List<float>[] bins = new List<float>[n];
			for (int i = 0; i < n; i++){
				bins[i] = new List<float>();
			}
			

			//Insert existing array elements into the empty bins.
			int index;
			for (int i = 0; i < n; i++) {
				index = (int)(arr[i] * n);
				bins[index].Add(arr[i]);
			}

			//Sort the array in order
			for (int i = 0; i < n; i++) {
				bins[i].Sort();
			}
			
			// Get the sorted array
            index = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < bins[i].Count; j++) {
                    arr[index++] = bins[i][j];
                }
            }
		}
		else{
            //End the function if the array is empty.
			return;
		}
    }

    public static void Main(){
        float[] arr = new float[] {0.102F, 0.212F, 0.442F, 0.661F, 0.232F, 0.157F, 0.341F};
        DoBinSort(arr, (arr.Length));
        foreach(float element in arr)
        {
            Console.Write(element + " ");
        }
        Console.WriteLine("");
    }

}