# Makefile

DIR = bin
EXEC1 = $(DIR)/serialMain1
EXEC2 = $(DIR)/parallelMain1
TARGET = $(EXEC1) #${EXEC2}

all: ${TARGET}

CC = g++
# Additional that could be added: -mpclmul
CC_FLAGS = -O3 -madx -msse4.1 -march=native
POST_FLAGS = -lpthread -mcmodel=medium -static-libstdc++

SOURCE1 = general/*.cpp serialSpec/*.cpp testing/serialMain1.cpp
$(DIR)/serialMain1: $(SOURCE1)
	mkdir $(DIR)
	$(CC) $(CC_FLAGS) -o $(DIR)/serialMain1 $(SOURCE1) $(POST_FLAGS)

SOURCE2 = general/*.cpp parallelSpec/*.cpp testing/parallelMain1.cpp
$(DIR)/parallelMain1: $(SOURCE2)
	mkdir $(DIR)
	$(CC) $(CC_FLAGS) -o $(DIR)/parallelMain1 $(SOURCE2) $(POST_FLAGS)


clean:
	-rmdir /s /q $(DIR)