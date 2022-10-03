#define pindata 3
#define Led 6

const int buttonPin = 2;

int buttonState = 0;
int variable_buttonState = 0;

void setup() {

Serial.begin(9600);

pinMode(buttonPin, INPUT);
pinMode(pindata, OUTPUT);
pinMode(Led, OUTPUT);

}

void loop(){

buttonState = digitalRead(buttonPin);

if (buttonState == HIGH) {
variable_buttonState = !variable_buttonState;
  delay(300);
}


if (variable_buttonState == 1) {
    digitalWrite(pindata, HIGH);
    pinMode(pindata, INPUT);

    digitalWrite(Led, HIGH);
}

else {
    digitalWrite(Led-1, LOW);
    
    pinMode(pindata, OUTPUT);
    delay(100);
}

Serial.print(variable_buttonState);

}
