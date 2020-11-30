clc;clear all;
prompt='  Enter the word    ';
str=input(prompt,'s');
arith=str;
len=size(str);
le=len(2);
alpha=['a' 'b' 'c' 'd'];
p=[0.4 0.3 0.2 0.1];
q1(1)=0;
q2(1)=p(1);

for i=1:le-1
    q1(i+1)=q1(i)+p(i);
    q2(i+1)=q2(i)+p(i+1);
end
l=0;h=1;
for i=1:le
    r=h-l;
    x=find(alpha==str(i));
    h=l+r*q2(x);
    l=l+r*q1(x);
end
disp('codeword:');
disp(l);
disp('tag');
disp((l+h)/2.0);

c=""; v=l;xd=0;
while(v> 1e-13 && xd<10)
    xd=xd+1;
    [a,f]=inrange(v,q1,q2,alpha,le);
    c=strcat(c,a);
    r = q2(f)-q1(f);
    v=(v-q1(f)); v=v/r;
  
end
disp('dec');
disp(c);

function [a,f] = inrange(x,q1,q2,alpha,le)
for i=1:le
    if(x>=q1(i) && x<q2(i))
        a =  alpha(i); f=i;
    end 
end
end