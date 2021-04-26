# -*- coding: utf-8 -*-

from matplotlib import pyplot as plt
import numpy as np
# Load data from txt file

euler = np.loadtxt('results_euler.txt')
rk4 = np.loadtxt('results_RK4.txt')
# Plot data

plt.plot(euler[:,0],euler[:,1])
plt.plot(rk4[:,0],rk4[:,1])
plt.legend(["euler method","RK4 method"])
plt.title('Modélisation d\'un circuit RLC (E= 1V, R=0.1Ω, L=1H, C=1F)')
plt.xlabel("temps en s")
plt.ylabel("u(t)")
plt.grid()
plt.savefig('results.png')


# Plot data


