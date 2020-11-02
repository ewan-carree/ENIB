const int pin2 = 2;
const int pin2 = 2;
const int pinA0 = A0;
const int ve = 5;
double vd1=0,id1=0,vd2=0,id2=0;

void setup() {
  pinMode(pin2, INPUT);
  Serial.begin(9600);    

}

void r1000(double *vd1, double *id1) {
  int r = 1;
  int valeur = analogRead(A0);
  double vdtemp= 5*valeur;
  *vd1 = vdtemp/1023;
  double idtemp = ve-*vd1;
  *id1 = idtemp/r;
}

void r300(double *vd2, double *id2) {
  double r = 0.3;
  int valeur = analogRead(A0);
  double vdtemp= 5*valeur;
  *vd2 = vdtemp/1023;
  double idtemp = ve-*vd2;
  *id2 = idtemp/r;
}

double calculrd(double vd1,double vd2,double id1,double id2){
  double a = vd2-vd1;
  double b = id2-id1;
  a*=1000;
  double rd = a/b;
  return rd; 
}
double calculv0(double vd1, double id1, double rd){
  double a = rd*id1;
  a/=1000;
  double v0 = vd1-a;
  return v0;
}

void loop() {

  r1000(&vd1,&id1);
  
  
  bool etatBP1 = digitalRead(pin2);
  if (etatBP1){ 
    r300(&vd2,&id2);
    double rd = calculrd(vd1,vd2,id1,id2);
    double v0 = calculv0(vd1,id1,rd);
    Serial.print("La tension de seuil est de "); Serial.print(v0); Serial.println(" V");
    Serial.print("Et sa resistance dynamique est de "); Serial.print(rd); Serial.println(" Ohms");
    Serial.print("Les calculs ont ete effectues avec ces couples de valeurs (");Serial.print(id1);Serial.print(" mA ; ");Serial.print(vd1);Serial.print(" V) et (");Serial.print(id2);Serial.print(" mA ; ");Serial.print(vd2);Serial.println(" V)");
    Serial.println();
    delay(400);
  }
}
