## How to contribute an implementation (code/documentation)?

*   Have a look at open issues. They contain the list of algorithms/DS we plan to be implemented. Pick an unassigned issue.
*   You can also create a new issue for an algorithm that is not in the list.
*   Make sure you are **assigned** for the issue.
*   Code the algorithm/DS following the style guide defined below.
*   Send a PR. 
*   Be sure to not include any compiled binaries in the patch.
*   While sending a PR make sure you follow **one issue per PR** rule.

<a name="sa"></a>

## Suggesting an algorithm / DS

*   First make sure you are not suggesting a duplicate.
*   If not, proceed and create the issue. Make sure, you specify only one language in an issue. Create multiple 
issues for different languages.
*   Title of issue should be of the following format -
    ```
        [Algorithm/DS Name] in [Language]
    ```
    eg:- Binary Sort in Java
*   Please try to include at least one external link for the algorithm/DS in the issue's body for each issue. The link 
should explain the algorithm/problem/DS in detail.

<a name="cs"></a>

## Code Style Guide

*   All the implementations should be independent and don't use global variables.
*   You can't create new folders. But you can create new files with the **correct naming convention**.
    1. UpperCamel/Pascal Notation -> Java, C#
        ```
       eg:- BubbleSort.java
        ```
    2. Simple-case letters & Underscore -> C, CPP, JavaScript, TypeScript, Golang, Python2, Python3
        ```
       eg:- bubble_sort.c
        ```
*   Use meaningful variable, method and function names and comments.
*   Should pass all the **build and validation checks** for the acceptance of your implementation.
*   No profanity.
*   Use external libraries only when no other solution is possible/plausible.
*   We have defined [skeleton codes](#samples) for some popular languages below. Please follow them whenever possible.

<a name="improving"></a>

## Improving an implementation

*   If you feel you can improve upon an implementation, feel free to open an issue discussing the improvements.

<a name="samples"></a>

## Samples

**C**

```c
void quicksort(int ar_size, int *ar) {
    /*
        Your implementation here...
    */
}

int main() {
	int ar_size = 4, i;
	int a[4] = {2, 3, 0, 4};
	quicksort(ar_size, a);

	for (i=0; i<ar_size; i++){
		printf("%d\n", a[i]);
	}
	return 0;
}
```

**Python**

```python
def quicksort(arr):
    #
    # Your implementation here...
    #


def main():
    arr = [2, 3, 0, 4]
    sorted_arr = quicksort(arr)
    print(sorted_arr)

    
if __name__ == '__main__':
    main()
```

**Java**

```java
public class QuickSort {
    
    static void quickSort(int[] a) {
        /*
            Your implementation here...
        */
    }
    
    public static void main(String[] args) {
        int[] arr = new int[] {2, 3, 0, 4};
        quickSort(arr);
        for(int element: arr) {
            System.out.println(element);
        }
    }
}
```

**Golang**

```go
package main

import "fmt"

// QuickSort sorts an array using QuickSort algorithm
func QuickSort(array []int) []int {
    // Your implementation here
    return array
}

func main() {
    array := []int{2, 3, 0, 4}
    sortedArray := QuickSort(array)
    fmt.Println(sortedArray)
}
```

**JavaScript**

```JavaScript
function quickSort (arr) {
	/*
	Your implementation here
	*/
}

function main () {
	let input = [2, 3, 0, 4];
	quickSort(input);
	for (let x in input) {
        // relevant implementations
	}
}

main();
```

**C#**

```csharp
using System;

public class QuickSort
{  
    public static void DoQuickSort(int[] a)
    {
        /*
            Your implementation here...
        */
    }
    
    public static void Main()
    {
        int[] arr = new int[] {2, 3, 0, 4};
        DoQuickSort(arr);
        foreach(int element in arr)
        {
            Console.Write(element + " ");
        }
        Console.WriteLine("");
    }
}
```
**cpp**
```cpp
#include <iostream>
using namespace std;
// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}
void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}
// Driver code
int main() {
  int data[] = {9, 5, 1, 4, 3};
  int size = sizeof(data) / sizeof(data[0]);
  insertionSort(data, size);
  cout << "Sorted array in ascending order:\n";
  printArray(data, size);
}
```