/*
	arduino uno supports up to 6 servos 
	but keep in mind the consume  if you do not use external Voltage supply for the servo,
	strong servos might need too much for the USB too handle
 
*/
#include <Servo.h>


unsigned char servomap[] = {3,5,6};
#define MAXSERVOS (sizeof(servomap))

Servo servo[MAXSERVOS]; 

int curValues[MAXSERVOS];
 
void setup() 
{ 
	Serial.begin(9600);
	for (int i=0; i <3; i++)
	{
		servo[i].attach(servomap[i]);  
	}
} 


char readBuffer[128];
int curReadPos=0;

int positions[MAXSERVOS];
int oldPositions[MAXSERVOS];

char *delimiters = " ,;:\t";
void analyseBuffer()
{
	int curservo=0;
	char *pch = strtok(readBuffer,delimiters);
  	while (pch != NULL)
	{
		positions[curservo++] = atol(pch);
		if (curservo==MAXSERVOS)
			return;
	    pch = strtok (NULL, delimiters);
	}
}

void updateServos(void)
{
    for (int i=0; i < MAXSERVOS; i++)
	    servo[i].write(positions[i]);

}

void loop(void) 
{
	int ch = Serial.read();
	if (ch != -1)
	{
		switch(ch)
		{
		case '|':
		case 13:
		case 10:
			readBuffer[curReadPos] = 0;
			analyseBuffer();
			updateServos();
			curReadPos = 0;
			break;
		default:
			if (((ch >='0') && (ch <='9')) 
				|| (ch==';')
				|| (ch==':')
				|| (ch==',')
				|| (ch==' ')
				|| (ch==9)
				)
			{
				readBuffer[curReadPos++] = ch;
			}
			if (curReadPos >= sizeof(readBuffer)) // avoid overflow
			{
				curReadPos = 0;
			}
			break;
			// ignore
		}
  	}
}
