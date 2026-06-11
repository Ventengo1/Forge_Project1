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

# June 9th, 2026: Create and Code the online web dashboard which will display all the stats and more

So decided to make this like a website which through the ESP32 Wifi module should work out.

Gonna make it in html, css, and jss like a normal website so it both functions well and looks good.

Decied to just use one of the free online compilers to make this easy.
<img width="946" height="493" alt="image" src="https://github.com/user-attachments/assets/061d233e-198b-4198-81b0-fa0f5e86cc3b" />

###### Disclaimer: Worked on code myself but used AI to help me out with it/make it better. 

Basic html/css/js: <img width="407" height="406" alt="image" src="https://github.com/user-attachments/assets/fcfd0a6f-b984-48e3-9256-679b0591d668" />

I was going to split into 3 seperate files but to keep it all easy gonna have in 1 html file.
AI helped me out with this.

ALso read documentation to make it work.

Realized part of way through that the C++ code in sketch.ino would need to change too so changed that too. AI helped me out with this too, but I did good amount on own.

Started off with placeholders and stuff but then changes to actaully check the real data every 2 seconds and use that.

Added the key feature which is the image recongiton/functionality
- With AI we added a hidden canvas to convert camera frames into Base64 text strings
- I used Hack Club AI to connect with the api to actually see, indentify, and analyze the health and amount of food/produce

In the sketch.ino file:
- Added WiFI and Web Stacks so that ESP32 can talk to local network instead of just logging to a computer screen --> Key for full fucntionality and web dashboard
- Added so that it turns on, congirues camera, and captures nice clean JPEG pic
- Reworte main loop to automaically snap photo every 10 sec and stream over network

<img width="952" height="464" alt="image" src="https://github.com/user-attachments/assets/86872af5-c6e8-4367-bbff-30cf31013e8f" />

Overall took about 1.5 hrs with 50 min for dashboard and documention reasearch etc, 30 min for ino change, and like 15 ish min for the hack club ai stuff

**Total time spent: 1.6 hours**

# June 9th, 2026: Setting up Supabase Database to store data so doesn't get erased

So decided to use supabase after doing reasearch to store data easily.

So first started off by creating a supabase database that will be stored as close as possible.

<img width="920" height="475" alt="image" src="https://github.com/user-attachments/assets/803aab3f-ce3b-4a1c-ab02-834e03cbff58" />

Next went and created a table that works for me:
<img width="959" height="419" alt="image" src="https://github.com/user-attachments/assets/0bb6b690-7a7b-44f6-9128-153b03af2990" />

After this worked with AI to help me get the code and added it to my html file to help make it all work.

Html file changes:

- Added the Supabase browser library via CDN and replaced the local mock variables with a live connection that automatically reads and updates stats, charts, and history cards directly from cloud database

- Added a new background function (saveHarvestToSupabase) that hooks directly into Hack Club AI loop, instantly saving the crop name, weight, and health analysis into permanent database rows every time an item is scanned

**Total time spent: 1.25 hours**



# June 11th, 2026: Setting up a local Node server to handle camera uploads

Decided to code a local backend server using Node.js to bridge the gap between the camera hardware and the dashboard before my physical parts get here

<img width="461" height="448" alt="image" src="https://github.com/user-attachments/assets/b26945db-dc16-41e1-a14b-1aaa2945a780" />


- Setup a new Node.js project environment and installed express and cors to manage network data (AI/web/googele overview helped me out with learning what to do)

 <img width="452" height="274" alt="image" src="https://github.com/user-attachments/assets/cc0310fb-99ac-4b04-95f5-2e881d485c3f" />
 
- Used express to listen on port 8080 so the hardware has a place to send data over my home network
  
- Configured body-parser to accept raw binary images so it can process JPEG photo data from the ESP32 camera without crashing
  
- Programmed an automatic folder creation script to safely hold onto incoming snapshots on my computer
  
- Added a file cleanup system that auto deletes the last image whenever a new one comes in so my hard drive doesn't fill up with random frames
  
- Built a POST endpoint  so the ESP32-CAM can upload frames wirelessly
  
- Created a GET endpoint so my html dashboard page can grab the latest picture and render it seamlessly

  Code file made in VS Code called server.js:

  <img width="958" height="599" alt="image" src="https://github.com/user-attachments/assets/452710b3-2c2d-44f5-95aa-4ddf049cd99b" />

