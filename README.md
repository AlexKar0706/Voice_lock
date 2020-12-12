# Voice lock
This is part of the Arduino project for creating a voice lock. The purpose of this prototype is to connect the Arduino Nano BLE 33, which reads voice commands, with the Arduino Uno Rev3, which drives a servo motor to open and close the lock. Arduino Uno Rev3 is used for this part of the project. The second part of project is [here](https://github.com/nth-eye/VoiceCmd-tflite "here")
## Instruction
This project contains 2 files, one for connecting two prototypes directly(NonBluetoothLock.c), the other for connecting two prototypes via Bluetooth (BluetoothLock.c)
### BluetoothLock.c
Before using the program, it is necessary to configure the HC-05 module as a master device.
To do this, enter 2 commands into the module:
AT+ROLE=1
AT+CMODE=0

After that, it is necessary to find out the Mac address of the second device and connect 2 Bluetooth modules:
AT+BIND=85de,45,58be1d

After that, the program can be uploaded to the Arduino Uno
### NonBluetoothLock.c
Before uploading the program to the Arduino Uno, connect it to the Arduino Nano BLE 33 directly
