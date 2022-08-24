clear;

knots_n = 50;

t = -4:0.01:4;
y = 1:801;
yy = 1:801;

for i=1:801
    y(i) = poly_n(t(i)); 
    yy(i) = lagrange(t(i),knots_n); 
end

hold on;
plot(t,y,'r');
plot(t,yy,'g');
legend('funkcja wlasciwa','po aproksymacji');