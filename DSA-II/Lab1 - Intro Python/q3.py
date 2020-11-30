import math
def main():
	flag = 0
	n = int(input())
	for i in range(2,int(math.sqrt(n))+1):
		if(n%i == 0):
			flag = 1
	if(flag):
		print(str(n)+" is not prime")
	else:
		print(str(n)+" is prime")

main()