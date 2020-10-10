import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
  public void binSort(float[] arr, int n) {
    if (n <= 0)
      return;
    
    ArrayList<Float>[] bin = new ArrayList[n];

    
    for (int i = 0; i < n; i++)
      bin[i] = new ArrayList<Float>();

    for (int i = 0; i < n; i++) {
      int binIndex = (int) arr[i] * n;
      bin[binIndex].add(arr[i]);
    }

    
    for (int i = 0; i < n; i++) {
      Collections.sort((bin[i]));
    }

    
    int index = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0, size = bin[i].size(); j < size; j++) {
        arr[index++] = bin[i].get(j);
      }
    }
  }

  
  public static void main(String[] args) {
    Main b = new Main();  
    Scanner sc= new Scanner(System.in);
    System.out.println("Enter the no. of numbers");
    int n= sc.nextInt();
    float[] arr = new float[n];
    for(int i=0;i<n;i++)
    {   System.out.println("Enter the number");
        arr[i]=sc.nextFloat();
    }
    b.binSort(arr, n);

    for (float i : arr)
      System.out.print(i + "  ");
  }
}