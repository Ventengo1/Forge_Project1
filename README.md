# Harvest AI
Harvest AI is a smart countertop station designed to track garden produce. By combining an integrated camera feed with a load cell weight sensor, the system automatically detects when you drop a fresh harvest onto the platform, identifies the vegetable, logs its exact weight, and calculates your running lifetime grocery savings on a live web dashboard.

I built this so I could see a direct timeline of my garden yields and track exactly how much money the backyard garden is saving me over time. Or for that matter, if it is actually saving me money...


Wired up diagram:
<img width="417" height="363" alt="image" src="https://github.com/user-attachments/assets/50a4d835-efab-4d9f-8bac-f0f502c988db" />

Heres a overview of the system:

1. Hardware (ESP32 CAM + HX711): Reads raw analog data from a load cell scale and captures a snapshot frame, then sends both metrics directly over local Wi-Fi.

2. Backend Server (Node.js + Express): Catches the inbound frame, commits the picture to a local cache folder, and synchronizes the weight/crop logs into Supabase cloud database. 

3. Frontend Dashboard (HTML + Tailwind + Chart.js): Pulls live entries straight from Supabase to automatically draw visual history timelines and update the yield analytics counters


