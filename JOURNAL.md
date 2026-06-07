---
title: "Harvest AI"
author: "Akshay Shah"
description: "A smart countertop station that uses an integrated camera and weight sensor to automatically identify my garden produce, calculate its exact harvest yield, and track my lifetime grocery savings on a live web dashboard."
created_at: "2026-06-07"
---

# June 7th: Create Project and Spend Time Reasearching Parts and Designing the overall system 

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
