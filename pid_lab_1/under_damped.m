clearvars
clc



zeta = 0.2;
Wn = 2;
numinator = [0 0 Wn^2];
den = [1 2*zeta*Wn Wn^2];

G = tf(numinator,den)

step(G)