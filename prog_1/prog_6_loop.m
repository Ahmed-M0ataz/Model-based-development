clear
clc

g= 9.81;
L= 1;
model = gcs;

for L_change = 1:1:10
    L = L_change;
    sim(model);
    plot(ans.yout.get("theta_double_dots").Values)

    hold on;
    legendLables{L_change} = "L" + num2str(L);
    disp("Simulation at L = " + num2str(L) + "Is completed.")

end
legend(legendLables);
title("this is theta double dot by Defferant L values from 1 to 10")