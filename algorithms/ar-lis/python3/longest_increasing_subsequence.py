def find_longest_increasing_subsequence(arr):
    """
    Longest increasing subsequence is the subsequence that has the longest streak of going up consecutively
    :param arr: the sequence to search for longest subsequence
    :return: the longest subsequence found in the sequence arr provided
    """
    longest_found = 0
    position_start = 0
    for i in range(len(arr) - 1):
        temp_length = 0
        is_increasing = True
        while is_increasing:
            if arr[i + temp_length] < arr[i + temp_length + 1]:
                # for consecutive elements, a & b, if a < b, then the sequence is increasing
                temp_length += 1
            else:
                is_increasing = False
        if temp_length >= longest_found:
            longest_found = temp_length + 1  # plus one to include the element arr[i]
            position_start = i
    longest_increasing_subsequence = arr[position_start:position_start + longest_found]

    print("Original sequence: ", arr)
    print("Longest increasing subsequence has length", longest_found)
    print("Longest increasing subsequence starts at position", position_start)
    print("Longest increasing subsequence: ", longest_increasing_subsequence)

    return longest_increasing_subsequence


def main():
    arr = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8, 3, 2, 7, 9, 5, 0, 2, 8, 8,
           4, 1, 9, 7, 1, 6, 9, 3, 9, 9]
    longest_increasing_subsequence = find_longest_increasing_subsequence(arr)
    print(longest_increasing_subsequence)


if __name__ == '__main__':
    main()
