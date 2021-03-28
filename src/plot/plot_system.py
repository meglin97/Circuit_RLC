# -*- coding: utf-8 -*-
'''
Created on 27 mars 2021

@author: hlin
'''
import matplotlib.pyplot as plt


# Load data from txt file
def loadFile():
    x, y = [], []
    with open('results.txt', 'r') as file:
        values = [float(s) for s in file.split()]
        x.append(values[0])
        y.append(values[1])
    return x, y


# Plot data
def plotData(x, y):
    plt.plot(x, y)
    plt.xlabel("temps en s")
    plt.ylabel("u(t)")
    plt.show()
    
x,y=loadFile()
plotData(x,y)