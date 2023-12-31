# Second Order System Response

## 1. Undamped

When damping ratio (\(\zeta\)) equals 0, the response oscillates without stability. The system exhibits oscillatory behavior.
![Undamped Response](https://github.com/Ahmed-M0ataz/Model-based-development/blob/main/pid_lab_1/media/un_damping.png)

## 2. Underdamping

For \(0 < \zeta < 1\), the system is underdamped. There is overshooting, but the system is stable, and settling time is less than that of overdamping and critical damping. The overshoot depends on the natural frequency.

![Underdamped Response](https://github.com/Ahmed-M0ataz/Model-based-development/blob/main/pid_lab_1/media/under_damping.png)

## 3. Critical Damping

At \(\zeta = 1\), critical damping occurs. There is no overshoot, and the settling time is greater than underdamping but less than overdamping.

![Critical Damping Response](https://github.com/Ahmed-M0ataz/Model-based-development/blob/main/pid_lab_1/media/critical_damping.png)

## 4. Overdamped

When \(\zeta > 1\), the system is overdamped. It takes a longer time to stabilize, with the settling time being the longest among the cases.

![Overdamped Response](https://github.com/Ahmed-M0ataz/Model-based-development/blob/main/pid_lab_1/media/over_damping.png)

## Simulating on Real Hardware

To simulate the response on real hardware, a simple second-order system from an RC circuit is used. 

![Hardware Connection](https://github.com/Ahmed-M0ataz/Model-based-development/blob/main/pid_lab_1/media/rc_circuit.jpg) | ![Hardware Connection](https://github.com/Ahmed-M0ataz/Model-based-development/blob/main/pid_lab_1/media/RC_CONNICTION.png)

Real Hardware:

![real hardware](https://github.com/Ahmed-M0ataz/Model-based-development/blob/main/pid_lab_1/media/real_hardware.jpg)

The Simulink blocks are configured as follows:

![Simulink Blocks](https://github.com/Ahmed-M0ataz/Model-based-development/blob/main/pid_lab_1/media/simulink.png)

The output response on real hardware is depicted as:

![Output Response](https://github.com/Ahmed-M0ataz/Model-based-development/blob/main/pid_lab_1/media/real_hardware_rc_circuit_second_order.png)

