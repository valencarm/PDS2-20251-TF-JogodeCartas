#include "Carta.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>

const std::vector<std::string> MANILHAS = {
    "4 de Paus",
    "7 de Copas",
    "A de Espadas",
    "7 de Ouros"
};

const std::vector<std::string> ORDEM_VALORES = {
    "3", "2", "A", "K", "J", "Q", "7", "6", "5", "4"
};

Carta::Carta(const std::string& naipe, const std::string& valor) {
    static std::vector<std::string> naipesValidos = {"Paus", "Ouros", "Copas", "Espadas"};
    static std::vector<std::string> valoresValidos = {"4", "5", "6", "7", "Q", "J", "K", "A", "2", "3"};

    if (std::find(naipesValidos.begin(), naipesValidos.end(), naipe) == naipesValidos.end()) {
        throw std::invalid_argument("Naipe inválido: " + naipe);
    }
    if (std::find(valoresValidos.begin(), valoresValidos.end(), valor) == valoresValidos.end()) {
        throw std::invalid_argument("Valor inválido: " + valor);
    }

    this->naipe = naipe;
    this->valor = valor;
}

std::string Carta::getCarta() const {
    return valor + " de " + naipe;
}

std::string Carta::getValor() const {
    return valor;
}
int Carta::getForca() const {
    if (valor == "4" && naipe == "Paus") return 100;
    if (valor == "7" && naipe == "Copas") return 99;
    if (valor == "A" && naipe == "Espadas") return 98;
    if (valor == "7" && naipe == "Ouros") return 97;

    // valores normais
    if (valor == "3") return 10;
    if (valor == "2") return 9;
    if (valor == "A") return 8;
    if (valor == "K") return 7;
    if (valor == "J") return 6;
    if (valor == "Q") return 5;
    if (valor == "7") return 4;
    if (valor == "6") return 3;
    if (valor == "5") return 2;
    if (valor == "4") return 1;

    return 0; // caso erro
}


bool Carta::comparaCarta(const Carta& c1, const Carta& c2) {
    std::string nome1 = c1.getCarta();
    std::string nome2 = c2.getCarta();

    auto it1 = std::find(MANILHAS.begin(), MANILHAS.end(), nome1);
    auto it2 = std::find(MANILHAS.begin(), MANILHAS.end(), nome2);

    if (it1 != MANILHAS.end() && it2 != MANILHAS.end()) {
        return std::distance(MANILHAS.begin(), it1) < std::distance(MANILHAS.begin(), it2);
    }
    if (it1 != MANILHAS.end()) return true;
    if (it2 != MANILHAS.end()) return false;

    auto pos1 = std::find(ORDEM_VALORES.begin(), ORDEM_VALORES.end(), c1.getValor());
    auto pos2 = std::find(ORDEM_VALORES.begin(), ORDEM_VALORES.end(), c2.getValor());

    return std::distance(ORDEM_VALORES.begin(), pos1) < std::distance(ORDEM_VALORES.begin(), pos2);
}

bool Carta::validaJogada(const std::vector<Carta>& maoJogador, const Carta& cartaJogada) {
    for (const auto& carta : maoJogador) {
        if (carta.getCarta() == cartaJogada.getCarta()) {
            return true;
        }
    }
    return false;
}

Carta Carta::operator=(Carta const& other){
    this->naipe = other.naipe;
    this->valor = other.valor;
    
    return *this;
}
