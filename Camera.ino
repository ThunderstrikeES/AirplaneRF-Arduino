
#define pindata 3
#define pinbutton A5

void setup() {
Serial.begin(9600);
pinMode(pindata, OUTPUT);

}

void loop() {


if (Serial.read() == "2") {

    digitalWrite(pindata, HIGH);
    pinMode(pindata, INPUT);
      delay(10000); // Duración del vídeo
    pinMode(pindata, OUTPUT);
      delay(100);
    pinMode(pindata, INPUT);
}
}
