# Extended-Resistance-Measurement
 
 **Aim:** Use the analog inputs and digital outputs (and probably a voltage divider) to determine the value of resistors. The measurement must be continously and the result must be shown on a screen.

**Hardware Used:** Arduino Uno with Screw Schield,  mSD Shield, Jumper Wires, Bread board, several resistors with different values, USB Cable.

**Software Used:** Arduino version 1.6.9

An ohmmeter is an embedded device assembled in correct combination of Hardware and Software (we used Arduino 1.6.9 IDE) to calculate the resistance. With proper code, we can turn the Arduino UNO into a device that can measure resistance. 

**Working:**
When the 2 resistors in series forms a voltage divider circuit. One end of the resistor pair is hooked up to 5V and the other end is hooked up to ground. The 5 volts that the arduino provides gets divided up between the 2 resistors, depending on the value of the 2 resistors. The resistor which holds the greater resistance gets more of the voltage, according to ohm's law formula, V=IR. The voltage that falls across a component is directly proportional to the amount of resistance it contains. Using this principle, we can set up a mathematical model to determine the resistance, based on the voltage division as show in fig.1

 
**Source Code:**

```cpp
int analogPin= 0;
int raw= 0;
int Vin= 5;
float Vout= 0;
float R1= 1300;
float R2= 0;
float buffer= 0;

void setup()
{
Serial.begin(9600);
}

void loop()
{
raw= analogRead(analogPin);
if(raw) 
{
buffer= raw * Vin;
Vout= (buffer)/1024.0;
buffer= (Vin/Vout) -1;
R2= R1 * buffer;
Serial.print("Vout: ");
Serial.println(Vout);
Serial.print("R2: ");
Serial.println(R2);
delay(1000);
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
