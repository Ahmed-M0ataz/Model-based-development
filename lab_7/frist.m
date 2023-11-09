clearvars
clc
% gain 
A = 0.25;
T = 0.1;
% numinetor 
num = [0 A];
den = [T 1];
% transfare function
G = tf(num,den)
% draw response with time
% step(G);
% xlim([0 12]);
% ylim([0 0.5]);

t = 0:0.1:10;
u_ramp= t;
[y_ramp,t_ramp] = lsim(G,u_ramp,t);
subplot(2,1,1);
plot(t_ramp,y_ramp)
xlabel('Time')
ylabel('system output')
grid on

u_para = 0.5 * t.^2;
[y_para, t_para] = lsim(G,u_para,t);
subplot(2,1,2)
plot(t_para, y_para)
xlabel('Time')
ylabel('system output')
grid on
