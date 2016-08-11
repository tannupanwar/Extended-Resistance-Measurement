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
