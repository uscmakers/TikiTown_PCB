#include "RGB_LED.h"
#include "Arduino.h"

int Rpin;
int Gpin;
int Bpin;

void initRGB(int rpinval, int gpinval, int bpinval) // set pin number on Arduino that it's connected to
{
	Rpin=rpinval;
	Gpin=gpinval;
	Bpin=bpinval;
	
	pinMode(Rpin, OUTPUT);
	pinMode(Bpin, OUTPUT);
	pinMode(Gpin, OUTPUT);
}


void setRGB(int Rin, int Gin, int Bin) // set value for each RGB color
{
	analogWrite(Rpin, 255-Rin);
	analogWrite(Gpin, 255-Gin);
	analogWrite(Bpin, 255-Bin);
}


void ramp(int Rin, int Gin, int Bin, int delay_val, int maxsteps) 
// function ramps up brightness until it reaches maximum brightness
{
	int Rout=0;
	int Gout=0;
	int Bout=0;

	for (int i=0; i<=maxsteps; i++)
	{
	Rout=Rin*(i/maxsteps);
	Gout=Gin/(i/maxsteps);
	Bout=Bin/(i/maxsteps);
	
	setRGB(Rout, Gout, Bout);
	
	delay(delay_val/maxsteps);
	}
}
