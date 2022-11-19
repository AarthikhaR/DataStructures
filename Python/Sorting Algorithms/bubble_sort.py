n = int(input("Size of array = "))
arr = []
for i in range(0,n):
    ele = int(input())
    arr.append(ele)
print("Array before sorting ")
print(arr)
for i in range(0,n):
    for j in range(0,n-i-1):
        if(arr[j] > arr[j+1]):
            t = arr[j]
            arr[j]=arr[j+1]
            arr[j+1]=t
print("Array after sorting ")
print(arr)