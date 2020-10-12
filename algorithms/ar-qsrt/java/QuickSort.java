public class QuickSort {

    public static void sort(int[] arr) {
        if (arr == null || arr.length == 0) return;

        quicksort(0, arr.length - 1, arr);
    }

    private static void quicksort(int left, int right, int[] arr) {
        if (left >= right) return;

        int mid = (left + right) / 2;
        int pivot = arr[mid];

        int partitionIndex = partition(left, right, pivot, arr);
        quicksort(left, partitionIndex - 1, arr);
        quicksort(partitionIndex, right, arr);
    }

    private static int partition(int left, int right, int pivot, int[] arr) {
        while (left <= right) {
            while (arr[left] < pivot) {
                left++;
            }
            while (arr[right] > pivot) {
                right--;
            }
            if (left <= right) {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        }
        return left;
    }

    public static void main(String[] args) {
        int[] input = {15, 2, 8, 9, 0, 1, 12, 22};

        System.out.print("Pre-sort: ");
        for (int i: input) {
            System.out.format("%d ",i);
        }
        
        QuickSort.sort(input);

        System.out.print("Post-sort: ");
        for (int i: input) {
            System.out.format("%d ",i);
        }
    }
    
}
