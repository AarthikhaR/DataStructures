def minimum_element(A,size):
    min = A[0]
    for i in range(0,size):
        if(min > A[i]):
            min = A[i]
    return min


def maximum_element(A,size):
    max = A[0]
    for i in range(0,size):
        if(max < A[i]):
            max = A[i]
    return max
    

A = []
n = int(input("Size of array = "))
for i in range(0,n):
    ele = int(input())
    A.append(ele)
min = minimum_element(A,n)
print("Minimum element in the array = ",min)
max = maximum_element(A,n)
print("Maximum element in the array = ",max)
