# -*- coding: utf-8 -*-

from matplotlib import pyplot as plt
import numpy as np
# Load data from txt file

data = np.loadtxt('results_euler.txt')
# Plot data

plt.plot(data[:,0],data[:,1])
plt.title('Modélisation d\'un circuit RLC avec la méthode d\'Euler\n avec E= 1V, R=0.1Ω, L=1H, C=1F')
plt.xlabel("temps en s")
plt.ylabel("u(t)")
plt.savefig('euler.png')
