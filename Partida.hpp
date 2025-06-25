#ifndef PARTIDA_H
#define PARTIDA_H

#include <vector>
#include <iostream>

class Partida {
private:
    std::vector<int> pontuacao; 
    int pontuacaoMaxima;
    int conjuntoRegras;
    int modoJogo;
    int aposta;

public:
    // Construtor e destrutor
    Partida(int conjuntoRegras, int modoJogo, int aposta, int pontuacaoMaxima);
    ~Partida();

    // Configurações da partida
    void setModojogo(int modoJogo);
    void setPontuacaoMaxima(int modoJogo);
    void ConfigurarModo(int modoJogo);

    void setConjuntoregras(int conjuntoRegras);
    void ConfigurarRegras(int conjuntoRegras);

    void setAposta(int aposta);
    void ConfigurarAposta(int aposta);

    void ConfigurarPartida(int modoJogo, int conjuntoRegras, int aposta);

    // Pontuação
    void atualizarPontuacao(int time, int pontos);
    int getPontuacao(int time) const;

    // Fim de jogo
    bool verificarFimDeJogo() const;
    int getTimeVencedor() const;

    // Visualização
    void exibirEstado() const;
};

#endif

#endif