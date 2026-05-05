# definir variables
CXX = g++
CXXFLAGS = -O3 -march=native -Wall
TARGET = experimento
SRC = experimento.cpp

# regla que se ejecuta al escribir make 
all: $(TARGET)

# regla del ejecutable 
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# limpiar archivos generados
clean:
	rm -f $(TARGET) resultados_tiempos.csv