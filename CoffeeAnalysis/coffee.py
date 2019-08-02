import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import queue

ring_buffer = queue.Queue()

def getDerivative(temp):
    global ring_buffer
    diff = temp - ring_buffer.get()
    ring_buffer.put(temp)
    return 100*diff

coffee_folder = 'C:/Users/GLaDOS/Desktop/coffee_data/'
coffee_data = coffee_folder + 'Eteopia-11-22-2018-03_23_49.csv'

coffee = np.array(pd.read_csv(coffee_data))
temps = coffee[:,0]

temps = temps[:int(len(temps)*0.75)]
derivs = np.zeros(temps.shape)

for i in range(5):
    ring_buffer.put(float(temps[0]))

for j in range(len(temps)):
    derivs[j] = getDerivative(temps[j])



fig, ax = plt.subplots()
ax.plot(range(len(temps)), temps)
ax.plot(range(len(derivs)), derivs)
ax.set(xlabel='time (s)', ylabel='tempurature')
ax.grid()
plt.show()

k = 0