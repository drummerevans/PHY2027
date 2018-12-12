'''
This program reads in the planetary (x, y) positions from text file(s) specified by the user generated from the c file project.c
The user then names the planet and specifies it's colour from the given list.
It then plots these positions as an (x, y) scatter point graph to map out the planetary motion around the Sun.
Furthermore, the user can specify the amount of times to run the program in order to obtain multiple mappings of planets on the same plot.
'''

import matplotlib.pyplot as plt

def plotter():
    # this is needed in order to read from the correct file
    planet = input("What is the name of you planet? ")
    results = input("Please input the name of the text file (including the .txt extension) from where you want to aquire the data: ")
    print("Please view the colour choice for your chosen planet from the list below: ")
    print("r, b, c, y, w, g, m, k")
    point_colour = input("Now please input the colour of your planet: ")

    fptr = open(results, "r", newline=None)
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
    plt.gca().set_facecolor('xkcd:dark blue')

    plt.plot(x_coords, y_coords, point_colour, Marker = ".", label = planet)
    plt.plot(x_coords, y_coords, LineWidth = 0.9, LineStyle = "-", Color = point_colour)
    plt.xlabel("x Position", fontsize = 12)
    plt.ylabel(" y Position", fontsize = 12)
    plt.legend(loc = "lower right", title = "Planet", fontsize = 10)
    plt.savefig("My_Orbit_Plot.pdf")

decision = 1
while decision == 1:
    plotter()
    print("Would you like to map another planet's orbit on the same plot?")
    print("1. Yes")
    print("2. No")
    decision = float(input("Please input 1 or 2: "))

print("Thank you for using these programs and goodbye.")