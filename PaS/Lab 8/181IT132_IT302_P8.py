# pip install texttable

from texttable import Texttable

def nCr(n, r):
    res = 1
    if r < 0 or r > n:
        return 0
    if r > n - r:
        r = n - r
    for i in range(r):
        res *= (n - i)
        res /= (i + 1)
    return res

def op(f, s):
    print(s)
    f.write(s)

def BinomialProbSums(f):
    val_list = input("Enter n and m values: ")
    val = []
    try:
        op(f, f"n, m values: {val_list}\n")
        for x in val_list.split(", "):
            val.append(int(x))
        n, m = val[0], val[1]
        if n < 1 or m < 0 or m > n:
            raise ValueError
    except ValueError:
        op(f, "\nInvalid input!")
        exit(0)

    p_val = [x/10 for x in range(1, 10)]
    header = ["r"]
    header.extend(p_val)
    contents = [header]

    mat = dict()
    for r in range(m+1):
        mat[r] = list()
    for p in p_val:
        val = 0
        for r in range(m+1):
            x = nCr(n, r)*(p**r)*(1-p)**(n-r)
            op(f, f"b({r};{n},{p}) = {x}\n")
            val += x
            mat[r].append(val)
    for r in range(m+1):
        row = [r]
        row.extend(mat[r])
        contents.append(row)

    t = Texttable()
    t.set_cols_dtype(["a", "f", "f", "f", "f", "f", "f", "f", "f", "f"])
    t.add_rows(contents)
    op(f, f"\nBinomial Probability Sums Table\n\t\t\t\tp values\n")
    op(f, t.draw())

if __name__ == "__main__":
    f = open('181IT132_IT302_P8_Output_TC1.txt', 'a')
    BinomialProbSums(f)