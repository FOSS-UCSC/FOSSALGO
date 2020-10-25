import java.util.Arrays;

/**
 * Java class providing the implementation of shell sort.
 */
public class ShellSort {

    /**
     * Method which executes the shell sort algorithm
     * by sorting an unsorted array of integers.
     *
     * @param unsortedArray The unsorted array of integers.
     */
    private static void shellSort(int unsortedArray[]) {

        int arrayLength = unsortedArray.length;

        for (int gap = arrayLength / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < arrayLength; i++) {
                int key = unsortedArray[i];
                int j = i;
                while (j >= gap && unsortedArray[j - gap] > key) {
                    unsortedArray[j] = unsortedArray[j - gap];
                    j -= gap;
                }
                unsortedArray[j] = key;
            }
        }
    }

    public static void main(String[] args) {

        int[] unsortedArray = {41, 15, 82, 5, 65, 19, 32, 43, 8};
        shellSort(unsortedArray);
        System.out.println("Sorted Array : " + Arrays.toString(unsortedArray));
    }
}

