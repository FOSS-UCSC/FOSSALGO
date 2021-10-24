def linear_search(arr, value):
    """
    :param arr: array/list to search a value in
    :param value: value to be searched in the array/list
    :return: index -> returns -1 if value not found else return the index of the first occurrence of the value in arr
    """
    for index, item in enumerate(arr):
        if item == value:
            return index

    return -1


def main():
    arr = [2, 3, 0, 4]
    val = 3
    index = linear_search(arr, val)
    print index


if __name__ == '__main__':
    main()
