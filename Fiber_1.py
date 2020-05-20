import numpy as np
import matplotlib.pylab as plt
from scipy.interpolate import make_interp_spline

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

x = np.arange(0, 80, 2)
xnew = np.linspace(0, 80, 10000)
y1 = [
    0, 0, 0, 0.05, 0.08, 0.10, 0.12, 0.15, 0.19, 0.24, 0.30, 0.36, 0.41, 0.46,
    0.79, 1.11, 1.45, 1.75, 2.10, 2.42, 2.75, 3.16, 3.43, 3.78, 4.15, 4.41,
    4.72, 5.08, 5.41, 5.75, 6.07, 6.39, 6.68, 6.99, 7.31, 7.65, 7.95, 8.30,
    8.67, 9.00
]
y = np.asarray(y1)
ynew = make_interp_spline(x, y)(xnew)
x0 = 26
y0 = 0.46
plt.scatter(x0, y0, s=25, color='y')
plt.annotate('阈值电流：28mA',
             xy=(x0, y0),
             xytext=(-50, +90),
             textcoords='offset points',
             fontsize=16,
             arrowprops=dict(arrowstyle='->', connectionstyle='arc3,rad=.2'))
plt.plot([x0, x0], [y0, 0], 'k--')
plt.plot(xnew, ynew, 'g', label="拟合")
plt.plot(x, y, 'r', linestyle='--', label="原始")
plt.title("半导体激光器P-I特性曲线图")
plt.xlabel("驱动电流I(mA)")
plt.ylabel("输出功率P(mW)")
plt.ylim(0, 9)
plt.legend(loc='upper left')
plt.show()