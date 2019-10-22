import java.util.Scanner;
public class SelectionSort 
{
   public static void main(String args[])
   {
		Scanner sc = new Scanner(System.in);
        System.out.print("Enter the length of the array:");
		int size = sc.nextInt();
		int [] array = new int[size];
		System.out.println("Enter the elements of the array:");

		for(int i=0; i<size; i++ ) 
		{
			array[i] = sc.nextInt();
		}

		for (int i = 0 ;i< size-1; i++)
		{
			int min = i;

			for (int j = i+1; j<size; j++)
			{
				if (array[j] < array[min])
				{
					min = j;
				}
			}
			int temp = array[min];
			array[min] = array[i];
			array[i] = temp;
		}
		System.out.println("Sorted Array");
		for (int i = 0 ;i< size; i++)
		{
			System.out.print(" "+array[i]);
		}
	}  
}