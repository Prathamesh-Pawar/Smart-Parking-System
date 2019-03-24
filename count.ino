int pins[2]={D5,D6};
int i=0,j=0;

void setup(){
  Serial.begin(115200);
  pinMode(pins[0],INPUT);
  pinMode(pins[1],INPUT);

}

void loop(){
  pins[0]=digitalRead(D5);
  pins[1]=digitalRead(D6);

  if(pins[0]==LOW)
  {
    i+=1;
    Serial.println("Car is Entering");
    Serial.println(i);
    delay(1800);
      
  }
  do{
     pins[0]=digitalRead(D5);
  }
  while(pins[0]==LOW);

    if(pins[1]==LOW)
  {
    j+=1;
    Serial.println("Car is Leaving");
    Serial.println(j);
    delay(1800);
  }
  do{
    pins[1]=digitalRead(D6);
  }
  while(pins[1]==LOW);
}

