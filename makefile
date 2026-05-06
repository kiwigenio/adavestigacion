# definir variables
CXX = g++
CXXFLAGS = -O3 -march=native -Wall
TARGET = experimento
SRCS = experimento.cpp funciones_strassen.cpp laboratorio_pruebas.cpp
OBJS = $(SRCS:.cpp=.o)
# regla que se ejecuta al escribir make 
all: $(TARGET)

# regla del ejecutable 
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)