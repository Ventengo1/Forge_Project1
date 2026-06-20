# Harvest AI
Harvest AI is a smart countertop station designed to track garden produce. By combining an integrated camera feed with a load cell weight sensor, the system automatically detects when you drop a fresh harvest onto the platform, identifies the vegetable, logs its exact weight, and calculates your running lifetime grocery savings on a live web dashboard.

I built this so I could see a direct timeline of my garden yields and track exactly how much money the backyard garden is saving me over time. Or for that matter, if it is actually saving me money...


Wired up diagram:
<img width="417" height="363" alt="image" src="https://github.com/user-attachments/assets/50a4d835-efab-4d9f-8bac-f0f502c988db" />

Heres a overview of the system:

1. Hardware (ESP32 CAM + HX711): Reads raw analog data from a load cell scale and captures a snapshot frame, then sends both metrics directly over local Wi-Fi.

2. Backend Server (Node.js + Express): Catches the inbound frame, commits the picture to a local cache folder, and synchronizes the weight/crop logs into Supabase cloud database. 

3. Frontend Dashboard (HTML + Tailwind + Chart.js): Pulls live entries straight from Supabase to automatically draw visual history timelines and update the yield analytics counters


Gemini had to help me with the BOM in the readme below, I didn't know how to put it there.

## Bill of Materials (BOM)

| Item | Component | Purpose | Cost | Links |
| --- | --- | --- | --- | --- |
| **Core Electronics** | ESP32-CAM Board Bundle | Microcontroller + Camera + Wi-Fi | $15.00 | [Amazon](https://www.amazon.com/dp/B0CJJHXD1W) |
| **Core Electronics** | HX711 ADC Amplifier Module | Translates analog weight pressure into digital signals | $6.00 | [Amazon](https://www.amazon.com/dp/B010FG9RXO) |
| **Core Electronics** | 5kg Scale Load Cell Bar | Aluminum alloy to weigh up to 11 lbs of produce | $8.00 | [Amazon](https://www.amazon.com/dp/B010FG9RXO) |
| **Core Electronics** | 0.96-inch I2C OLED Display | Screen to show real-time feedback like weight and status | $6.00 | [Amazon](https://www.amazon.com/dp/B072Q2X2LL) |
| **Core Electronics** | 18650 Battery Expansion Shield | Provides cordless 5V power and handles onboard charging | $7.50 | [Amazon](https://www.amazon.com/dp/B07K7GZ2RK) |
| **Prototyping & Connections** | M-F & F-F Jumper Wires | Connects modules together and makes everything work | $5.00 | *Local / On Hand* |
| **Prototyping & Connections** | Solderless Breadboard | For initial testing and layout mapping | $4.00 | *Local / On Hand* |
| **Mechanical Enclosure** | Rigid Scale Base Plates (x2) | Acrylic or wood sheets to sandwich the load cell | $8.00 | [Amazon](https://www.amazon.com/dp/B0D5QCC74J) |
| **Mechanical Enclosure** | Overhead Mounting Support | Wood dowel, pipe, or 3D print to hold camera over scale | $4.00 | *Local / DIY* |
|  |  | **Total Project Cost** | **$64.50** |  |


