public class linearSearch {

    public static final int unorderedLinearSearch(int value, int[] array) {
        for (int i = 0; i < array.length; i++) {
            int iValue = array[i];
            if (value == iValue)
                return i;
        }
        return Integer.MAX_VALUE;
    }
    
    public static final int orderedLinearSearch(int value, int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (value == array[i]){
                return i;
            }
            else if (array[i] > value){
             return -1;
            }
        }
        return Integer.MAX_VALUE;
    }
    
    public static void main(String[] args) {


      int[] integers = {1,2,3,4,5,6,7,8,8,8,9,9,9,0};
         int shouldBeFound = 9;

         int atIndex = linearSearch.unorderedLinearSearch(shouldBeFound, integers);

         System.out.println(String.format("Should be found: %d. Found %d at index %d. An array length %d"
                 , shouldBeFound, integers[atIndex], atIndex, integers.length));
         
         int[] sortedArray = {10,20,30,40,50};
         //the element that should be found
         int key = 30;
         
         atIndex = linearSearch.orderedLinearSearch(key, sortedArray);

         System.out.println(String.format("Should be found: %d. Found %d at index %d. An array length %d"
                 , key, sortedArray[atIndex], atIndex, sortedArray.length));
         
 }
}