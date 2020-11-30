# pip install scipy, texttable, numpy, matplotlib

import math
import numpy as np
import scipy.stats as stats
import matplotlib.pyplot as plt
from scipy.integrate import quad
from texttable import Texttable

def op(f, s):
    print(s)
    f.write(s)

def plot(a):
    pdf = stats.norm.pdf(a, 0, 1)
    plt.plot(a, pdf, "-bo")
    plt.xlabel("z scores")
    plt.ylabel("Probability")
    plt.grid(True)
    plt.title(f"Standard Normal Dist. Graph")
    plt.savefig("181IT132_IT302_P10_TC_test.png")

def cumArea(a):
    const = (2*np.pi)**(-0.5)
    y = quad(lambda x: const*np.exp((-x**2)/2), -math.inf, a)
    return y[0]

def NormalDist(f):
    val_list = input("Enter series values: ")
    val = []
    try:
        op(f, f"Series values: {val_list}\n")
        for x in val_list.split(", "):
            val.append(int(x))
            if int(x) < 0:
                raise ValueError
        n = len(val)
        if n < 1:
            raise ValueError
    except ValueError:
        op(f, "\nInvalid input!")
        exit(0)

    val.sort()
    mean = np.mean(val)
    stdev = np.std(val)
    zscores = [(i-mean)/stdev for i in val]
    op(f, f"Mean of the given series: {mean}\nStandard Deviation = sqrt(variance): {stdev}\nStandardizing using z = (x-μ)/σ\nZ values: {zscores}\n")
    a1, a2, a3, a4, a5 = cumArea(-3.49), cumArea(0),  cumArea(3.49),  cumArea(-1),  cumArea(1)
    
    t = Texttable(max_width=300)
    cols = ["a"]
    cols.extend(["f" for i in range(5)])
    contents = [["z-scores", -3.49, -1, 0, 1, 3.49],["area", a1, a4, a2, a5, a3]]
    t.set_cols_dtype(cols)
    t.add_rows(contents)

    op(f,f'''\nVerifying properties of obtained Standard Normal Dist.\n1. Cumulative area is close to 0 for z-scores close to z = −3.49
     Obtained area for z = -3.49 is {a1:.4f}\n2. Cumulative area for z = 0 is 0.5
     Obtained area for z = 0 is {a2:.4f}\n3. Cumulative area is close to 1 for z -scores close to z = 3.49
     Obtained area for z = 3.49 is {a3:.4f}\n4. Cumulative area increases as z-scores increase
\tObtained areas for increasing z-scores\n{t.draw()}\n5. Mean is {abs(np.mean(zscores)):.4f}, Standard Deviation is {np.std(zscores)}''')

    plot(zscores)

if __name__ == "__main__":
    with open('181IT132_IT302_P10_Output_TC_test.txt', "a", encoding="utf-8") as f:
        NormalDist(f)
