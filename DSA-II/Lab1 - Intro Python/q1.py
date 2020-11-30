def fact_iter(n):
	fact = 1
	for i in range(1,n+1):
		fact*=i
	return fact

def fact_rec(n):
 	while(n>0):
	 	if (n <= 1):
	 		return 1
	 	return n*fact_rec(n-1)

def main():
	n = int(input())
	print("Iterative: " + str(fact_iter(n)))
	print("Recursive: " + str(fact_rec(n)))

main()


