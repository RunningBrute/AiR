x = [308.6 362.6 423.3 491.4];
y = [0.055389 0.047485 0.040914 0.035413];
[p,L] = lagranp(x,y); %wyznacza wielomian Lagrange'a
xmin = min(x);
xmax = max(x);
xx = linspace(xmin,xmax,51);
yy = polyval(p,xx); %interpolacja do zadanych punktow
clf
plot(xx,yy,'b',x,y,'r*',x,o.*x,'p') %wykres funkcji
y1 = polyval(L(1,:),xx); %wielomiany charakterystyczne Lagrange'a
y2 = polyval(L(2,:),xx);
y3 = polyval(L(3,:),xx);
y4 = polyval(L(4,:),xx);
figure
clf
plot(xx,y1,'g.',xx,y2,'m-',xx,y3,'.',xx,y4,'r-.')