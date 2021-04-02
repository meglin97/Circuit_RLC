# -*- coding: utf-8 -*-

from matplotlib import pyplot as plt
import numpy as np
# Load data from txt file

x, y = [], []
with open('results.txt', 'r') as file:
    lines=file.readlines()
    for line in lines:
        values = [float(s) for s in line.split()]
        x.append(values[0])
        y.append(values[1])
# Plot data

plt.plot(x, y)
plt.xlabel("temps en s")
plt.ylabel("u(t)")
plt.show()
