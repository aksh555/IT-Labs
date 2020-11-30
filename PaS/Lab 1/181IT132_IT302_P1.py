import math

def get_space(r):
    coordinates = []
    for x in range(r+1):
        for y in range(r+1):
            if (x**2 + y**2) < r**2:
                coordinates.append((x,y))
    
    line = "Sapce for r = " + str(r) + ": \n"
    line += ", ".join(str(point) for point in coordinates)
    write_to_file([line])

def write_to_file(lines):
    f = open('output.txt',"w")
    for line in lines:
        print(line)
        f.write(line)
    f.write("\n")
    f.close()

def main():
    r = input("Enter a 3 digit positive integral value for radius: ")
    lines = []

    try:
        r = int(r)
    except:
        lines.append(str(r) + " is not an integer! Terminating")
        write_to_file(lines)
        return 0

    if (r < 1):
        lines.append(str(r) + " is not a positive integer! Terminating")
        write_to_file(lines)
        return 0

    if (len(str(r))!=3):
        lines.append(str(r) + " is not a 3 digit integer! Terminating")
        write_to_file(lines)
        return 0

    write_to_file(lines)
    get_space(r)

if __name__ == '__main__':
    main()