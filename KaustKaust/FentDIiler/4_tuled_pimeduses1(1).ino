int light = 0; // hoiustab praegune valguse tase
// https://projecthub.arduino.cc/DCamino/ambient-light-sensor-using-photo-resistor-and-led-lights-79c2ed
// https://www.tinkercad.com/things/74HmcGsVcdK/editel?returnTo=%2Fdashboard
void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
}

void  loop() {
    light = analogRead(A0);  // loeb ja salvestab asju PR seest
    
    Serial.println(light); // prindib praeguse valguse taseme
 
    if(light > 450) { // Kui on valge
        Serial.println("On valje");
        digitalWrite(13,LOW); // lülita vasakpoolne LED välja
        digitalWrite(12,LOW);  // lülita parempoole LED välja
    }
    else if(light > 229 && light < 451) { // Kui on tavaline valgus
        Serial.println("Tava valgus, ära raiska minu aega!");
       digitalWrite(13, HIGH); // lülita vasakpoolne LED peale
       digitalWrite(12,LOW);  // lülita parempoole LED välja
    }
    else { // Kui on pime
        Serial.println("Pime on!");
        digitalWrite(13,HIGH); // lülita vasakpoolne LED tööle
        digitalWrite(12,HIGH);  // lülita parempoolne LED tööle
    }
    delay(1000); // ära spämmi raisk
}