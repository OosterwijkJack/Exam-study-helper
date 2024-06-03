# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Iprogram_files -g

# Source files
SRCS = main.c program_files/data.c program_files/tools.c

# Executable name
EXEC = main

# Default rule
all:
	$(EXEC)

# Rule to compile source files directly into the executable
$(EXEC):
	$(CC) $(CFLAGS) $(SRCS) -o $@

# Clean rule to remove the generated executable
clean:
	rm -f $(EXEC)

# Phony targets to avoid conflict with files of the same name
.PHONY: all clean