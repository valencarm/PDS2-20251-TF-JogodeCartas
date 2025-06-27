#ifndef CARTA_HPP
#define CARTA_HPP
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>


class Carta {
private:
    std::string naipe;
    std::string valor;

public:
    Carta(const std::string& naipe, const std::string& valor);

    std::string getCarta() const;
    std::string getValor() const;
    static bool comparaCarta(const Carta& c1, const Carta& c2);
    static bool validaJogada(const std::vector<Carta>& maoJogador, const Carta& cartaJogada);
    

    ~Carta() {}
};

#endif
