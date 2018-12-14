'''
This is a SAMPLE program and reads in the planetary (x, y) positions generated from the c file project.c
It then plots all the planets as an (x, y) scatter point graph to map out the planetary motion around the Sun
'''

import matplotlib.pyplot as plt

x1 = []
y1 = []

x2 = []
y2 = []

x3 = []
y3 = []

x4 = []
y4 = []

x5 = []
y5 = []

x6 = []
y6 = []

x7 = []
y7 = []

x8 = []
y8 = []

fptr = open("results1.txt", "r", newline=None)

positions = fptr.readlines()

data  = []

for result in positions:
    datum = result.split( )
    for i in range(0, len(datum)):
        if i == 0:
            x1.append(float(datum[i]))
        elif i == 1:
            y1.append(float(datum[i]))

fptr2 = open("results2.txt") 

positions2 = fptr2.readlines()

data2  = []

for result in positions2:
    datum2 = result.split( )
    for i in range(0, len(datum2)):
        if i == 0:
            x2.append(float(datum2[i]))
        elif i == 1:
            y2.append(float(datum2[i]))

fptr3 = open("results3.txt") 

positions3 = fptr3.readlines()

data3  = []

for result in positions3:
    datum3 = result.split( )
    for i in range(0, len(datum3)):
        if i == 0:
            x3.append(float(datum3[i]))
        elif i == 1:
            y3.append(float(datum3[i]))

fptr4 = open("results4.txt") 

positions4 = fptr4.readlines()

data4  = []

for result in positions4:
    datum4 = result.split( )
    for i in range(0, len(datum4)):
        if i == 0:
            x4.append(float(datum4[i]))
        elif i == 1:
            y4.append(float(datum4[i]))

fptr5 = open("results5.txt", "r", newline=None)

positions5 = fptr.readlines()

data5  = []

for result in positions5:
    datum5 = result.split( )
    for i in range(0, len(datum5)):
        if i == 0:
            x5.append(float(datum5[i]))
        elif i == 1:
            y5.append(float(datum5[i]))
  
fptr6 = open("results6.txt") 

positions6 = fptr6.readlines()

data6  = []

for result in positions6:
    datum6 = result.split( )
    for i in range(0, len(datum6)):
        if i == 0:
            x6.append(float(datum6[i]))
        elif i == 1:
            y6.append(float(datum6[i]))


fptr7 = open("results7.txt") 

positions7 = fptr7.readlines()

data7  = []

for result in positions7:
    datum7 = result.split( )
    for i in range(0, len(datum7)):
        if i == 0:
            x7.append(float(datum7[i]))
        elif i == 1:
            y7.append(float(datum7[i]))


fptr8 = open("results8.txt") 

positions8 = fptr8.readlines()

data8  = []

for result in positions8:
    datum8 = result.split( )
    for i in range(0, len(datum8)):
        if i == 0:
            x8.append(float(datum8[i]))
        elif i == 1:
            y8.append(float(datum8[i]))

#trundles = [i ** 3 for i in range(1, 11)]
# fptr2 = open("cyg_ucerrors.txt", "w")

# print(err_vert)
# for item in err_vert:
#     fptr2.write(str(item) + "\n")

# fptr2.close()

fptr8.close()
fptr7.close()
fptr6.close()
fptr5.close()
fptr4.close()
fptr3.close()
fptr2.close()
fptr.close()

plt.rc('font', family = 'serif', serif = 'cmr10')
plt.rcParams['mathtext.fontset'] = "cm" 
plt.rcParams['axes.unicode_minus'] = False # ensures that minus signs appear on the axes scales
plt.gca().set_facecolor('xkcd:dark blue')

# plt.plot(x1, y1, 'r.')
plt.plot(x1, y1, LineWidth = 0.9, LineStyle = "-", Color = "r", label = "Mercury")
# plt.plot(x2, y2, 'r.')
plt.plot(x2, y2, LineWidth = 0.9, LineStyle = "-", Color = "w", label = "Venus")
# plt.plot(x3, y3, 'r.')
plt.plot(x3, y3, LineWidth = 0.9, LineStyle = "-", Color = "g", label = "Earth")
# plt.plot(x4, y4, 'r.')
plt.plot(x4, y4, LineWidth = 0.9, LineStyle = "-", Color = "y", label = "Earth")
# plt.plot(x5, y5, 'r.')
plt.plot(x5, y5, LineWidth = 0.9, LineStyle = "-", Color = "m", label = "Jupiter")
# plt.plot(x6, y6, 'r.')
plt.plot(x6, y6, LineWidth = 0.9, LineStyle = "-", Color = "b", label = "Saturn")
# plt.plot(x7, y7, 'r.')
plt.plot(x7, y7, LineWidth = 0.9, LineStyle = "-", Color = "c", label = "Uranus")
# plt.plot(x8, y8, 'r.')
plt.plot(x8, y8, LineWidth = 0.9, LineStyle = "-", Color = "k", label = "Neptune")
plt.xlabel("x Position", fontsize = 12)
plt.ylabel(" y Position", fontsize = 12)
plt.legend(loc = "lower right", title = "Planet", fontsize = 10)
plt.savefig("Combo_Orbit_Plot.pdf")