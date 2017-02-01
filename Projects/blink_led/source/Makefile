CC      =  avr-gcc
CFLAGS  =  -mmcu=atmega2560 -DF_CPU=16000000UL -O0 -c
LDFLAGS =  -mmcu=atmega2560

all: main.c
	$(CC) $(CFLAGS) -o main.o main.c
	$(CC) $(LDFLAGS) -o main main.o
	avr-objcopy -O ihex -R .eeprom main main.hex

clean:
	-rm main.o main

flash:
	sudo avrdude -D -F -V -c wiring -p m2560 -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex
