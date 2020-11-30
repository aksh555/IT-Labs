def main(f):
    n = input("Enter n value: ")
    try:
        n = int(n)
        if n <= 0:
            print("Invalid: n <= 0!\n")
            f.writelines("\nInvalid: n <= 0!")
            exit(1)

        names = dict()

        print("Enter the names of inspectors comma separated")
        name_list = []
        names_read = input()
        for name in names_read.split(", "):
            name_list.append(name)
        if len(name_list) < n:
            print("Invalid: number of names < n!")
            f.writelines('Invalid: number of names < n!')
            exit(1)

        if len(name_list) > n:
            name_list = name_list[:n]

        print("Enter the percentage of each individual who stamps the packages, comma separated")
        percentage_list = []
        percentage_read = input()
        for percentage in percentage_read.split(", "):
            percentage_list.append(percentage)
        if len(percentage_list) < n:
            print("Invalid: Number of percentages < n!")
            f.writelines("Invalid: Number of percentages < n!")
            exit(1)

        if len(percentage_list) > n:
            percentage_list = percentage_list[:n]

        sum = 0
        for i in range(n):
            sum += int(percentage_list[i])
        if sum != 100:
            print("Invalid: The total sum of percentages is not equal to 100!")
            f.writelines(
                'Invalid: The total sum of percentages is not equal to 100!')
            exit(1)

        print("Enter the No of packages where each individual misses a stamps once, comma separated")
        packages_list = []
        packages_read = input()
        for package in packages_read.split(", "):
            packages_list.append(package)

        if len(packages_list) < n:
            print("Invalid: Number of packages < n!")
            f.writelines('Invalid: Number of packages < n!')
            exit(1)

        if len(packages_list) > n:
            packages_list = packages_list[:n]

        for i in range(n):
            names[name_list[i]] = (percentage_list[i], packages_list[i])

        name = input("Enter the name whose probability should we calculate:")

        if name not in names:
            print("Invalid:The given name is not there in the list!")
            f.writelines('Invalid:The given name is not there in the list!')
            exit(1)
        numerator = int(names[name][0])/int(names[name][1])
        denominator = 0

        for name in names:
            denominator += int(names[name][0])/int(names[name][1])
        print('Probability of all: '+str(denominator))
        print('Probability of the chosen person: '+str(numerator))

        probability = numerator/denominator
        print(probability)
        f.writelines(str(probability))

    except ValueError:
        print("Invalid Input!\n")
        f.writelines("Invalid Input!\n")


if __name__ == "__main__":
    f = open('181IT132_IT302_P2_Output_TC6.txt', 'a')
    main(f)
    f.close()
