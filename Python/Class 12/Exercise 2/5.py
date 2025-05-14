def Rotate_Lst(Arr,n):
    n%=len(Arr)
    Arr=Arr[-n:]+Arr[:-n]
    return Arr

