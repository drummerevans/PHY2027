'''
This program reads in the planetary (x, y) positions generated from the c file project.c
It then plots these positions as an (x, y) scatter point graph to map out the planetary motion around the Sun
'''

import matplotlib.pyplot as plt

fptr = open("results.txt", "r", newline=None)
row = fptr.readline()

x_coords = []
y_coords = []

data = []

while row: # while there is a line in the text file, perform the following...
    data = row.split( ) # splitting the row of numbers into individual numbers without spaces
    for col in range(0, len(data)):
        if col == 0:
            x_coords.append(float(data[col]))
        elif col == 1:
            y_coords.append(float(data[col]))
    row = fptr.readline() # when fptr.readline() is called, we move onto the next line/row

plt.rc('font', family = 'serif', serif = 'cmr10')
plt.rcParams['mathtext.fontset'] = "cm" 
plt.rcParams['axes.unicode_minus'] = False # ensures that minus signs appear on the axes scales

plt.plot(x_coords, y_coords, 'r.')
plt.plot(x_coords, y_coords, LineWidth = 0.9, LineStyle = "-", Color = "b")
plt.xlabel("x Position", fontsize = 12)
plt.ylabel(" y Position", fontsize = 12)
plt.savefig("My_Orbit_Plot.pdf")