# === VARIÁVEIS DE CONFIGURAÇÃO ===
CXX := g++
CXXFLAGS := -Wall -Wextra -Iinclude -std=c++14 -g
LDFLAGS := 

SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj
BIN_DIR := bin
LIB_DIR := lib

# Nomes dos alvos
TARGET_EXEC := $(BIN_DIR)/meu_programa  # Executável
TARGET_LIB := $(LIB_DIR)/libmeulib.a    # Biblioteca estática (.a)

# Lista de arquivos-fonte e objetos
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Garante que os diretórios existam
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR))

# === REGRAS PRINCIPAIS ===
.PHONY: all exec lib clean

# Compila tudo (executável + biblioteca)
all: exec lib

# Apenas o executável
exec: $(TARGET_EXEC)

# Apenas a biblioteca
lib: $(TARGET_LIB)

# === REGRA PARA O EXECUTÁVEL ===
$(TARGET_EXEC): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

# === REGRA PARA A BIBLIOTECA ESTÁTICA (.a) ===
$(TARGET_LIB): $(OBJS)
	ar rcs $@ $^

# === REGRA PARA COMPILAR OBJETOS (.o) ===
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# === GERADOR DE DEPENDÊNCIAS ===
DEPFILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.d,$(SRCS))
$(OBJ_DIR)/%.d: $(SRC_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -MM -MT '$(@:.d=.o)' $< > $@

-include $(DEPFILES)

# === LIMPEZA ===
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)
