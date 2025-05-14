def pow(a,b):
    if b==1:
        return a
    else:
        return a*pow(a,b-1)
        
