function y = lagrange(x, knots_n)

y = 0;
tt = -4:(8/knots_n):4;

for j=1:knots_n+1
    num = 1;
    den = 1;
    for i=1:knots_n+1 
        if i~=j
            num = num*(x-tt(i));
            den = den*(tt(j)-tt(i));
        end
    end
    y = y + poly_n(j)*(num/den);
end