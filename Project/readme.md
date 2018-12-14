## data.txt
This text file contains the planetry data (excluding the Sun) of the 9 planets in the Solar System. It contains the name, mass(10e24kg), period(days), position from Sun(10e9km)and orbital velocity(m/s).

The data was aquired from: https://nssdc.gsfc.nasa.gov/planetary/factsheet/ (accessed 27th November 2018).
The planetary orbits had to be rounded to the nearest day in order to loop around an integer number of times.

## project.c

This program maps the planetary motion of planets in the solar system around the Sun.
The Sun's mass was auired from: https://nssdc.gsfc.nasa.gov/planetary/factsheet/sunfact.html (accessed 30th November 2018).
To run use:
```
gcc project.c -o project.exe
./project.exe
```

## plot.py

This program reads in the planetary (x, y) positions generated from the project.c program.
It then maps these position as a scatter (x, y) graph to simulate the planetary motion around the Sun over time.
This program also gives the user the opportunity to specify the amount of planets they wish to map.

To run in Python 3 use:
```
python plot.py
```

## combo_plot.py

This is a SAMPLE program and reads in the planetary (x, y) positions generated from the project.c program.

To run in Python 3 use:
```
python combo_plot.py
```
This just gives a demnstartion of combining all of the planetary orbits from some test data generated from the project.c program.
The pdf following pdf is just a demonstration of combining all these planetary oribts 
![alt text](https://github.com/drummerevans/PHY2027/blob/master/Project/Combo_Orbit_Plot.pdf "Combo Plot")