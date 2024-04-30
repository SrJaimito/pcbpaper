BUILD_DIR = ./build

CFLAGS = -O3

include app/pcb_generator/Makefile.pcb_generator

pcbpaper: app/main.c $(BUILD_DIR)/generator.o
	$(CC) $^ -o $@ $(CFLAGS)

