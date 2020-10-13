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
        int leftIndex = left;
        int rightIndex = right;

        while (leftIndex <= rightIndex) {
            while (arr[leftIndex] < pivot) {
                leftIndex++;
            }
            while (arr[rightIndex] > pivot) {
                rightIndex--;
            }
            if (leftIndex <= rightIndex) {
                int temp = arr[leftIndex];
                arr[leftIndex] = arr[rightIndex];
                arr[rightIndex] = temp;
                leftIndex++;
                rightIndex--;
            }
        }
        return leftIndex;
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
