#include<string.h> 
char inByte[100];
char * x;
char * y;
char * z;
char * ch;
int pos, a, b, c, i, k;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{    
  if(Serial.available()>0) 
  {
    // if data available in serial port
  
    while(!Serial.available());
    { digitalWrite(13, HIGH);
      Serial.readBytesUntil('E', inByte, 100);
      int i=1;
      int j=0, k=0, l=0, m=0;
      while(inByte[i]!='y')
      {
          x[j]=inByte[i];
          j++;
          i++;
      }
      x[j]='\0';
      while(inByte[i]!='Z')
      {
          y[l]=inByte[i];
          l++;
          i++;
      }
      y[l]='\0';

      while(inByte[i]!='E')
      {
          z[m]=inByte[i];
          m++;
          i++;
      }
      z[m]='\0';
    
     a= atoi((const char* )x);
     b= atoi((const char* )y);
     c= atoi((const char* )z);

     
   /*  Serial.println("x = ");Serial.print(x);
     Serial.println("y = ");Serial.print(y);
     Serial.println("Z = ");Serial.print(z);
     
     */
     }
  }
     else
      digitalWrite(13, LOW);
}
