import matplotlib.pyplot as plt

x_vals = []
y_vals = []

fptr = open("results.txt", "r", newline=None)

list_of_results = fptr.readlines()

data  = []

for result in list_of_results:
    datum = result.split( )
    for i in range(0, len(datum)):
        if i == 0:
            x_vals.append(float(datum[i]))
        elif i == 1:
            y_vals.append(float(datum[i]))

plt.plot(x_vals, y_vals, 'r+')
plt.savefig("My_Orbit_Plot.pdf")