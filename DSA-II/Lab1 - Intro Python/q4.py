def bub(lis):
	n = len(lis)
	for i in range(n):
		for j in range(n-i-1):
			if(lis[j] > lis[j+1]):
				lis[j],lis[j+1] = lis[j+1],lis[j]
	print(lis)

def sel(lis):
	n = len(lis)
	for i in range(n):
		for j in range(i+1, n):
			if(lis[i] > lis[j]):
				lis[i],lis[j] = lis[j],lis[i]
	print(lis)

def main():
	n = int(input())
	lis = [int(input()) for i in range(n)]
	print("Original List: " + str(lis))

	print("Bubble Sort")
	bub(lis)
	print("Selection Sort")
	sel(lis)

main()


