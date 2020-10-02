public class BinarySearch {

    public static void sort(int arr[], int n) {
        int i;
        int j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - 1; j++) {
                if (arr[j] >= arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public static int binarySearch(int arr[], int low, int high, int searchVal) {
        if (low > high) {
            System.out.println("Search is finished. Value not found");
            return -1;
        }
        int mid = (low + high) / 2;
        if (searchVal == arr[mid]) {
            System.out.println("Search is finished. Index is " + mid);
            return mid;
        } else if (searchVal >= arr[mid]) {
            low = mid + 1;
            return binarySearch(arr, low, high, searchVal);
        } else {
            high = mid - 1;
            return binarySearch(arr, low, high, searchVal);
        }
    }

    public static void main(String[] args) {
        int arr[] = {4, 5, 1, 10, 2, 7, 6, 3};
        sort(arr, arr.length);
        int low = 0;
        binarySearch(arr, low, arr.length - 1, 7);
        binarySearch(arr, low, arr.length - 1, 8);
    }

}
