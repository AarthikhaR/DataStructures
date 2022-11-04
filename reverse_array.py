def reverse_array(A,beg,end):
    while beg < end:
        A[beg],A[end] = A[end],A[beg]
        beg+=1
        end-=1


A = []
n = int(input("Enter the size of array = "))
for i in range(0,n):
    e = int(input())
    A.append(e)
print("Array before reversing : ")
print(A);
reverse_array(A,0,n-1)
print("Array after reversing :")
print(A)
