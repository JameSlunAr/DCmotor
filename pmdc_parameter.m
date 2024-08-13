% Tham so dong co dc
UaN = 140;
IaN = 25;
PN = 3336;
La = 1.7e-3;
Ra = 0.26;
nN = 3000;
TN = 0.26;
J = 0.00252;
B = 0;

% Tinh toan tham so chua biet
KE = (UaN - Ra*IaN)*9.55/nN;
KT = KE;
% K o day la KT*phi=KE*phi

% PI dong dien
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

% PI toc do
Tfv=5*Tfi;
Teq=(2*Zeta)/OmegaN+Tfv;
TMech=J/KE;
Kpv=TMech/(2*Teq);
Tiv=4*Teq;
Kiv=Kpv/Tiv;
Kav=sqrt(Tiv);