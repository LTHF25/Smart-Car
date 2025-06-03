# 🚗 Smart RC Car - Arduino Based

[![Arduino](https://img.shields.io/badge/Arduino-UNO-blue.svg)](https://www.arduino.cc/)
[![Bluetooth](https://img.shields.io/badge/Bluetooth-HC--05-green.svg)](https://github.com/yourusername/smart-rc-car)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Version](https://img.shields.io/badge/Version-1.0.0-red.svg)](CHANGELOG.md)

> **Proyek Smart RC Car yang dapat dikontrol melalui smartphone menggunakan koneksi Bluetooth**

## 📋 Daftar Isi

- [🎯 Deskripsi Proyek](#-deskripsi-proyek)
- [⚡ Komponen Utama](#-komponen-utama)
- [🔧 Instalasi](#-instalasi)
- [🎮 Cara Penggunaan](#-cara-penggunaan)
- [📱 Aplikasi Mobile](#-aplikasi-mobile)
- [🔌 Skema Rangkaian](#-skema-rangkaian)
- [💻 Kode Program](#-kode-program)
- [🚀 Fitur](#-fitur)
- [🔍 Troubleshooting](#-troubleshooting)
- [📸 Galeri](#-galeri)
- [🤝 Kontribusi](#-kontribusi)
- [📄 Lisensi](#-lisensi)

## 🎯 Deskripsi Proyek

Smart RC Car adalah proyek IoT sederhana yang memungkinkan pengguna untuk mengendalikan mobil RC menggunakan smartphone melalui koneksi Bluetooth. Proyek ini menggunakan Arduino UNO sebagai mikrokontroler utama dan berbagai komponen elektronik untuk menciptakan pengalaman kontrol yang responsif dan menyenangkan.

### ✨ Keunggulan
- **Kontrol Nirkabel**: Menggunakan Bluetooth untuk komunikasi
- **Responsif**: Kontrol real-time tanpa delay
- **Mudah Digunakan**: Interface sederhana di smartphone
- **Ekonomis**: Menggunakan komponen yang terjangkau
- **Modular**: Dapat dikembangkan dengan fitur tambahan

## ⚡ Komponen Utama

### 🔋 1. Baterai LiPo (Lithium Polymer)
- **Fungsi**: Sumber daya listrik utama untuk seluruh sistem
- **Spesifikasi**: 7.4V (2S) / 11.1V (3S)
- **Kapasitas**: 2200mAh (atau sesuai kebutuhan)
- **Keunggulan**: Ringan, berkapasitas besar, cocok untuk aplikasi mobile

### ⚡ 2. Step-down Regulator (10A Buck Converter)
- **Fungsi**: Menurunkan tegangan dari baterai LiPo ke 5V untuk Arduino
- **Input**: 6V - 24V
- **Output**: 5V (adjustable 3.3V - 12V)
- **Arus Maksimum**: 10A
- **Mengapa Penting**: Melindungi Arduino dari kelebihan tegangan

### 🚙 3. Motor Driver L298N
- **Fungsi**: Mengontrol arah dan kecepatan motor DC
- **Kapasitas**: 2 motor DC
- **Kontrol Arah**: IN1, IN2 (Motor A) & IN3, IN4 (Motor B)
- **Kontrol Kecepatan**: ENA & ENB (PWM)
- **Fitur**: Dapat mengatur maju, mundur, belok kiri/kanan

### 📶 4. Bluetooth Module HC-05
- **Fungsi**: Komunikasi nirkabel dengan smartphone
- **Protokol**: Bluetooth 2.0/2.1
- **Jangkauan**: ~10 meter (tanpa penghalang)
- **Komunikasi**: Serial (UART)
- **Tegangan**: 3.3V - 5V

### 🧠 5. Arduino UNO
- **Fungsi**: Mikrokontroler utama (otak sistem)
- **Prosesor**: ATmega328P
- **Tegangan**: 5V
- **Pin Digital**: 14 (6 PWM)
- **Pin Analog**: 6

### ⚙️ 6. Motor DC & Komponen Pendukung
- **Motor DC**: 2 buah untuk roda kiri dan kanan
- **Roda**: 4 buah (2 aktif, 2 pasif)
- **Chassis**: Frame mobil RC
- **Kabel Jumper**: Untuk koneksi antar komponen

## 🔧 Instalasi

### 📋 Persyaratan
- Arduino IDE versi 1.8.x atau lebih baru
- Smartphone Android dengan Bluetooth
- Aplikasi Bluetooth Terminal

### 🔗 Koneksi Hardware

```
Arduino UNO    →    Komponen
─────────────────────────────
5V             →    VCC (HC-05, L298N)
GND            →    GND (Semua komponen)
Pin 2          →    TX (HC-05)
Pin 3          →    RX (HC-05)
Pin 4          →    IN1 (L298N)
Pin 5          →    IN2 (L298N)
Pin 6          →    IN3 (L298N)
Pin 7          →    IN4 (L298N)
Pin 9          →    ENA (L298N)
Pin 10         →    ENB (L298N)
```

### 💾 Upload Kode
1. Buka Arduino IDE
2. Copy kode dari file `smart_rc_car.ino`
3. Pilih Board: Arduino UNO
4. Pilih Port yang sesuai
5. Upload kode ke Arduino

## 🎮 Cara Penggunaan

### 📱 Persiapan Smartphone
1. **Aktifkan Bluetooth** di smartphone
2. **Scan** dan **pair** dengan HC-05 (Password: 1234 atau 0000)
3. **Install** aplikasi Bluetooth Terminal
4. **Connect** ke HC-05 melalui aplikasi

### 🎯 Kontrol Gerakan
Kirim karakter berikut melalui aplikasi:

| Karakter | Fungsi | Gerakan |
|----------|--------|---------|
| `F` | Forward | Maju |
| `B` | Backward | Mundur |
| `L` | Left | Belok Kiri |
| `R` | Right | Belok Kanan |
| `S` | Stop | Berhenti |

### 🔄 Cara Kerja
1. Smartphone mengirim karakter kontrol via Bluetooth
2. HC-05 menerima dan meneruskan ke Arduino
3. Arduino memproses perintah
4. Motor driver menggerakkan motor sesuai perintah
5. Mobil bergerak sesuai kontrol

## 📱 Aplikasi Mobile

### 📲 Rekomendasi Aplikasi
- **Arduino Bluetooth Controller**
- **Bluetooth Terminal**
- **Serial Bluetooth Terminal**
- **Bluetooth Electronics**

### 🎨 Custom App (Opsional)
Anda dapat membuat aplikasi Android sendiri menggunakan:
- **MIT App Inventor**
- **Android Studio**
- **Flutter**

## 🔌 Skema Rangkaian

```
                    ┌─────────────────┐
                    │   Baterai LiPo  │
                    │    7.4V/11.1V   │
                    └─────────┬───────┘
                              │
                    ┌─────────▼───────┐
                    │  Step-down      │
                    │  Regulator      │
                    │  (Buck 5V)      │
                    └─────────┬───────┘
                              │
              ┌───────────────┼───────────────┐
              │               │               │
    ┌─────────▼───────┐   ┌───▼────┐   ┌─────▼─────┐
    │   Arduino UNO   │   │ HC-05  │   │  L298N    │
    │                 │   │        │   │           │
    │ Pin 2 ────────────── RX     │   │ IN1-IN4   │
    │ Pin 3 ────────────── TX     │   │ ENA-ENB   │
    │ Pin 4-7 ──────────────────────── IN1-IN4   │
    │ Pin 9-10 ─────────────────────── ENA-ENB   │
    └─────────────────┘   └────────┘   └─────┬─────┘
                                             │
                                    ┌────────▼────────┐
                                    │   Motor DC      │
                                    │   Kiri & Kanan  │
                                    └─────────────────┘
```

## 💻 Kode Program

### 📄 File Utama: `smart_rc_car.ino`
```cpp
#include <SoftwareSerial.h>

// Bluetooth HC-05
SoftwareSerial bluetooth(2, 3); // RX, TX

// Motor Driver L298N
const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 7;
const int ENA = 9;
const int ENB = 10;

// Kecepatan motor (0-255)
const int SPEED = 200;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  // Setup motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  // Set initial speed
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);
  
  Serial.println("Smart RC Car Ready!");
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();
    Serial.print("Command: ");
    Serial.println(command);
    
    executeCommand(command);
  }
}

void executeCommand(char cmd) {
  switch(cmd) {
    case 'F': // Forward
      moveForward();
      break;
    case 'B': // Backward
      moveBackward();
      break;
    case 'L': // Left
      turnLeft();
      break;
    case 'R': // Right
      turnRight();
      break;
    case 'S': // Stop
      stopMotors();
      break;
    default:
      Serial.println("Unknown command");
  }
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Moving Forward");
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Moving Backward");
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Turning Left");
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Turning Right");
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Motors Stopped");
}
```

## 🚀 Fitur

### ✅ Fitur Saat Ini
- [x] Kontrol dasar (Maju, Mundur, Kiri, Kanan, Stop)
- [x] Komunikasi Bluetooth
- [x] Kontrol kecepatan motor
- [x] Status monitoring via Serial Monitor

### 🔄 Pengembangan Selanjutnya
- [ ] Sensor ultrasonik untuk obstacle avoidance
- [ ] Kamera untuk FPV (First Person View)
- [ ] Sensor accelerometer untuk stabilitas
- [ ] LED indicator untuk status
- [ ] Buzzer untuk alarm
- [ ] Mode autopilot sederhana

## 🔍 Troubleshooting

### ❌ Masalah Umum & Solusi

#### 1. **Bluetooth tidak bisa connect**
- ✅ Pastikan HC-05 sudah dipair dengan smartphone
- ✅ Cek password default: 1234 atau 0000
- ✅ Restart Bluetooth di smartphone

#### 2. **Motor tidak bergerak**
- ✅ Cek koneksi kabel ke motor driver
- ✅ Pastikan baterai terisi penuh
- ✅ Periksa tegangan output step-down regulator

#### 3. **Arduino tidak merespon**
- ✅ Periksa koneksi TX/RX HC-05 ke Arduino
- ✅ Buka Serial Monitor untuk debug
- ✅ Pastikan baud rate sesuai (9600)

#### 4. **Gerakan tidak sesuai perintah**
- ✅ Cek konfigurasi pin motor driver
- ✅ Periksa kondisi motor DC
- ✅ Pastikan karakter perintah sesuai (F/B/L/R/S)

### 🔧 Tips Optimasi
- Gunakan baterai LiPo dengan kapasitas sesuai kebutuhan
- Tambahkan kapasitor untuk mengurangi noise motor
- Gunakan kabel berkualitas baik untuk koneksi
- Lakukan kalibrasi kecepatan motor jika perlu

## 📸 Galeri

### 🖼️ Foto Komponen
```
/images/
├── components/
│   ├── arduino_uno.jpg
│   ├── hc05_bluetooth.jpg
│   ├── l298n_motor_driver.jpg
│   ├── lipo_battery.jpg
│   └── step_down_regulator.jpg
├── assembly/
│   ├── wiring_diagram.jpg
│   ├── assembled_car.jpg
│   └── testing_setup.jpg
└── demo/
    ├── mobile_app_screenshot.jpg
    └── car_in_action.gif
```

### 🎥 Video Demo
- [Demo Kontrol Dasar](link-to-video)
- [Proses Assembly](link-to-video)
- [Troubleshooting Guide](link-to-video)

## 🤝 Kontribusi

Kontribusi sangat diterima! Silakan fork repository ini dan buat pull request untuk:

### 🌟 Cara Berkontribusi
1. **Fork** repository ini
2. **Buat branch** fitur baru (`git checkout -b feature/AmazingFeature`)
3. **Commit** perubahan (`git commit -m 'Add some AmazingFeature'`)
4. **Push** ke branch (`git push origin feature/AmazingFeature`)
5. **Buat Pull Request**

### 💡 Ide Kontribusi
- Menambah sensor baru
- Optimasi kode
- Membuat aplikasi mobile yang lebih baik
- Dokumentasi yang lebih lengkap
- Tutorial video

## 📞 Kontak & Dukungan

### 👨‍💻 Developer
- **Nama**: Luthfi
- **Email**: [your-email@domain.com]
- **GitHub**: [@yourusername]
- **LinkedIn**: [your-linkedin-profile]

### 💬 Komunitas
- **Discord**: [Smart RC Car Community]
- **Telegram**: [Smart RC Car Group]
- **Forum**: [Arduino Indonesia Forum]

## 📄 Lisensi

Proyek ini dilisensikan under **MIT License** - lihat file [LICENSE](LICENSE) untuk detail.

```
MIT License

Copyright (c) 2024 Luthfi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## 🙏 Acknowledgments

- **Arduino Community** - Untuk platform dan dukungan
- **ESP32/Arduino Forums** - Untuk troubleshooting dan tips
- **GitHub Community** - Untuk hosting dan collaboration tools
- **YouTube Tutorials** - Untuk inspirasi dan pembelajaran

---

<div align="center">

### ⭐ Jika proyek ini membantu, berikan bintang ya!

**Made with ❤️ by Luthfi**

[⬆️ Kembali ke atas](#-smart-rc-car---arduino-based)

</div>