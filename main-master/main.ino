#include <SoftwareSerial.h>

// Buat objek serial untuk HC-05 di pin 3 (RX), 2 (TX)
SoftwareSerial bluetooth(3, 2); // RX 2, TX 3

char command;
int speed = 200;

// Pin motor
const int enA = 5;
const int in1 = 6;
const int in2 = 7;
const int in3 = 9;
const int in4 = 10;
const int enB = 11;

void setup() {
  Serial.begin(9600);         // Untuk komunikasi ke PC
  bluetooth.begin(9600);      // Untuk komunikasi ke HC-05

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  stopMotor();

  Serial.println("Menunggu koneksi Bluetooth...");
}

void loop() {
  // Cek jika data diterima dari Bluetooth
  if (bluetooth.available()) {
    command = bluetooth.read();
    Serial.print("Dari Bluetooth: ");
    Serial.println(command);

    switch (command) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': turnLeft(); break;
      case 'R': turnRight(); break;
      case 'S': stopMotor(); break;
      default:
        Serial.println("Perintah tidak dikenal.");
        break;
    }
  }
}

void forward() {
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("Maju");
}

void backward() {
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("Mundur");
}

void turnLeft() {
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("Belok Kiri");
}

void turnRight() {
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("Belok Kanan");
}

void stopMotor() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("STOP");
}
