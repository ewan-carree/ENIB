const int pin2 = 2;
const int pinA0 = A0;
float maxi=0;
float mini=0;
int count = 0;
bool etat = digitalRead(pin2);

void setup() {
  pinMode(pin2,INPUT);
  digitalWrite(pin2,LOW);
  Serial.begin(9600);
}

int potar(){
  int valeurPotar = analogRead(pinA0);
  return valeurPotar;
}

float mappage(int valeurPotar){
  float tension = (valeurPotar*5.0)/1023.0;
  return tension;
}

void display(){  
  while (!etat && count==0){
    etat = digitalRead(pin2);
    maxi = mappage(potar()); 
  }
  if (potar() == 1023){
    count=1;
  }
  
  while (etat && count==1){
    etat = digitalRead(pin2);
    mini = mappage(potar());
  } 
  if (potar() == 0 && count==1){
    count=2;
  }
    
  if (count==2){
    Serial.print("Le 0 logique correspond a une tension mini de 0V et maxi de "); Serial.print(mini); Serial.println("V");
    Serial.print("Le 1 logique correspond a une tension mini de "); Serial.print(maxi); Serial.println("V et maxi de 5V");
    Serial.println();
    count=0;
  }
}

void loop() {
  display();
}





