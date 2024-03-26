### Author: Arun Thathachary 3/20/2024
### Ref: https://earthly.dev/blog/makefile-variables/
###		 https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
###		 https://makefiletutorial.com/#conditional-ifelse 

SOURCES = writer.c ### eg: hello.c helper.c
OBJS = $(SOURCES:.c=.o) ### define .o names for each .c name
TARGET = writer ### target file to be compiled

CROSS_COMPILE = ### define empty flag - to be provided from the terminal
CC = ${CROSS_COMPILE}gcc  ### compiler - concatenate with gcc
OPTS = -Wall ### flags
#LIBS = -lm ### libraries - not required at the moment

$(TARGET): $(OBJS)
#	$(CC) -o $(TARGET) $(OBJS) $(LIBS)
	$(CC) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

### check if CROSS_COMPILE flag is empty/specified. print message
ifeq ($(CROSS_COMPILE),)
	@echo "CROSS_COMPILE flag not specified. Running default native compile"
else
	@echo "CROSS_COMPILE specified as ${CROSS_COMPILE}"
endif

clean:
	rm -f $(OBJS) $(TARGET)