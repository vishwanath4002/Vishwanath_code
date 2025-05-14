A=[10,12,15,17,20,30]
for i in range(6):
    if A[i]%2==0:
        A[i] //= 2
    elif A[i]%3==0:
        A[i] //= 3
    if A[i]%5==0:
        A[i] //= 5;
for i in range(6):
    print(A[i],end="#")
