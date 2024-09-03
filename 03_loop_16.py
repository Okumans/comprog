print("."*((n:=int(input()))-1)+"*\n"+"".join("."*(n-1-i)+"*"+"."*(i*2-1)+"*\n"for i in range(1,n-1))+(n*2-1)*"*")
