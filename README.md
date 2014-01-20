jenkuino
========

jenkins marries arduino to show continues integration results

Arduino
-------
Attach the PWM channels to the yellow/orange wire
Attach the black one to the GND
Attach the red wire to the voltage supply (5V or as much as required by your servos, standard is 6V)

The servoCommand.ino is on PWM ports 3,5 and 6, modidy to your needs

Serial interface
----------------
The readTmpWriteSerial script should be started (i.e. ruby readTmpWriteSerial.rb)
If you like you can also write a service, but for testing it is sufficient.
It must keep running, once you interrupt the serial interface the arduino programm will reset and put the default values.
Do not save the state, it is not that good of an idea to save values to EEPROM on the Arduino all the time, it has a limit of around 100000.

Jenkins
-------

Install the build script in the jenkins set and filter your values as needed.
It should generate as many entries into the /tmp/feedjenkuino as servos attached
i.e.:
20 30 40\n

The value range should be ideally 5 - 175.
It is theroetically 0 to 180 degrees but higher or lower values may cause noise, experiment with your own servos which values are acceptable 


