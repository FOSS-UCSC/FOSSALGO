// Heap Sort Typescript Implementation

/**
 *  Helper function to heapify the tree
 */
function heapify(collection: Array<number>, length: number, index: number): void {
    
    let rootNode: number = index; // root node location initialization
    const leftChild: number = index*2 + 1; // left child location  initialization based on root
    const rightChild: number = index*2 + 2; // right child location initialization based on root

    // if value of left child is greater than the root node
    if (leftChild < length && collection[leftChild] > collection[rootNode]) {
        rootNode = leftChild;
    }

    // if value of right child is greater than the root node
    if (rightChild < length && collection[rightChild] > collection[rootNode]) {
            rootNode = rightChild;
    }

    // if root node is not the index
    if (rootNode !== index){
        // swap the values
        const temp: number = collection[rootNode];
        collection[rootNode] = collection[index];
        collection[index] = temp;
        // Recursively sort the sub-tree
        heapify(collection, length, rootNode);
    }

}  

/**
 *  Main function to call for heap sort
 * @param collection Array of numbers
 */
function heapSort(collection: Array<number>): void {
    // Build heap by rearranging elements 
    for (let i = collection.length / 2; i >= 0; --i) {
         heapify(collection, collection.length, i);
    }
    // Iterate through the elements of heap
    for (let i = collection.length - 1; i >= 0; --i) {
        // swap current node with the leaf node
        const temp = collection[0];
        collection[0] = collection[i];
        collection[i] = temp;
        
        // heapify the sub-tree
        heapify(collection, i, 0);
    }

}

// Driver program

function main() {
  const sample: Array<number> = [12, 11, 13, 5, 6, 7];
  heapSort(sample);
}

main();