<img width="460" height="509" alt="image" src="https://github.com/user-attachments/assets/d93280f2-bb4d-45f1-98cd-fd9e3a15db70" />



**Total time spent: 1 hour**


# June 11th, 2026: Testing out server I just made

So now I want to test out the server with a image or something

First gonna start off by testing the POST upload endpoint:
<img width="453" height="229" alt="image" src="https://github.com/user-attachments/assets/ff3ecc15-dabb-4c95-b033-49f16fa321e6" />

First to make all of this work had to convert and image from png to jpg and put into folder:
<img width="458" height="530" alt="image" src="https://github.com/user-attachments/assets/5e603c3f-002c-420b-8966-90e5cfa4bc0d" />

Gonna use AI to help me deug this issue:

<img width="458" height="481" alt="image" src="https://github.com/user-attachments/assets/de2f23c3-30d8-41c3-8eb0-e173ecb26d6b" />

Now gettign this error:

Invoke-WebRequest : Cannot bind parameter 'Headers'. Cannot
convert the "Content-Type: image/jpeg" value of type
"System.String" to type "System.Collections.IDictionary".
At line:1 char:17
+ curl -X POST -H "Content-Type: image/jpeg" --data-binary
"@test.jpg"  ...
+                 ~~~~~~~~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : InvalidArgument: (:) [Invoke-We
   bRequest], ParameterBindingException
    + FullyQualifiedErrorId : CannotConvertArgumentNoMessage,
   Microsoft.PowerShell.Commands.InvokeWebRequestCommand


IDK what's causing it but will figure it out.

It seems I may need to try bypass curl on windows as its acting up.

Been spending about 25 min and still getting issues. Gotta work through it though.

Finally got this:

PS C:\Users\ojas\harvest-ai-backend> curl.exe -X POST -H "Content-Type: image/jpeg" --data-binary "test.jpg" http://localhost:8080/upload-frame
Frame committed.
PS C:\Users\ojas\harvest-ai-backend>


Frame comitted! ---> Yay it worked

So now tried to open up the localhost web page for image to show up but not working.

An image icon is there but the actual image is not shown.

It seems there is another broken image.

Gonna try to redo the steps in a new terminal window.

Now back to getting issues like this:

<img width="464" height="230" alt="image" src="https://github.com/user-attachments/assets/7f3882ed-1cb1-4b5d-8e16-cd6e50af1e8a" />

Realized the file was test.jpg.jpg!!!!! NO!!!!

Found using this: <img width="446" height="208" alt="image" src="https://github.com/user-attachments/assets/5554fe62-53ec-432a-aa05-54421a96daa3" />


It will work now!!!


Yes it worked!!!!!!!!!!!!!!!!!!!!!!!!!!!

<img width="949" height="487" alt="image" src="https://github.com/user-attachments/assets/3f2294b8-15eb-426e-80ab-76bfac57774c" />\

**Total time spent: 1.5 hour**


# June 11th, 2026: Test out Dashboard UI with the server locally

First need to start the backend server again which I worked on earlier today and got working.

<img width="659" height="227" alt="image" src="https://github.com/user-attachments/assets/deb79489-d75f-46bc-b2dd-9c1674908e73" />

Now that it's running, gonna in the harvest local folder for project, create the html file to test for the dashboard.

<img width="956" height="551" alt="image" src="https://github.com/user-attachments/assets/8cb3559a-1689-4ee7-bbf7-1f0ec52a9f22" />

Created simple code with a bit of help from AI to just test and make sure everythign works in this new folder for the dashboard I made.

Now testing it with the image and got frame committed which means no more errors!!!

<img width="865" height="140" alt="image" src="https://github.com/user-attachments/assets/90ea6f1c-7b0d-43dc-ae83-c0c71f4b0ecb" />

Was able to get dashboard simpel html that I coded with this so I can confirm now that it should work with the full code and everything:

<img width="950" height="497" alt="image" src="https://github.com/user-attachments/assets/3c298761-0588-4126-99b3-1f714d0b9d89" />

Next probably gonna work on like the design for the physcial parts and everything else seems set.

**Total time spent: 0.6 hour**




















