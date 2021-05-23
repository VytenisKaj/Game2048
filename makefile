
CC = g++
FLAGS = -std=c++11 -Wall
DEL = del
KEEP = echo This is a .keep file for git > git.keep
SRC_DIR = src
DOC_DIR = doc
SRC_H = $(wildcard $(SRC_DIR)/*.h)
SRC_CPP = $(wildcard $(SRC_DIR)/*.cpp)
SRC_OBJ = $(SRC_CPP:%.cpp=%.o)
TARGET = game2048.exe

all : $(TARGET) put_keep

$(TARGET) : $(SRC_OBJ)
	$(CC) $(FLAGS) $(SRC_OBJ) -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_H)
	$(CC) $(FLAGS) -c $< -o  $@
	
clean : 
	$(DEL) /Q $(SRC_DIR)\*.o
	$(DEL) $(TARGET)
	
rebuild : clean all

deploy :
	git add .
	git commit -m "Commit by makefile"
	git push -u origin main

put_keep : 
	cd $(SRC_DIR) && $(KEEP)
	cd $(DOC_DIR) && $(KEEP)

.PHONY: all clean rebuild
