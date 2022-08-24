function y = mcI(a,b,n,fx)

    h = (b-a)/n;
    y = 0;
    
    for i=1:n
        y = y + fx(i);
    end
    
    y = h*y;