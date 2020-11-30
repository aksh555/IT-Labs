def fib_iter(n):
	f1 = 0
	f2 = 1
	n-=2
	print(f1)
	print(f2)
	while(n):
		f3 = f1 + f2
		n-=1
		print(f3)
		f1 = f2
		f2 = f3

def fib_rec(n):
	if(n<=1):
		return n
	else:
		return fib_rec(n-1) + fib_rec(n-2)

def main():
	n = int(input())
	print("Iterative: ")
	fib_iter(n)
	print("Recursive: ")
	for i in range(n):
		print(fib_rec(i))

main()

