def insertion_sort(list1):
    i=1
    while i < len(list1):
        item_to_insert=list1[i]
        j=i-1
        #print("old index",i, "   New index",j,"element",item_to_insert,)
        while j >=0:
            if item_to_insert < list1[j]:
                list1[j+1]=list1[j]
                #print(list1)
                j =j-1
            else:
                break
        list1[j+1]=item_to_insert       
        #print(list1)
        
        i += 1
    return (list1)


'''If u want to see how this(insertion_sort) work remove the # mark & run the program'''

a=[15,6,7,8,3,8]


print(insertion_sort(a))
