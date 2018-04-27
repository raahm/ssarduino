#define RESISTANCE 10000

int adc0; // for CA 1
int adc1; // for CA 2
int adc2; // for therm1
int adc3; // for therm2
int adc4; // for therm3
int adc5; // for tension

//int num avg

//int arr0[30];
//int arr1[30];
//int arr2[30];
//int arr3[30];
//int arr4[30];
//int arr5[30];

int i, adcVal1, adcVal2;
double thermRest1, thermRest2;
double temp1, temp2, tempf1, tempf2, tempAvg;

double tempCircumference, circumference;

void setup() {
  // put your setup code here, to run once:

//  pinMode(A0, INPUT);
//  pinMode(A1, INPUT);
//  pinMode(A2, INPUT);
//  pinMode(A3, INPUT);
//  pinMode(A4, INPUT);
//  pinMode(A5, INPUT);
//  analogReference(EXTERNAL);
  Serial.begin(9600);
  thermRest1 = 0;
  thermRest2 = 0;
  temp1 = 0;
  temp2 = 0;
  tempf1 = 0;
  tempf2 = 0;
  tempAvg = 0;
  tempCircumference = 0;
  circumference = 0;
  i = 1;
  adcVal1 = 0;
  adcVal2 = 0;

}

void loop() {
//  adc0 = analogRead(A0);
  adc1 = analogRead(A1);
  thermRest1 = RESISTANCE / ((1023.0 / adc1) - 1);
//  thermRest2 = RESISTANCE / ((1023.0 / adc1) - 1);
  temp1 = -22.63 * log(thermRest1)+206.8;
//  temp2 = -22.63 * log(thermRest2)+206.8;
  tempf1 = temp1 * 1.8 + 32;
//  tempf2 = temp2 * 1.8 + 32;
//  tempAvg = (tempf1 + tempf2) / 2;
  Serial.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\nTemperature:\t");
  Serial.println(tempf1);
//  Serial.print("rest1:\t");
//  Serial.println(thermRest1);
  Serial.print("adc:\t");
  Serial.println(adc1);

//  Serial.print("\n\n\n\n\n\n\n\ntemp2:\t");
//  Serial.println(tempf2);
//  Serial.print("rest2:\t");
//  Serial.println(thermRest2);
//  Serial.print("adc:\t");
//  Serial.println(adc1);

//  Serial.println("\n\n\n\n\n\n\n\n\n\n\n\nTemperature:");
//  Serial.println(tempAvg);
  //second order polynomial
  // y = .001513231441121x^2-2.238437260225210x+827.040640269862

  // linear progression
  // y = 0.128424683872337x - 98.346586267050600

  adcVal1 = analogRead(A0);
//  circumference = .001513231441121*(adcVal1*adcVal1) -2.238437260225210*adcVal1+827.040640269862;
  circumference = 0.128424683872337*adcVal1 - 98.346586267050600;
  circumference = circumference / 2;
  circumference = circumference + 7.3;
  if (circumference < 7.3) {
    circumference = 7.3;
  }
  circumference = 19.7 + circumference;
  Serial.println("\n\n\nElongation:");
  Serial.println(circumference);
  Serial.println("ADCVal");
  Serial.println(adcVal1);

  delay(1000);


}
