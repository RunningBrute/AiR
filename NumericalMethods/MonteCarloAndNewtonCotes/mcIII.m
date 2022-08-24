function y = mcIII(a,b,n,fx)

    h = (b-a)/n;
    k = n/2;
    
    y0 = fx(1);
    y1 = 0;
    for i=1:k
        y1 = y1 + fx((2*i)+1);
    end
    
    y2 = 0;
    for i=1:(k-1)
        y2 = y2 + fx(2*(i+1));
    end;
    
    y = (h/3)*(y0 + (4*y1) + (2*y2) + fx(n+1));
    