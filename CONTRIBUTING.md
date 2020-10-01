## How to contribute an implementation (code)?

*   Have a look at open issues. They contain the list of algorithms/DS we plan to be implemented. Pick an unassigned issue.
*   You can also create a new issue for an algorithm that is not in the list.
*   Make sure you are assigned for the issue.
*   Code the algorithm/DS following the styleguide defined below.
*   Send a PR. 
*   Be sure to not include any compiled binaries in the patch.
*   While sending a PR make sure you follow one issue per PR rule.
*   If Everything fine, you will be able to merge the PR yourself too.

<a name="sa"></a>

## Suggesting an algorithm / DS

*   First make sure you are not suggesting a duplicate.
*   If not, proceed and create the issue. Make sure that you specify only one language in an issue. Create multiple issues for different languages.
*   Title of issue should be of the following format -
    ```
        Algorithm/DS Name [Language]
    ```
*   Please include at least one external link for the algorithm/DS in the issue's body for each issue. The link should explain the algorithm/problem/DS in detail.

<a name="cs"></a>

## Code Style Guide

*   Code submitted should be modular. 
*   Don't use global variables.
*   Use separate folders for each concept. Folder name should be in full lowercase. If the algorithm/DS name has multiple words, separate them by underscores. (eg `longest_common_subsequence`)
*   Filename should be derived from the folder name. (eg `longest_common_subsequence` becomes `longestCommonSubsequence.c` or `LongestCommonSubsequence.java`)
*   Name of master function of the code should be kept same as filename to the best extent possible.
*   Prefer classes instead of multiple helper functions (where applicable).
*   Currently we are accepting contributions in C, C++, C#, Java, Python, Go and JavaScript but other languages may be considered after a discussion.
*   Define `tester` code only in `main` routine.
*   Use meaningful variable, method and function names and comments.
*   No profanity.
*   Use external libraries only when no other solution is possible/plausible.
*   We have defined [skeleton codes](#samples) for some popular languages below. Please follow them whenever possible.

<a name="naming-conventions"></a>

## File and folder naming conventions

For folder naming, we are using a simple-coded mechanism. Contributors are not allowed to create new folders. 
In the coding mechanism for algorithms contains two parts for a name, which are,

1.  The related data structure for the algorithm, 
2.  The name of the algorithm. 

You can see the coded definitions from the below list.

| Coded-Name | Related Data Structure | Category         | Algorithm                      |
| :---       | :---                   | :---             | :---                           |
| `ar-lsrh`  | array                  | searching        | linear search                  |
| `ar-bsrh`  | array                  | searching        | binary search                  |
| `gr-bfsrh` | graph/tree             | searching        | breadth first search           |
| `ar-bsrt`  | array                  | sorting          | bubble sort                    |
| `ar-hsrt`  | array                  | sorting          | heap sort                      |
| `ar-isrt`  | array                  | sorting          | insertion sort                 |
| `ar-ssrt`  | array                  | sorting          | selection sort                 |
| `ar-shsrt` | array                  | sorting          | shell sort                     |
| `ar-msrt`  | array                  | sorting          | merge sort                     |
| `ar-nsrh`  | array                  | pattern matching | naive pattern search           |
| `ar-kmp`   | array                  | pattern matching | knuth–morris–pratt             |
| `ar-lis`   | array                  | pattern matching | longest increasing subsequence |
| `ar-lcs`   | array                  | pattern matching | longest common subsequence     |
| `ar-knn`   | array                  | classification   | k-nearest neighbors            |

For data structure folder naming is as bellow.

| Coded-Name    | Data Structure     |
| :---          | :---               |
| `ds-stk`      | stack              |
| `ds-que`      | queue              |
| `ds-cque`     | circular queue     |
| `ds-slinklst` | singly liked-list  |
| `ds-dlinklst` | doubly linked-list |
| `ds-btree`    | binary tree        |

Due to we are dealing with multiple programming languages we can't depend on a specific file naming convention.
You have to strictly follow the below naming convention types according to the relevant language. For maintaining the consistancy, numbers are not allowed to use in file names.

*   **Upper-Camel Case (eg:- FileName.abc) ->** *Java*
*   **Simple cases & underscore (eg:- FileName.abc) ->** *C, C++*

<a name="points"></a>

## Standalone points

*   In some cases, C and C++ implementation will be similar. In that case, only the C implementation must be done.

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
		console.log(input[x] + ' ');
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
