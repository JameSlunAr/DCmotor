% DC motor parameters
UaN = 140;          % rated voltage                     V
IaN = 25;           % rated current                     A
PN = 3336;          % power                             W
La = 1.7e-3;        % amature inductance                H
Ra = 0.26;          % amature resistance                Ohm
TN = 0.26;          % rated load                        N
nN = 3000;          % rated angular velocity            rpm
J = 0.00252;        % moment of inertia                 kg.m^2
B = 0;              % coefficient of viscous friction   kg.m^2/sec

% Unknown parameters calculating
KE = (UaN - Ra*IaN)*9.55/nN;
KT = KE;

% PI current controller
fsw = 5e4;
w_cc = fsw/20;
Kpc = La*w_cc;
Kic = Ra*w_cc;
Kac = 1/Kpc;

% PI speed controller
w_cs = w_cc/5;
Kps = J*w_cs/KT;
Kis = J*w_cs^2/(5*KT);
Kas = 1/Kps;

% Simulink sampling freq
f_simu = 1e5;