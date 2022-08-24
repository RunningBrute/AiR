function y = cmc(a,b,N)

    h = (b-a)/N;
    y = 0;
    
    for i=1:N
        j = ((b-a)*rand()) + a;
        y = y + (4*(j)^3)+(3*(j)^2);
        %y = y + 3*sin(j^2);
        %y = y + 2*exp(-j);
    end
    
    y = h*y;