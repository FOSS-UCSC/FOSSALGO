public class QuickSort
{
    
    
    static void quicksort(int arr[],int low,int high)
    {
        if(low<high)
        {
            int piviot=partition(arr,low,high);
            
            quicksort(arr,low,piviot-1);
            quicksort(arr,piviot+1,high);
        }
    }
    
    private static int partition(int arr[],int from,int to)
    {
        int piviot =arr[from];
        int left=from;
        int right=to;
        
        while(true)
        {
            while(arr[left]<piviot)
            {
                left++;
            }
            
            while(arr[right]>piviot && right>0)
            {
                right--;
            }
            if(left>=right)
            {
                break;
            }
            else
            {
            int temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            System.out.println(temp);
            }
            
        }
        
        return left;
    }

}
