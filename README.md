# Extended-Resistance-Measurement
 
 **Aim:** Use the analog inputs and digital outputs (and probably a voltage divider) to determine the value of resistors. The measurement must be continously and the result must be shown on a screen.

**Hardware Used:** Arduino Uno with Screw Schield,  mSD Shield, Jumper Wires, Bread board, several resistors with different values, USB Cable.

**Software Used:** Arduino version 1.6.9

An ohmmeter is an embedded device assembled in correct combination of Hardware and Software (we used Arduino 1.6.9 IDE) to calculate the resistance. With proper code, we can turn the Arduino UNO into a device that can measure resistance. 

**Working:**
When the 2 resistors in series forms a voltage divider circuit. One end of the resistor pair is hooked up to 5V and the other end is hooked up to ground. The 5 volts that the arduino provides gets divided up between the 2 resistors, depending on the value of the 2 resistors. The resistor which holds the greater resistance gets more of the voltage, according to ohm's law formula, V=IR. The voltage that falls across a component is directly proportional to the amount of resistance it contains. Using this principle, we can set up a mathematical model to determine the resistance, based on the voltage division as show in fig.

**Circuit Diagram:**

![Alt text](https://github.com/tannupanwar/Extended-Resistance-Measurement/blob/master/Circuit_new.png "Circuit Diagram")
 
**Resistance table:**

| Table        | Rref1         | Rref2  |
| ------------ |:-------------:| -----: |
| RM           |  1300         | 580000 |
| 10           | 8             | 0      |
| 100          | 73            | 0      |
| 120          | 87            | 0      |
| 150          | 106           | 0      |
| 180          | 125           | 0      |
| 220          | 148           | 0      |
| 270          | 176           | 0      |
| 330          | 207           | 1      |
| 390          | 236           | 1      |
| 470          | 272           | 1      |
| 560          | 308           | 1      |
| 680          | 352           | 1      |
| 820          | 396           | 1      |
| 1000         | 445           | 2      |
| 10000        | 906           | 17     |
| 100000       | 1011          | 151    |
| 1000000      | 1023          | 648    |
| 4700000      | 1024          | 912    |
| 10000000     | 1024          | 968    |


**Source Code:**

```cpp
int analogPin= 0;
int raw= 0;
int Vin= 5;
float Vout= 0;
float R1= 6800;
float R2= 0;
float buffer= 0;
int stdResisters[]={1000,1100,1200,1300,1500,1600,1800,2000,2200,2400,2700,3000,3300,3600,3900,4300,4700,5100,5600,6200,6800,7500,8200,9100};
int stdResisters1[]={10,11,12,16,18,20,22,24,27,30,33,36,39,43,47,51,56,62,68,75,82,91};
float x=0;
float y=0;
float temp;
int analogPin1= 1;
float Vout1= 0;
float R11= 1300;
float R22= 0;
void setup()
{
Serial.begin(9600);
}
void loop()
{
  
raw= analogRead(analogPin);
if(raw) 
{
x= raw;
buffer= raw * Vin;
Serial.print("raw: ");
Serial.println(x);
Vout= (buffer)/1024.0;
buffer= (Vin/Vout) -1;
y= buffer;
R2= R1 * buffer;
Serial.print("Vout: ");
Serial.println(Vout);
if(R2< stdResisters[(sizeof(stdResisters)/2)])
{
for(int i=0;i<(sizeof(stdResisters)/2);i++)
{
  if(i==0 && R2<stdResisters[i])
  {
    R2=stdResisters[i];
    break;
  }
  else
  {
    if(R2> stdResisters[i] && R2<stdResisters[i+1])
    {
      if((R2-stdResisters[i]) > (stdResisters[i+1]-R2))
      {
        R2=stdResisters[i+1];
        break;
      }
      else
      {
        R2=stdResisters[i];
        break;
      }
    }
  }
}
}
else
{
for(int i=0;i<((sizeof(stdResisters)/2)+1);i++)
{
  if(i==0 && R2<stdResisters[i])
  {
    R2=stdResisters[i];
    break;
  }
  else
  {
    if(R2> stdResisters[i] && R2<stdResisters[i+1])
    {
      if((R2-stdResisters[i]) > (stdResisters[i+1]-R2))
      {
        R2=stdResisters[i+1];
        break;
      }
      else
      {
        R2=stdResisters[i];
        break;
      }
    }
  }
}
  
}
Serial.print("R2:");
Serial.println(R2);
delay(1000);
raw= analogRead(analogPin1);
if(raw) 
{
buffer= raw * Vin;
Vout1= (buffer)/1024.0;
Vout1=floor(Vout1*1000)/1000;
buffer= (Vin/Vout1) -1;
R22= R11 * buffer;
Serial.print("Vout1: ");
Serial.println(Vout1);
if(R22< stdResisters1[(sizeof(stdResisters1)/2)])
{
for(int i=0;i<(sizeof(stdResisters1)/2);i++)
{
  if(i==0 && R22<stdResisters1[i])
  {
    R22=stdResisters1[i];
    break;
  }
  else
  {
    if(R22> stdResisters1[i] && R22<stdResisters1[i+1])
    {
      if((R22-stdResisters1[i]) > (stdResisters1[i+1]-R22))
      {
        R22=stdResisters1[i+1];
        break;
      }
      else
      {
        R22=stdResisters1[i];
        break;
      }
    }
  }
}
}
else
{
for(int i=0;i<((sizeof(stdResisters1)/2)+1);i++)
{
  if(i==0 && R22<stdResisters1[i])
  {
    R22=stdResisters1[i];
    break;
  }
  else
  {
    if(R22> stdResisters1[i] && R22<stdResisters1[i+1])
    {
      if((R22-stdResisters1[i]) > (stdResisters1[i+1]-R22))
      {
        R22=stdResisters1[i+1];
        break;
      }
      else
      {
        R22=stdResisters1[i];
        break;
      }
    }
  }
}
  
}
//Serial.print("raw2:");
//Serial.println(raw);
//Serial.print("buffer2:");
//Serial.println(buffer);
Serial.print("R22: ");
Serial.println(R22);
delay(1200);
}
}
}
```

1.	Create variable analogPin equal to 0. (i.e. voltage value read connected to analogPin A0).
2.	Create variable raw, to read analog voltage. (can be between 0 to 1023).
3.	Create variable vin equal to 5 (5V provided by Arduino UNO).
4.	Create variable vout, initially 0 (later, divided voltage across unknown resister).
5.	Create variable R1 (Reference resister).
6.	Create variable R2, initially 0. (Unknown resister).
7.	Create variable buffer (temporary variable).
8.	Formula used to calculate:
