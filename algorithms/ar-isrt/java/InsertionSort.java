class InsertionSort {
    public static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
    }

    public static void main(String args[]) {
        int arr[] = {18, 11, 15, 5, 7};

        InsertionSort ob = new InsertionSort();
        ob.sort(arr);

        printArray(arr);
    }

    public void sort(int arr[]) {
        int n = arr.length;
        int j;
        for (int i = 1; i < n; i++) {
            int key = arr[i];

            for (j = i - 1; (j >= 0 && key < arr[j]); j--)
                arr[j + 1] = arr[j];

            arr[j + 1] = key;
        }

    }
}