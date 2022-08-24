a = -1;
b= 1;
n = 100;
fx = a:(b-a)/n:b;
j = 1;

%% przyklad A)

for i = a:(b-a)/n:b
    fx(j) = (4*(i)^3)+(3*(i)^2);
    j = j+1;
end
y1 = mcI(a,b,n,fx)
y2 = mcII(a,b,n,fx)
y3 = mcIII(a,b,n,fx)
%mc = cmc(a,b,n)
%% przyklad B)

j = 1;

for i = a:(b-a)/n:b
    fx(j) = 3*sin(i^2);
    j = j+1;
end
y1 = mcI(a,b,n,fx)
y2 = mcII(a,b,n,fx)
y3 = mcIII(a,b,n,fx)
%mc = cmc(a,b,n)
%% przyklad C)

j = 1;

for i = a:(b-a)/n:b
    fx(j) = 2*exp(-i);
    j = j+1;
end
y1 = mcI(a,b,n,fx)
y2 = mcII(a,b,n,fx)
y3 = mcIII(a,b,n,fx)
%mc = cmc(a,b,n)