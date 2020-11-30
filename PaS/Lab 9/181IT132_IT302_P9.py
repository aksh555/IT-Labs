# pip install texttable
# pip install matplotlib

import math
from texttable import Texttable
import matplotlib.pyplot as plt

def op(f, s):
    print(s)
    f.write(s)

def plot(x, y):
    # plt.ion() intercative o/p
    plt.plot(x, y[1:], "-bo")
    plt.xlabel("x values")
    plt.ylabel(f"Σp(x;μ={y[0]})")
    plt.grid(True)
    plt.title(f"Probability Sums for μ={y[0]}")
    plt.savefig("181IT132_IT302_P9_TCGx.png")

def PoissonProbSums(f):
    val_list = input("Enter n and μ values: ")
    val = []
    try:
        op(f, f"n, μ values: {val_list}\n")
        for x in val_list.split(", "):
            val.append(float(x))
        n, mean = int(val[0]), val[1]
        if n < 1 or mean < 0:
            raise ValueError
    except ValueError:
        op(f, "\nInvalid input!")
        exit(0)

    x_val = [x for x in range(n+1)]
    header = ["μ"]
    header.extend(x_val)
    contents = [header]

    row = [mean]
    val = 0
    for x in x_val:
        tval = (math.exp(-mean)*(mean**x))/math.factorial(x)
        op(f, f"p({x};{mean}) = {tval}\n")
        val += tval
        row.append(val)
    contents.append(row)

    t = Texttable(max_width=300)
    cols = ["a"]
    cols.extend(["f" for i in range(n+1)])
    t.set_cols_dtype(cols)
    t.add_rows(contents)
    op(f, f"\nPoisson Probability Sums Table\n\t\t\t\tx values\n")
    op(f, t.draw())
    plot(header[1:], row)

if __name__ == "__main__":
    with open('181IT132_IT302_P9_Output_TCx.txt', "a", encoding="utf-8") as f:
        PoissonProbSums(f)