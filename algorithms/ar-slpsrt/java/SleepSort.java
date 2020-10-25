import java.util.Arrays;
import java.util.List;
import java.util.concurrent.CountDownLatch;

/**
 * Java class which provides the implementation of sleep sort.
 */
public class SleepSort {

    /**
     * Method which executes the sleep sort algorithm
     * by sorting an unsorted list of integers.
     *
     * @param unsortedIntegerList The unsorted list of integers.
     */
    private static void sleepSort(List<Integer> unsortedIntegerList) {

        final CountDownLatch countDownLatch = new CountDownLatch(unsortedIntegerList.size());

        for (final Integer element : unsortedIntegerList) {

            new Thread(() -> {
                countDownLatch.countDown();
                try {
                    countDownLatch.await();
                    /*
                    Using only milli seconds will not provide good results so it is
                    multiplied with the value. Increasing the value 2 will provided
                    better results for larger lists
                    */
                    Thread.sleep(element * 2);
                    // Print the elements as they get sorted.
                    System.out.println(element);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }).start();
        }
    }

    public static void main(String[] args) {

        List<Integer> unsortedIntegerList = Arrays.asList(10, 5, 2, 5, 0, 300, 1, 6);
        sleepSort(unsortedIntegerList);
    }
}
