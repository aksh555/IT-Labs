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

def main(f):
    val_list = input("Enter number of oranges, apples, bananas in sack (comma separated): ")
    sample = input("Enter number of items selected: ")
    val = []
    try:
        op(f, f"Orange, Apple, Banana values: {val_list}\nSample value: {sample}")
        for x in val_list.split(", "):
            val.append(int(x))
        sample = int(sample)
        if sample<0 or sample > sum(val):
            op(f, "\nInvalid sample value!")
            exit(0)
        O, A, B = val[0], val[1], val[2]
        if O<0 or A<0 or B<0:
            raise ValueError

    except ValueError:
        op(f, "\nInvalid input!")
        exit(0)

    tot = O + A + B
    tot_ways = nCr(tot, sample)
    op(f, f"""\nNo. of ways of choosing X oranges, Y apples in the sample is = C({O},X)*C({A},Y)*C({B},{sample}-X-Y)
No. of ways of choosing sample = C({tot},{sample}) = {tot_ways}
f(X,Y) = (C({O},X)*C({A},Y)*C({B},{sample}-X-Y))/C({tot},{sample})\n""")

    f_val = {}
    for x in range(O+1):
        for y in range(A+1):
            f_val[str(x)+","+str(y)] = nCr(O, x) * \
                nCr(A, y)*nCr(B, sample-x-y)/tot_ways
    for i in f_val:
        if f_val[i] > 1:
            op(f, f"\n Invalid! f({i}): "+str(f_val[i])+" is greater than 1!")
            return
        print(f"f({i}) = {str(f_val[i])}")
        f.write(f"f({i}) = {str(f_val[i])}\n")

    e = 0
    Mx = 0
    My = 0
    in_step = ""
    mean_x = ""
    mean_y = ""
    for i in f_val:
        xy = i.split(",")
        x = int(xy[0])
        y = int(xy[1])
        ir = x*y*f_val[i]
        Mx += x*f_val[i]
        My += y*f_val[i]
        if in_step:
            in_step += " + "+str(x)+"*"+str(y)+"*"+str(f_val[i])
            mean_x += " + "+str(x)+"*"+str(f_val[i])
            mean_y += " + "+str(y)+"*"+str(f_val[i])
        else:
            in_step += str(x)+"*"+str(y)+"*"+str(f_val[i])
            mean_x += str(x)+"*"+str(f_val[i])
            mean_y += str(y)+"*"+str(f_val[i])
        e += ir

    op(f, f"""\nE(XY) = {in_step}
E(XY) = {e}
Expected value of X = {mean_x}
μX = {Mx}
Expected value of Y = {mean_y}
μY = {My}
\nCovariance of X,Y = E(X,Y) - μX*μY = {e - (Mx*My)}""")

if __name__ == "__main__":
    f = open('181IT132_IT302_P6_Output_TC6.txt', 'a')
    main(f)