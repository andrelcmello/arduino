CC      =  avr-gcc
CFLAGS  =  -mmcu=atmega2560 -DF_CPU=16000000UL -O0 -c
LDFLAGS =  -mmcu=atmega2560

all: main.hex

main.hex: main
	avr-objcopy -O ihex -R .eeprom main main.hex

main: main.o
	$(CC) $(LDFLAGS) -o main main.o

main.o: main.c
	$(CC) $(CFLAGS) -o main.o main.c

clean:
	-rm main.o main

flash:
	sudo avrdude -D -F -V -c wiring -p m2560 -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex
