# ============================================================
#  Makefile — Employee Management System
#
#  Usage:
#    make          builds the program  →  ./employment
#    make clean    removes compiled files
# ============================================================

CC      = gcc
CFLAGS  = -Wall -Wextra
TARGET  = employment
SRCS    = main.c employee_operations.c file_handler.c utils.c
OBJS    = $(SRCS:.c=.o)

# Default target: build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	@echo "Build successful! Run with: ./$(TARGET)"

# Compile each .c into a .o
%.o: %.c employee.h
	$(CC) $(CFLAGS) -c $< -o $@

# Remove all compiled output
clean:
	rm -f $(OBJS) $(TARGET)
	@echo "Cleaned."
