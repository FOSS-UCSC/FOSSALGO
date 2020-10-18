using System;

public static class HeapSort
{
    private static int GetLeftChild(int node)
    {
        return 2 * node + 1;
    }

    private static int GetRightChild(int node)
    {
        return 2 * node + 2;
    }

    private static bool HasLeftChild(int node, int heapSize)
    {
        return GetLeftChild(node) < heapSize;
    }

    private static bool HasRightChild(int node, int heapSize)
    {
        return GetRightChild(node) < heapSize;
    }

    private static void SwapValues(int node1, int node2,
        int[] heap)
    {
        int temp = heap[node2];
        heap[node2] = heap[node1];
        heap[node1] = temp;
    }
    
    private static void BuildMaxHeap(int node,
        int heapSize, int[] heap)
    {
        if (HasLeftChild(node, heapSize))
        {
            int maxChild = GetLeftChild(node);
            int maxValue = heap[maxChild];

            if (HasRightChild(node, heapSize))
            {
                int rightChild = GetRightChild(node);
                int rightValue = heap[rightChild];

                if (rightValue > maxValue)
                {
                    maxChild = rightChild;
                    maxValue = rightValue;
                }
            }

            int nodeValue = heap[node];
            if (nodeValue < maxValue)
            {
                SwapValues(node, maxChild, heap);
                BuildMaxHeap(maxChild, heapSize, heap);
            }
        }
    }

    public static void DoHeapSort(int[] a)
    {
        int[] heap = a;
        int heapSize = heap.Length;
        int root = 0;

        for (int node = heapSize / 2 - 1; node >= root; node--)
        {
            BuildMaxHeap(node, heapSize, heap);
        }

        for (int index = a.Length - 1; index >= 0; index--)
        {
            SwapValues(root, index, heap);

            heapSize = index;
            BuildMaxHeap(root, heapSize, heap);
        }
    }
}