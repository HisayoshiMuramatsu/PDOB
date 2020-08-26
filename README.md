# PDOB - Periodic-Disturbance Observer

This is a control algorithm implementation in C++. It implements the control method proposed by [1] and developed by [2]. The periodic-disturbance observer (PDOB) has the following advantages.

1. Periodic-disturbance estimation and cancellation
2. The PDOB including a time-delay element aims at compensating all frequencies of a periodic disturbance with an infinite number of band-stop characteristics.
3. The time-delay element does not affect the nominal stability.
4. The PDOB does not affect the nominal command-tracking characteristic.
5. The amplification of other disturbances can be attenuated by the sensitivity function adjusted by a design parameter γ.
6. The parameter γ can also adjust the complementary sensitivity function, which provides the robust stability without peaks.

The PDOB is beneficial to realizing precise repetitive operations for automatic systems, such as actuators, industrial machines, robots, and so on.

[1] Hisayoshi Muramatsu and Seiichiro Katsura, “An Adaptive Periodic-Disturbance Observer for Periodic-Disturbance Suppression,” IEEE Transactions on Industrial Informatics, vol. 14, no. 10, pp. 4446-4456, Oct. 2018.
IEEE Xplore: http://ieeexplore.ieee.org/document/8288655/
arXive: https://arxiv.org/abs/2004.00487  
[2] Hisayoshi Muramatsu and Seiichiro Katsura, “An Enhanced Periodic-Disturbance Observer for Improving Aperiodic-Disturbance Suppression Performance,” IEEJ Journal of Industry Applications, vol. 8, no. 2, pp. 177-184, May 2019.
https://www.jstage.jst.go.jp/article/ieejjia/8/2/8_177/_article/-char/ja/

## Description

The PDOB can estimate and compensate for a periodic disturbance including a fundamental wave and harmonics.

## Example

There is a test program that simulates a position control system using a motor, proportional-and-derivative (PD) controller, and acceleration feedforward controller under a periodic disturbance including harmonics.

## Licence

[MIT License](https://github.com/HisayoshiMuramatsu/PDOB/blob/master/LICENSE) © Hisayoshi Muramatsu
