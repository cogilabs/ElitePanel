
int i = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(i == 5) {
    Serial.print("a$");
  }
  Serial.print(i);
  Serial.print(" Hey!");
  i++;
  Serial.print("$");
  delay(5000);
}
