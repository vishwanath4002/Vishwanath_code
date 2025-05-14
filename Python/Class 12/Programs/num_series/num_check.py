def is_perfect(n):
    s=0
    for i in range(1,n):
        if n%i==0:
            s+=i
    if s==n:
        return True
    else:
        return False

def is_palindrome(n):
    if str(n)==str(n)[::-1]:
        return True
    else:
        return False
