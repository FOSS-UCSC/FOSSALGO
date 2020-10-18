def insertion_sort(array):
    if not array or len(array) == 1: return array # the inputted array has nothing inside or has one element

    sorted_list = []
    for item in array: # looping through the main array
        # iterating through the list and comparing each item
        for i in sorted_list: # comparing every item in the sorted_list
            if item < i:
                sorted_list.insert(sorted_list.index(i), item) # inserting item into sorted_list because it is less than the item
                break
        else:
            sorted_list.append(item) # nothing was inserted, therefore, item is greather than anything in sorted_list

    return sorted_list


def main():
    a = [5, 2, 4, 3, 0, 6, 7, 8, 11]
    print(insertion_sort(a))

if __name__ == "__main__":
    main()
