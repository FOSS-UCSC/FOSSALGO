class coinchange{ 
      
    // Returns the count of ways we can  
    // sum S[0...m-1] coins to get sum n 
   static long countWays(int S[], int m, int n) 
    { 
        //Time complexity of this function: O(mn) 
        //Space Complexity of this function: O(n) 
  
        // table[i] will be storing the number of solutions 
        // for value i. We need n+1 rows as the table is 
        // constructed in bottom up manner using the base 
        // case (n = 0) 
        long[] table = new long[n+1]; 
  
        // Initialize all table values as 0 
        Arrays.fill(table, 0);   //O(n) 
  
        // Base case (If given value is 0) 
        table[0] = 1; 
  
        // Pick all coins one by one and update the table[] 
        // values after the index greater than or equal to 
        // the value of the picked coin 
        for (int i=0; i<m; i++) 
            for (int j=S[i]; j<=n; j++) 
                table[j] += table[j-S[i]]; 
  
        return table[n]; }
      
    // Driver program to test above function 
    public static void main(String[] args) 
    { Scanner sc=new Scanner(System.in);
    int t=sc.nextInt();
    while(t-->0)
    {int m = sc.nextInt();
        int arr[] =new int[m];
        for(int i=0;i<m;i++)
        {
            arr[i]=sc.nextInt();
        }
        int k=sc.nextInt();
         
        System.out.println( countWays(arr, m, k)); 
    
        
    }
          
    } 
  
} 
