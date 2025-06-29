#ifndef PARTIDA_H
#define PARTIDA_H

#include <vector>
#include <iostream>
#include "Time.hpp"

class Partida {
private:
    std::vector<int> pontuacao; 
    int pontuacaoMaxima;
    int conjuntoRegras;
    int modoJogo;
    int aposta;
    Time t1, t2;

public:
    // Construtor e destrutor
    Partida(Time t1, Time t2);
    Partida(int conjuntoRegras, int modoJogo, int aposta, int pontuacaoMaxima);
    ~Partida();

    // Configurações da partida
    void setModojogo(int modoJogo);
    void setPontuacaoMaxima(int modoJogo);
    void ConfigurarModo(int modoJogo);
      //funcoes auxiliares
      bool isMaoDeDez() const;
      bool isMaoDeFerro() const;

    /*void setConjuntoregras(int conjuntoRegras);
    void ConfigurarRegras(int conjuntoRegras);*/

    void setAposta(int aposta);
    void ConfigurarAposta(int aposta);

    void ConfigurarPartida(int modoJogo, /*int conjuntoRegras,*/ int aposta);

    // Pontuação
    void atualizarPontuacao(int time, int pontos);
    int getPontuacao(int time) const;

    // Fim de jogo
    bool verificarFimDeJogo() const;
    int getTimeVencedor() const;

    // Visualização
    void exibirEstado() const;

    void Jogar();
};

#endif