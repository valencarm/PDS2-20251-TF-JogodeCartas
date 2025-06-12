// Controlar o estado da partida
// Controlar a pontuacao dos times
// Definir o modo de jogo e o conjunto de regras
// Gerenciar apostas

//Colaboracoes: Time, Rodada, Jogador

#ifdef PARTIDA
#define PARTIDA

#include <iostream>

class Partida{
    private:
    std::vector <int> pontuacao;
    int conjunto_regras;
    int modo_jogo;
    int aposta;
    
    public:
    Partida(int regras, int modo_jogo, int aposta) {}
    ~Partida() {}

    setModojogo();
    ConfigurarModo(int modo_jogo);
    
    setConjuntoregras();
    ConfigurarRegras(int regras);

    setAposta();
    ConfigurarAposta(int aposta);

    ConfigurarPartida(int modo_jogo, int regras, int aposta);

}