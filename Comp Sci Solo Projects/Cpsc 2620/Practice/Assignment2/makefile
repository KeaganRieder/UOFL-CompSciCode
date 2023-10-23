CC = g++
CFLAGS  =-std=c++11 -g -Wall

TARGET = test_matrix
CLASS1 = Matrix
MAIN = test_matrix

all: $(TARGET)

$(TARGET): $(CLASS1).o $(MAIN).o
	$(CC) $(CFLAGS) -o $(TARGET) $(CLASS1).o $(MAIN).o

$(CLASS1).o: $(CLASS1).cpp $(CLASS1).h
	$(CC) $(CFLAGS) -c $(CLASS1).cpp

$(MAIN).o: $(MAIN).cpp $(CLASS1).h
	$(CC) $(CFLAGS) -c $(MAIN).cpp

clean:
	$(RM) -f $(TARGET) $(CLASS1).o $(MAIN).o
