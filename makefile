LIBS 	= 
CFLAGS	= -Wall -I inc
LDFLAGS	= -rcs
CC	= gcc   # compiler name
LD	= ar

TARGET	= libcircularbuffer.a

OBJ := $(patsubst %.c,%.o,$(wildcard src/*.c))

all: $(TARGET) 


$(TARGET): $(OBJ)
	$(LD) $(LDFLAGS) -o $@ $(OBJ) $(LIBS)
	
src/%.o : src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)
clean:
	rm -f $(TARGET)  $(OBJ) #This way is cleaner than your clean

install:
	cp $(TARGET) /lib/
	cp inc/circular_buffer.h /usr/include/

uninstall:
	rm /lib/$(TARGET)
	cp /usr/include/circular_buffer.h
