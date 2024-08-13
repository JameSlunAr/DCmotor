%tham so dong co dc
Ua = 400;
Ia = 62;
P = 22e3;
La = 5.2e-3;
Ra = 0.32;
T = 67.8;
n = 3100;
J = 0.05;
Uf = 310;
If = 1.8;
eta = 0.873;
% Tinh toan tham so chua biet
KE = (Ua - Ra*Ia)*9.55/n;
% KT, KE o day la K*phi
KT = KE;
Laf = KE/If;
Rf = Uf/If;
Lf = Laf;