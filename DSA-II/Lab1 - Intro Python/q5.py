import string

def repl(st1, st2, st3):
	rep = ""
	i = 0
	while ( i<len(st1)):
		if(st1[i] == st2[0] and i+len(st2)<len(st1)):
			if(st1[i:i+len(st2)] == st2):
				rep += st3
				if(i+len(st2) > len(st1)-1):
					break
				else:
					i+= len(st2)
		else:
			rep += st1[i]
			i += 1
	return rep


def main():
	st1 = input()
	st2 = input()
	st3 = input()
	print("Original string1: " + st1)
	print("Modified string1: " + st1.replace(st2, st3))
	
	print("Modified string: ", repl(st1, st2, st3))
	

main()
	

