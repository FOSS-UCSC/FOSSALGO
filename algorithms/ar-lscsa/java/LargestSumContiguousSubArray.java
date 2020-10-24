
public class LargestSumContiguousSubArray{

    public static int largestSumContiguousSubArray(int[] array){
        int arraySize = array.length;
        int maxValue = Integer.MIN_VALUE;
        int endValue=0;
        for(int i=0; i<arraySize; i++){
            endValue += array[i];
            if(endValue>maxValue) maxValue = endValue;
            if(endValue<0) endValue = 0;
        }
        return maxValue;
    }

    public static void main(String[] args){
        int[] testArray = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int largestSum = largestSumContiguousSubArray(testArray);
        System.out.println(largestSum);
    }
}