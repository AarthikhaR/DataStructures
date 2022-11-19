n = int(input("Size of array = "))
arr = []
for i in range(0,n):
    ins = int(input())
    arr.append(ins)
print("Array before Sorting ")
print(arr)
for i in range(0,n):
    min_index = i
    for j in range(i+1,n):
        if(arr[min_index] > arr[j]):
            min_index = j
    arr[i] ,arr[min_index] = arr[min_index] , arr[i]
print("Array after Sorting ")
print(arr)