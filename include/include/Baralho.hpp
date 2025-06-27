#ifndef BARALHO_HPP
#define BARALHO_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Carta.hpp"
#include "Jogador.hpp"

class Baralho {
private:
    std::vector<Carta> cartas;

public:
    Baralho();

    void embaralharCartas();
    void distribuirCartas(std::vector<Jogador>& jogadores);
    void organizarCartas(bool ordemCrescente = false);
    Carta getCarta();
    const std::vector<Carta>& getCartas() const;
    void resetar();

    ~Baralho() {}
};

#endif
