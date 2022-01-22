#include<Servo.h>

Servo serX;
Servo serY;

String serialData;

void setup() {
  serX.attach(10);
  serY.attach(11);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  //hello world
}

void serialEvent(){
  serialData = Serial.readString();

  serX.write(dataX(serialData));
  serY.write(dataY(serialData));
  
}

int dataX(String data){
  data.remove(data.indexOf("Y"));
  data.remove(data.indexOf("X"), 1);

  return data.toInt();
}

int dataY(String data){
  data.remove(0, data.indexOf("Y") + 1);
  
  return data.toInt();
}
