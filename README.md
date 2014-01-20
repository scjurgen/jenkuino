jenkuino
========

Here at AS ideas Engineering we value testing. Integral part is the Continues Integration and Unit-Tests

jenkins marries arduino to show continues integration results

Arduino
-------
Attaching the Servo(s):
- Attach the PWM channels to the yellow/orange wire
- Attach the black one to GND
- Attach the red wire to the voltage supply (5V or as much as required by your servos, standard is 6V)

The servoCommand.ino is on PWM ports 3,5 and 6, modify to your needs.

TBD: Fritzing scheme


Serial interface
----------------
The readTmpWriteSerial script should be started (i.e. ruby readTmpWriteSerial.rb)
If you like you can also write a service, but for testing it is sufficient.
It must keep running, once you interrupt the serial interface the arduino programm will reset and put the default values.


Jenkins
-------

(TBD)

Install the build script in the jenkins set and filter your values as needed.
It should generate as many entries into the /tmp/feedjenkuino as servos attached
i.e.:
<code>
$ cat /tmp/feedjenkuino
</code>
<code>
20 30 40\n
</code>

The value range should be ideally 5 - 175.
It is theroetically 0 to 180 degrees but higher or lower values may cause noise, experiment with your own servos which values are acceptable 


