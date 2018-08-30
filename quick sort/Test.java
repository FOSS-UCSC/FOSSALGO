public class Test{

  public static void main(String[] args)
    {
        System.out.println("hello");
        int a[]={2,5,8,7,6,8,8,9,4,5,4,7,8,1,2};
        QuickSort.quicksort(a,0,a.length-1);
        
        for(int e:a)
        {
            System.out.print(e+" ");
        }
    }
}
