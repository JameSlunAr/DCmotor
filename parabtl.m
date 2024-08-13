%Tham so dong co DC
UaN = 400; IaN = 62; PN = 22e3;
La = 5.2e-3; Ra = 0.32;
TN = 67.8; nN = 3100; J = 0.05;
B = 0;
% Tinh toan tham so chua biet
KE = (UaN - Ra*IaN)*9.55/nN;
KT = KE;
%PI dong dien
fsw = 5e3;
Td=1/fsw;
Tfi=1/(5*fsw);
Te=Td+Tfi;
Ta=La/Ra;
Ti=Ta;
Zeta=1/sqrt(2);
OmegaN=1/(2*Te*Zeta);
Kp=(Ra*Ta*OmegaN)/(2*Zeta);
Ki=Kp/Ti;
Ka=sqrt(Ti);

%PI toc do
Tfv=5*Tfi;
Teq=(2*Zeta)/OmegaN+Tfv;
TMech=J/KE;
Kpv=TMech/(2*Teq);
Tiv=4*Teq;
Kiv=Kpv/Tiv;
Kav=sqrt(Tiv);

%bo bien doi
%Vd=24;
%pi=3.14;