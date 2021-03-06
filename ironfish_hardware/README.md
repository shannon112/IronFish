# ironfish_hardware
This folder is for the robot hardware info. No code inside.  
**But,** make sure that you have followed the tutorial below to establish connection with your controllers  
before implementing ros on it.

## Appearence
<img src="https://i.imgur.com/oY3Imbg.png" width="400"> <img src="https://i.imgur.com/fsRahLl.png" width="400"> 
<img src="https://i.imgur.com/SuPGbef.jpg" width="400"> <img src="https://i.imgur.com/l7LderM.png" width="300">

## Materials
|#| Item                               | Spec name                  | Ref / Remarks   |
|-| ---------------------------------- | -------------------------  | -------- |
|A| Laptop * 1            | YOURS     | Ubunut16.04 & ROS kinetic environment is recommended  |
|B| Motion controller * 2 | Faulhaber MCDC 3006 S RS   | https://drive.google.com/drive/folders/1DKgq1ITcUMww3H3-kriDh9FNR-PY3Cgm?usp=sharing     |
|C| DC-Micromotors * 2    | Faulhaber 2657W024CR      | https://drive.google.com/drive/folders/1bG2t3RO65lxccGH9DnF-CN5II5Syyg2p?usp=sharing     |
|D| Encoder * 2 | Faulhaber Incremental encoder Series IE3-512 | Same as C     |
|E| Gearheads * 2 | Faulhaber Planetary Gearheads Series 26/1 43-1 | Same as C     |
|F| Scanning Rangefinder * 1  | Hokuyo URG-04LX-UG01  |  https://drive.google.com/drive/folders/1AfirbEaHy5gv8004uOnOZeE3WCbf11Sa?usp=sharing     |
|G| RGB-D Camera * 1     | Intel Realsense D435     | https://drive.google.com/drive/folders/19zL03yQC1dr7TytkH7gSz8V8WhdSbO7P?usp=sharing     |
|H| RS232-USB adapter wire * 1   | OnePing OP-1020-PCAM1PJ  | https://drive.google.com/drive/folders/1uPQWRpJJQQIh6ZeSIjmJu8m3Tci86CJD?usp=sharing     |
|I| Battery 25.6V 5.6Ah * 1|  18650 battery pack  | https://drive.google.com/drive/folders/1jFFBTxFVX7ok8Z7qQUKVdkUe1ItO6g4X?usp=sharing     |
|J| Regulator * 2     | LM2596 LM2596S     | 25.6->12V to kinect and meters / 25.6->5V to usb hub    |
|K| USB3.0 HUB * 1     | https://drive.google.com/drive/folders/1qxdRvp6AEbokOa-jauzLfaD-camSwtRR?usp=sharing     | At least having 4 ports, and independent power line   |
|L| MiniUSB wire * N     | Any~     | Connect to Hokuyo     |
|M| MicroUSB wire * N     | Any~     | Connect to Camera      |
|N| Wire * N     | Any~     | -     |
|O| Terminal Socket * 1 | Any~     | -     |
|P| RS232 adapter * 1 | null modem DCE-DCE   | https://drive.google.com/open?id=1Pn5CrrlS4PzhgkqS9_Uuz6B_8ALD5fnF     |
|Q| Switch * 1 | any   | for emergency stop     |
|R| RGB-D Camera * 1     | Microsoft Kinect 1414  |  https://www.evernote.com/shard/s315/sh/66dd6958-0004-4f01-adf3-c85db65ba50b/0391136fb9a61bebaf4f77235412f5ee   |
|S| USB multimeter * 1 | aibo PMT031 | - 
|T| Ampere meter * 1 | - | https://drive.google.com/file/d/1ynRALMMktycoePIaTkB1DrEn-dkggC0r/view?usp=sharing 
|U| Voltmeter * 1 | - | https://drive.google.com/file/d/1ynRALMMktycoePIaTkB1DrEn-dkggC0r/view?usp=sharing 


## Wiring v3
<img src="https://github.com/shannon112/IronFish/blob/master/ironfish_hardware/wiring.png" width="600">

## Simple test of communicating with controller
Plugin wire's rs232 side to controller and usb side to your laptop. See if you can get a message of connecting new plugin device to ttyUSB0. If you do not see it, you may need to install the driver of that rs232-USB wire.
```
dmesg
```
Add group to get the authorization of hardware connected on your linux machine.  
This avoids issues for ttyUSB# or ttyACM# permissions.
```
sudo usermod -a -G dialout <username>
```
You must log out and then log in again for this to take effect. Check if it works:
```
id -Gn
```
Then, we need the tool "minicom" to directly send ascii data to controller
```
sudo apt-get install minicom
```
Set up the protocol parameters (do this only at the first time):
```
sudo minicom -s
(If you have set up the parameters, just type "minicom" in terminal. The minicom will be launched.)
```
1. Choose "**Serial port setup**", and the settings should be as the picture showed below.
2. Press Enter to finish and then choose "**Save setup as dfl**"
3. Choose "**Exit**", and the you will be in minicom.
4. Press "**Ctrl + a**". Next, release and press "**z**",  and then press "**e**" to enable echo on the screen.
5. You can send commands now.
```
en (Enable motors. The motors should output torque.)
1v100 (The motor of node 1 will move in 100rpm.)
v0 (Stop all the motors)
```

<img src="https://github.com/shannon112/IronFish/blob/master/ironfish_hardware/minicom_settings.png" width="600">
