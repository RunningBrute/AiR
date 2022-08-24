function y = mcII(a,b,n,fx)
    
    h = (b-a)/n;
    
    y0 = fx(1);
    y1 = 0;
    for i=1:(n-1)
        y1 = y1 + fx(i+1);
    end
    
    y = (h/2)*(y0 + (2*y1) + fx(n+1));
    
    