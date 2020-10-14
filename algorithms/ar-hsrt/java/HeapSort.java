public class HeapSort {

    public void sort(int arr[]){

        int n = arr.length;

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        for (int i=n-1; i>0; i--){

            int temp_element = arr[0];
            arr[0] = arr[i];
            arr[i] = temp_element;

            heapify(arr, i, 0);
        }
    }

    void heapify(int arr[], int n, int i){

        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            heapify(arr, n, largest);
        }
    }

    public static void main(String args[]){
        int input[] = {15, 2, 8, 9, 0, 1, 12, 22};
        int n = input.length;

        HeapSort ob = new HeapSort();
        ob.sort(input);

        System.out.println("Sorted array is");

        for (int i=0; i<n; ++i) {
            System.out.print(input[i] + " ");
        }
    }
}