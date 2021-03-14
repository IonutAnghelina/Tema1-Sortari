#Batch 1: Sorted strings
import random

fout=open("batch1.out","w")

print(10,file=fout)


for i in range(10):
    n=random.randint(1000,10000)
    print(f"{n} {n}",file=fout);
    l=[x for x in range(1,n+1)]
    print(" ".join( [str(x) for x in sorted(l,reverse=random.randint(0,1))] ),file=fout)


fout.close()


fout=open("batch2.out","w")

print(10,file=fout)
for i in range(10):
    n=random.randint(1000,10000)
    print(f"{n} {n}",file=fout);
    l=[x for x in range(1,n+1)]



    noSwaps=random.randint(5,10)

    l.sort(reverse=random.randint(0,1))

    for j in range(noSwaps):
        x1=random.randint(0,n-1)
        x2=random.randint(0,n-1)
        l[x1],l[x2]=l[x2],l[x1]

    print(" ".join( [str(x) for x in l] ),file=fout)


fout.close()

fout=open("batch3.out","w")

print(10,file=fout)

for i in range(10):
    n=10000
    print(f"{n} {10}",file=fout)
    l=[random.randint(1,10) for j in range(n)]

    print(" ".join( [str(x) for x in l] ),file=fout)

fout.close()

fout=open("batch4.out","w")

print(10,file=fout)

for i in range(10):
    n=random.randint(1000,10000)
    print(f"{n} {10*n}",file=fout);
    l=[random.randint(0,10*n) for x in range(1,n+1)]
    print(" ".join( [str(x) for x in l] ),file=fout)


fout.close()

fout=open("batch5.out","w")

print(10,file=fout)

for i in range(10):
    n=random.randint(10000,10000)
    limit=(10**9)
    print(f"{n} {limit}",file=fout);
    l=[random.randint(0,limit) for x in range(1,n+1)]
    print(" ".join( [str(x) for x in l] ),file=fout)

