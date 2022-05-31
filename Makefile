CC = g++
TARGET = Keyboard

SRC_DIR = ./source
OBJ_DIR = ./obj
INC = ./include
CFLAGS =  -I $(INC) -g 
# # LDFLAGS = 
# DEBUG = _DEBUG

SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))
OBJS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@  $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY : clean all
clean :
	rm -f $(OBJS) $(TARGET)

-include $(DEPS)

# g++ main.cpp LinkdeQueue.cpp LinkedStack.cpp LinkedList.cpp Node.cpp -o Keyboard