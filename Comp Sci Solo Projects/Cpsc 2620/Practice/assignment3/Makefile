CC = g++
CFLAGS  =-std=c++11 -g -Wall

TARGET = testStrMatrix
CLASS1 = Structured_Matrix
CLASS2 = Symmetric_Matrix
CLASS3 = Triangular_Matrix
CLASS4 = Upper_Triangular_Matrix
CLASS5 = Lower_Triangular_Matrix
CLASS6 = Diagonal_Matrix
CLASS7 = Symmetric_Tridiagonal_Matrix
MAIN = testStrMatrix

all: $(TARGET)

$(TARGET): $(CLASS1).o $(CLASS2).o $(CLASS3).o $(CLASS4).o $(CLASS5).o $(CLASS6).o $(CLASS7).o $(MAIN).o
	$(CC) $(CFLAGS) -o $(TARGET) $(CLASS1).o $(CLASS2).o $(CLASS3).o $(CLASS4).o $(CLASS5).o $(CLASS6).o $(CLASS7).o $(MAIN).o

$(CLASS1).o: $(CLASS1).cpp $(CLASS1).h
	$(CC) $(CFLAGS) -c $(CLASS1).cpp

$(CLASS2).o: $(CLASS2).cpp $(CLASS2).h
	$(CC) $(CFLAGS) -c $(CLASS2).cpp

$(CLASS3).o: $(CLASS3).cpp $(CLASS3).h
	$(CC) $(CFLAGS) -c $(CLASS3).cpp

$(CLASS4).o: $(CLASS4).cpp $(CLASS4).h
	$(CC) $(CFLAGS) -c $(CLASS4).cpp

$(CLASS5).o: $(CLASS5).cpp $(CLASS5).h
	$(CC) $(CFLAGS) -c $(CLASS5).cpp

$(CLASS6).o: $(CLASS6).cpp $(CLASS6).h
	$(CC) $(CFLAGS) -c $(CLASS6).cpp

$(CLASS7).o: $(CLASS7).cpp $(CLASS7).h
	$(CC) $(CFLAGS) -c $(CLASS7).cpp

$(MAIN).o: $(MAIN).cpp $(CLASS1).h $(CLASS2).h $(CLASS3).h $(CLASS4).h $(CLASS5).h $(CLASS6).h $(CLASS7).h
	$(CC) $(CFLAGS) -c $(MAIN).cpp

clean:
	$(RM) -f $(TARGET) $(CLASS1).o $(CLASS2).o $(CLASS3).o $(CLASS4).o $(CLASS5).o $(CLASS6).o $(CLASS7).o $(MAIN).o
