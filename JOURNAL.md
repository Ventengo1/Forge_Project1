---
title: "Harvest AI"
author: "Akshay Shah"
description: "A smart countertop station that uses an integrated camera and weight sensor to automatically identify my garden produce, calculate its exact harvest yield, and track my lifetime grocery savings on a live web dashboard."
created_at: "2026-06-07"
---

# June 7th: Create Project on Forge and Spend Time Reasearching Parts and the overall system 

Spent first 30 min reasearching parts needed and creating a simple list.
Looks like I'm gonna need:
- A microcontroller and camera --> proabably gonna go with ESP32 Cam Development Board Bundle
Pics:
Amazon:
<img width="929" height="395" alt="image" src="https://github.com/user-attachments/assets/fd555961-d2b1-4513-8d24-b1f5a9559340" />
Ebay:
<img width="923" height="444" alt="image" src="https://github.com/user-attachments/assets/e231b731-9d8f-4743-ba20-3af398dcc0aa" />

- Next gonna need a weight sensor --> probably gonna go with HX711 ADC Amplifier Module with a 5kg cell load bar (5kg will be more than enough for produce as just a bunch of veggies, beans, and leaves, that kinda thing)

Pics on amazon:
<img width="700" height="407" alt="image" src="https://github.com/user-attachments/assets/edacebb2-6549-47b0-8fb9-7ddb52c73789" />

- Next need a OLED Display for both testing and to tell user (me/my family) what is happening like what the weight is or if its sending the image

Pics from amazon:

<img width="715" height="226" alt="image" src="https://github.com/user-attachments/assets/5620e982-e1bc-4512-9442-b82320e30c06" />

#### Structural enclosure

- Base plates for scale: Two rigid panels, maybe acrylic sheets or plywood or something like this
- Mouting arm: Plastic pipe or small wooden dowel or 3d printed bracket --> really just to mount esp32 cam directly over center of scale paltform for photo analysis

#### Protoyping stuff/connections

- Male to Female Jumper wires
- Female to Female jumper wires
- Small solderless breadboard to prototype with
- Some type of power bank/battery for the device to use (will do more research on this below as so far looks like maybe need some type of converter/tranformer, step up/down)

###### Battery Research

Really 2 options for what I do:

1. Use a USB power bank like one for phone
   - simple to use
   - easy to find
   - but won't look great

2. Use an 18650 battery shield module
   - looks a lot better
   - will fit nice a snugly in enclosure
   - can charge and then use like a power bank
   - harder to wire up and work with --> not just plug in a use


**Total time spent: 1.25 hours**

# June 7th: Work to create BOM, find accurate prices for all items, and finalize my list

My new bom is in this file: https://github.com/Ventengo1/Harvest-AI/blob/main/BOM.csv

In it added all the items with my accurate approximate prices, prices my change and places I buy may but hopefully pretty close. 

Gotta go now and add the links to some. 

Just added links to them, so now it should follow all the guidelines on forge website.

#### Spent a lot of time working through errors like this: We can make this file beautiful and searchable if this error is corrected: It looks like row 12 should actually have 5 columns, instead of 4 in line 11. But made it through


Finsished BOM for now:

<img width="940" height="373" alt="image" src="https://github.com/user-attachments/assets/9e07ed48-ee73-45c7-a526-f0034c5098aa" />


**Total time spent: 0.6 hours**

# June 8th: Creating an online diagram/blueprint of the electronics all wired up and maybe even code it

- Use wowki with ESP32 to try to build wiring map and blueprint
- Added ESP32 as they don't have the cam but pretty close, Added SSD1306, added the weight sensor which had bar too

<img width="1915" height="978" alt="image" src="https://github.com/user-attachments/assets/be2b534c-42a1-4b0f-bca5-75856dc9a3ef" />

Now gonna wire it all up and figure all of this out before hand so that later I don't need to when I build it.

1. Start off by wiring up the four OLED pins to the ESP32
GND ──> ESP32 GND

VCC ──> ESP32 3V3

SCL ──> ESP32 14

SDA ──> ESP32 15

<img width="260" height="317" alt="image" src="https://github.com/user-attachments/assets/b7bd6cde-7955-4ff2-9107-cb6cef6f10ae" />

2. Wire up the HX711 to ESP32

ND ──> ESP32 GND

VCC ──> ESP32 5V 

DT (Data) ──> ESP32 D4 

SCK (Clock) ──> ESP32 D2 

<img width="391" height="306" alt="image" src="https://github.com/user-attachments/assets/743d807c-3e17-41a0-9fbe-84d1e05ce04c" />

#### Now gonna add in libraries and some basic code

Libaries:

<img width="933" height="440" alt="image" src="https://github.com/user-attachments/assets/db7113ce-7668-4888-abfe-fec3ab5d5394" />

Now I will write up some code and have it test to make sure everything is working. 
<img width="930" height="397" alt="image" src="https://github.com/user-attachments/assets/32719ecf-e106-439d-955f-4694408b73c3" />

The code will display the weight and initilaize everything and tell me any issues/errors if they arise.

<img width="937" height="443" alt="image" src="https://github.com/user-attachments/assets/db7400da-1568-49b3-8a23-50c84dd6520e" />

Link to full design: https://wokwi.com/projects/466259968212112385


**Total time spent: 1.25 hours**







