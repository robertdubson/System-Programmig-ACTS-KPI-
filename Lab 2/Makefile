

CC = g++
TARGET_BINARY = binary
TARGET_LIB = lib1.a
FLAGS_FOR_LIB = -L.
SOURCES = InsurancePolicy.cpp DataBase.cpp 
OBJECTS_FOR_LIB = $(SOURCES:.cpp=.o)
MAIN_SOURCE = UserInterface.cpp
OBJECT_MAIN = $(MAIN_SOURCE:.cpp=.o)


$(TARGET_BINARY): $(OBJECT_MAIN) $(TARGET_LIB)
	$(CC) -o $(TARGET_BINARY) $(OBJECT_MAIN) $(FLAGS_FOR_LIB) $(TARGET_LIB)


$(OBJECT_MAIN): $(MAIN_SOURCE)
	$(CC) -c $(MAIN_SOURCE)


$(TARGET_LIB): $(OBJECTS_FOR_LIB)
	ar cr $(TARGET_LIB) $(OBJECTS_FOR_LIB)

$(OBJECTS_FOR_LIB): $(SOURCES) 
	$(CC) -c $(SOURCES)


clean: 
	rm -f *.o *.a binary

