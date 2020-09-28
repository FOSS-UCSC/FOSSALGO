class SelectionSort {
    // Driver code to test above
    public static void main(String args[]) {
        SelectionSort ob = new SelectionSort();
        Scanner s = new Scanner(System.in);
        System.out.println("Insert array elements seperating with spaces only");

        String temp = s.nextLine();

        String ar[] = temp.split(" ");
        int arr[] = new int[ar.length];

        for (int i = 0; i < ar.length; i++) {
            arr[i] = Integer.parseInt(ar[i]);
        }

        ob.sort(arr);
        System.out.println("Sorted array");
        ob.printArray(arr);
    }

    public void sort(int arr[]) {
        int n = arr.length;

        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n - 1; i++) {
            // Find the minimum element in unsorted array
            //int min_idx = i;
            int min = arr[i];
            int index = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < min) {
                    min = arr[j];
                    index = j;
                }
            }

            // Swap the found minimum element with the first
            // element
            int temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
        }
    }

    // Prints the array
    public void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
}
