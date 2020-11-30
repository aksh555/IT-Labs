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

def op(s):
    print(s)
    # f.write(s)

def main():
    p = input("Enter the probability of recovery (p): ")
    val_list = input(
        "Enter total no. who contracted (N) and min no. who survive (M): ")
    val = []
    try:
        op(f"N, M values: {val_list}\np: {p}")
        for x in val_list.split(", "):
            val.append(int(x))
        p = float(p)
        if p < 0 or p > 1:
            op("\nInvalid p value!")
            exit(0)
        N, M = val[0], val[1]
        if N <= 0 or M <= 0 or M > N:
            raise ValueError
    except ValueError:
        op("\nInvalid input!")
        exit(0)
    q = 1 - p
    op(f"q: {q}\n\nProbability of k people surviving is P(x=k) = C({N},k) * {p}^k * {q}^({N}-k)")
    calc = ""
    val = 0

    for i in range(M, N+1):
        t1 = nCr(N, i)
        t2 = (p**i)
        t3 = (q**(N-i))
        val += t1*t2*t3
        if(i != N):
            calc += f"P(x={i}) + "
        else:
            calc += f"P(x={i})"
    op(f"Probability of atleast {M} people surviving is: {calc}\nProbability = {val}")

if __name__ == "__main__":
    main()
