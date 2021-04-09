# Serial Keyboard

It's a keyboard that transmits serial. Or it's a 256-key keyboard, using 18 keys. Something like that. The main thing is that it transmits any serial byte.

## Notice

This repo contains a few files, but is mostly geared towards an unoptimized build with the internal structure consisting of 3(!) different PCBs. The SerialKeyboard.brd is just a 18-key keyboard with diodes. The DisplayCarrier.brd is an interposer between the Motherboard.brd, which is the only thing with active electronics. There's also an Arduino in there and the front panel, which makes for a grand total of five different PCBs in this project.

I have started work on a simplified version, MasterBoard.brd, which would combine this all into one single circuit board. This work is not completed.

If someone can find me a source of 2U 'Transmit' keycaps, I'll get right on that.

![render](https://github.com/bbenchoff/SerialKeybard/blob/main/Art/render.PNG)

![full pic](https://github.com/bbenchoff/SerialKeybard/blob/main/Art/baudboxFullPic.jpg)