import processing.serial.*;
Serial myPort;

void setup() {
  size(360, 360);
  frameRate(10);
  
  println(Serial.list());
  
  String portName = Serial.list()[2];
  println("portName:" + portName);
  myPort = new Serial(this, portName, 9600);
}

boolean isFirst = true;
int count = 0;

void draw() {
  background(0);
  text("press 'a', 'b', 'c', 'd', 'e', 'f' ", 10, height/2);
  
  //writeSomething
  if (key == 'a') {
    if(isFirst) {
      isFirst = false;
      myPort.write('A');
      println("shot!");
    }
    key = ' ';
  }
  else if (key == 's') {
    if(isFirst) {
      isFirst = false;
      myPort.write('B');
      println("shot!");
      
    }
    key = ' ';
  }
  else if (key == 'd') {
    if(isFirst) {
      isFirst = false;
      myPort.write('C');
      println("shot!");
    }
    key = ' ';
  }
  else if (key == 'f') {
    if(isFirst) {
      isFirst = false;
      myPort.write('D');
      println("shot!");
    }
    key = ' ';
  }
  else if (key == 'z') {
    if(isFirst) {
      isFirst = false;
      myPort.write('E');
      println("shot!");
    }
    key = ' ';
  }
  else if (key == 'x') {
    if(isFirst) {
      isFirst = false;
      myPort.write('F');
      println("shot!");
    }
    key = ' ';
  }
  
  println(key);
  println(count);
  
  ++count;
  
  if(count>65) {
    isFirst = true;
    count= 0;
  }
  
//  if(myPort.available()>0){
//    int inByte = myPort.read();
//    println(inByte);
//  }
  
}

