BUILD_DIR = build
TEST_DIR = test

CFLAGS = -O3 -g3

all: pcbpaper

include app/pcb_generator/Makefile.pcb_generator

pcbpaper: app/main.c $(BUILD_DIR)/generator.o $(BUILD_DIR)/cell.o $(BUILD_DIR)/component.o $(BUILD_DIR)/socket.o
	$(CC) $^ -o $@ $(CFLAGS)

test: $(TEST_DIR)/test_socket $(TEST_DIR)/test_component
	./$(TEST_DIR)/test_socket
	./$(TEST_DIR)/test_component

clean:
	rm -rf build/* test/* pcbpaper > /dev/null

