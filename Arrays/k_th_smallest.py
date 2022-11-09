n = int(input("Enter the number of elements of the array = "))
array = []
k = int(input("Enter the value of k = "))
print("Elements of the array: ")
for i in range(0,n):
    ele = int(input())
    array.append(ele)
print("Array before sorting: ")
print(array)
for i in range(0,n):
    for j in range(0,n-i-1):
        if(array[j]>array[j+1]):
            t = array[j]
            array[j]=array[j+1]
            array[j+1]=t
print("Array after sorting: ")
print(array)
print("The ", k , " th smallest element in given array is ", array[k-1])
print("The ",k ," th largest element in given array is ",array[n-k])

