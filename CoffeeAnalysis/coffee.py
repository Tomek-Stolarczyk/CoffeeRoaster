import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def AverageFilter(temps):
    filtered_values = np.zeros((temps.shape[0]//4, 1))
    for j in range(0, len(temps)-4, 4):
        i = j//4
        filtered_values[i] = (temps[j] + temps[j+1] + temps[j+2] + temps[j+3]) / 4
    return filtered_values


if __name__ == "__main__":
    coffee_folder = 'C:/Users/GLaDOS/Desktop/coffee_data/'
    coffee_data = coffee_folder + 'Eteopia-11-22-2018-03_23_49.csv'

    raw_data = np.array(pd.read_csv(coffee_data))
    raw_temps = raw_data[:,0]

    filtered_values = AverageFilter(raw_temps)
    fig, ax = plt.subplots()
    ax.plot(range(len(raw_temps)), raw_temps)
    ax.plot([i*4 for i in range(len(filtered_values))], filtered_values)
    ax.set(xlabel='time (s)', ylabel='tempurature')
    ax.grid()
    plt.show()