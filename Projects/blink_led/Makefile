PROJNAME =  blink_led

# Directories
SRCDIR   =  source
BUILDDIR =  build
OBJDIR   =  $(BUILDDIR)/obj
BINDIR   =  $(BUILDDIR)/bin

# Files to build
OBJS     =  $(addprefix $(OBJDIR)/, main.o)
ELF      =  $(BINDIR)/$(PROJNAME)
HEX      =  $(BINDIR)/$(PROJNAME).hex

# Building helpers
CC       =  avr-gcc
CFLAGS   =  -mmcu=atmega2560 -DF_CPU=16000000UL -O1 -c
LDFLAGS  =  -mmcu=atmega2560


# Implicit rules
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo Building file: $@
	@$(CC) $(CFLAGS) -o $@ $^


# File rules
all: $(HEX)

$(HEX): $(ELF) | $(BINDIR)
	@echo Building file: $(HEX)
	@avr-objcopy -O ihex -R .eeprom $(ELF) $(HEX) 

$(ELF): $(OBJS) | $(BINDIR)
	@echo Building file: $(ELF)
	@$(CC) $(LDFLAGS) -o $(ELF) $(OBJS)

$(OBJS): | $(OBJDIR)


# Directory rules
$(BINDIR): | $(BUILDDIR)
	@echo Creating folder: $(BINDIR)
	@mkdir $(BINDIR)

$(OBJDIR): | $(BUILDDIR)
	@echo Creating folder: $(OBJDIR)
	@mkdir $(OBJDIR)

$(BUILDDIR):
	@echo Creating folder: $(BUILDDIR)
	@mkdir $(BUILDDIR)


# Helper rules
clean:
	@echo Deleting folder: $(BUILDDIR)
	@-rm -r -f $(BUILDDIR)

flash:
	sudo avrdude -D -F -V -c wiring -p m2560 -P /dev/ttyACM0 -b 115200 -U flash:w:$(HEX)
