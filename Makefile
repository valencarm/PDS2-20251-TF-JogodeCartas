# === VARIÁVEIS DE CONFIGURAÇÃO ===
CXX = g++                        # Compilador
CXXFLAGS = -Wall -Iinclude -std=c++17  # Flags de compilação

SRC_DIR = src                   # Diretório dos arquivos .cpp
INC_DIR = include               # Diretório dos headers
BUILD_DIR = obj                 # Onde ficarão os .o
BIN_DIR = bin                   # Onde ficará o executável
TARGET = $(BIN_DIR)/meu_programa

# Lista de arquivos-fonte
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Converte os .cpp para .o (ex: src/main.cpp → build/main.o)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# === REGRA PADRÃO (primeira regra é a padrão) ===
all: $(TARGET)

# === COMO GERAR O EXECUTÁVEL FINAL ===
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Ex: build/main.o depende de src/main.cpp e include/algum.hpp
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# === LIMPAR ARQUIVOS GERADOS ===
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)