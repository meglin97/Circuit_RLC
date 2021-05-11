# -*- coding: utf-8 -*-

from matplotlib import pyplot as plt
import numpy as np

# Load data from txt file
euler = np.loadtxt('data_euler.txt')
rk4 = np.loadtxt('data_RK4.txt')
heun = np.loadtxt('data_heun.txt')

# Plot data
plt.figure(figsize=(20,15))
plt.plot(euler[:,0],euler[:,1])
plt.plot(heun[:,0],heun[:,1])
plt.plot(rk4[:,0],rk4[:,1])

# Add legend, axis label  and title
plt.legend(["euler method","heun method","RK4 method"],shadow=False, ncol=3)
plt.title('Modélisation d\'un circuit RLC (E= 1V, R=0.1Ω, L=1H, C=1F)')
plt.xlabel("temps en s")
plt.ylabel("u(t)")
plt.xlim([-1,101])
plt.grid()

# Save result as image
plt.savefig('data.png')

# Alert message to user
print("\n********** INFO : results.png crée **********")



