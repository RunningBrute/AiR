a = -1;
b= 1;
n = 1:1:100;
y1 = 1:1:100;
y2 = 1:1:100;
y3 = 1:1:100;

%% przyklad A)

aa = 2;
for ii = 1:100
  fx = a:(b-a)/n(ii):b;
  j = 1;
  for i = a:(b-a)/n(ii):b
      fx(j) = (4*(i)^3)+(3*(i)^2);
      j = j+1;
  end
  y1(ii) = abs(aa - mcI(a,b,n(ii),fx));
  y2(ii) = abs(aa - mcII(a,b,n(ii),fx));
  y3(ii) = abs(aa - mcIII(a,b,n(ii),fx));
end
subplot(1,3,1);
hold on;
plot([1:100],y1,'-r');
plot([1:100],y2,'-b');
plot([1:100],y3,'-g');
title('wielomian');
xlabel('n'); ylabel('epsilon');
%% przyklad B)

bb = 1.8616;

j = 1;
for ii = 1:100
  fx = a:(b-a)/n(ii):b;
  j = 1;
  for i = a:(b-a)/n(ii):b
      fx(j) = 3*sin(i^2);
      j = j+1;
  end
  y1(ii) = abs(bb - mcI(a,b,n(ii),fx));
  y2(ii) = abs(bb - mcII(a,b,n(ii),fx));
  y3(ii) = abs(bb - mcIII(a,b,n(ii),fx));
end
subplot(1,3,2);
hold on;
plot([1:100],y1,'-rp');
plot([1:100],y2,'-b');
plot([1:100],y3,'-g');
title('sinus');
xlabel('n'); ylabel('epsilon');
%% przyklad C)

cc = 4.7008;

j = 1;

for ii = 1:100
  fx = a:(b-a)/n(ii):b;
  j = 1;
  for i = a:(b-a)/n(ii):b
      fx(j) = 2*exp(-i);
      j = j+1;
  end
  y1(ii) = abs(cc - mcI(a,b,n(ii),fx));
  y2(ii) = abs(cc - mcII(a,b,n(ii),fx));
  y3(ii) = abs(cc - mcIII(a,b,n(ii),fx));
end
subplot(1,3,3);
hold on;
plot([1:100],y1,'-r');
plot([1:100],y2,'-b');
plot([1:100],y3,'-g');
title('exp');
xlabel('n'); ylabel('epsilon');