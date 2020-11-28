# Energy-meter (under progress)
My energy meter has a LED that flashes each time I have consumed 1Wh of energy. This project uses an Arduino nano and a photocell to detect each pulse and calculates the momentary power and current as well as displaying the elapsed watt hours.

Right now the values is displayed on a 16x2 LCD screen communicating with a Arduino nano via the I2C protocol. 
My plan is to integrate this in Home Assistant by using a Arduino nano 33 IoT which is communicating with a Raspberry PI over WIFI. I will also 3D print a proper case, right now everything is sitting on a breadboard with the screen taped to it. Everything is connected with jumper wires.



