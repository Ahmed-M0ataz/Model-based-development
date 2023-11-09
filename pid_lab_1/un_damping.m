clearvars
clc



zeta = 0.0;
Wn = 5;
numinator = [0 0 Wn^2];
den = [1 2*zeta*Wn Wn^2];

G = tf(numinator,den)

step(G)
xlim([0 10])
ylim([0 2])