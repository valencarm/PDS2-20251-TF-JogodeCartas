# === VARIÁVEIS DE CONFIGURAÇÃO ===
CXX := g++
CXXFLAGS := -Wall -Wextra -Iinclude -std=c++17 -g
LDFLAGS := 

SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj
BIN_DIR := bin
TARGET := $(BIN_DIR)/meu_programa

# Lista de arquivos-fonte
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Garante que os diretórios existam
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# === REGRAS ===
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

# Regra genérica para arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Gera dependências automaticamente
DEPFILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.d,$(SRCS))
$(OBJ_DIR)/%.d: $(SRC_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -MM -MT '$(@:.d=.o)' $< > $@

# Inclui os arquivos de dependência
-include $(DEPFILES)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)