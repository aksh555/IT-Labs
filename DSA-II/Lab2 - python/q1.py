import math
class Fraction:
    def __init__(self,x,y):
        self.num = x
        self.den = y
    def __str__(self):
        return str(self.num)+"/"+str(self.den)
    def reduce(self):
        x = math.gcd(self.num,self.den)
        self.num/=x
        self.den/=x
    def __add__(self,frac):
        newfrac = Fraction(self.num*frac.den + self.den*frac.num,self.den*frac.den)
        newfrac.reduce()
        return newfrac
    def __mul__(self,frac):
        newfrac = Fraction(self.num*frac.num,self.den*frac.den)
        newfrac.reduce()
        return newfrac
    def inv(self):
        newfrac = Fraction(self.den, self.num)
        newfrac.reduce()
        return newfrac
    def __eq__(self,frac):
        self.reduce()
        frac.reduce()
        if(self.num == frac.num and self.den == frac.den):
            return True
        else:
            return False

def main():
    f1 = Fraction(3,4)
    f2 = Fraction(9,4)
    print("Addition:", f1+f2)
    print("Multiplication:", f1*f2)
    print("Inverse:" , f1.inv())
    print("Equality:", f1==f2)

if (__name__ == "__main__"):
    main()