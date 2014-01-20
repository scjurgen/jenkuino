
# install rubygems  and serialport
require 'rubygems'  
require 'serialport' 

#params for serial port  
#this may be different for you and depends on the mac AND the arduino that you are using
#check Arduino App to match the right port

port_str = "/dev/tty.usbmodem1411"  
baud_rate = 9600  
data_bits = 8  
stop_bits = 1  
parity = SerialPort::NONE  

sp = SerialPort.new(port_str, baud_rate, data_bits, stop_bits, parity)  
sp.flow_control = (SerialPort::SOFT|SerialPort::HARD)


#put the 3 servos to center position 
lastcontent="90 90 90\n"

while 1 do
	a = File.read("/tmp/feedjenkuino")
	#send new data only if different
	unless a.eql? lastcontent then 
		sp.write(a)
		lastcontent = a
		puts lastcontent
		puts "\n"
	end
	sleep(1)
end
#actually never reached
sp.close

