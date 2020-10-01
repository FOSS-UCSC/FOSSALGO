def binary_search(item_list, item):
    first = 0
    last = len(item_list) - 1
    found = False
    while first <= last and not found:
        mid = (first + last) // 2
        if item_list[mid] == item:
            found = True
        else:
            if item < item_list[mid]:
                last = mid - 1
            else:
                first = mid + 1
    return found


# This code will simply binary search for the given search element and if it is found it will display 'True'
# and of doesn't 'False'. For Example:

print(binary_search([1, 2, 3, 5, 8], 6))
print("")
print(binary_search([1, 2, 3, 5, 8], 5))
print("")
print(binary_search([13, 46, 675, 464, 54, 6, 7, 8, 645, 43, 22, 45, 6, 5], 5))
print("")
print(binary_search([13, 46, 675, 464, 54, 6, 7, 8, 645, 43, 22, 45, 6, 5], 100))
