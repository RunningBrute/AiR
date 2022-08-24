function yi = lagrange(x,y,xi)

knots_n=20;
x=-4:8/knots_n:4;
for i=1:knots_n+1
    y(i)=exp(-x(i)^2);
end
xi=-4:0.01:4;
n = length(x) - 1; 
ni = length(xi); 

L = ones(n+1,ni); 
for k = 0 : n 
    
    for kk = 0 : (k-1)
        L(kk+1,:) = L(kk+1,:).*(xi - x(k+1))/(x(kk+1)-x(k+1)); 
    end 
    
    for kk = k+1 : n 
        L(kk+1,:) = L(kk+1,:).*(xi - x(k+1))/(x(kk+1)-x(k+1)); 
    end 
    
end 


yi = y * L;
hold on;
grid on;
for i=1:801
    yb(i)=exp(-xi(i)^2);
end
figure(1);
plot(xi,yb,'r');
plot(xi,yi,'g');
for i=1:801
    blad(i)=yb(i)-yi(i);
end
plot(xi,blad);
legend('f. rozpatrywana','interpolacja','blad');