import sample
from math import pow

x,y=map(int,input('Enter two numbers : ').split())
sample.add(x,y)
sample.sub(x,y)
sample.mul(x,y)
sample.div(x,y)
print('%s**%s = %s'%(x,y,pow(x,y)))
