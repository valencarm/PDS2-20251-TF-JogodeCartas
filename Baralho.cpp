#include "Baralho.hpp"
#include <algorithm>
#include <random>
#include <chrono>
#include <stdexcept>

Baralho::Baralho() {
    std::vector<std::string> naipes = {"Paus", "Ouros", "Copas", "Espadas"};
    std::vector<std::string> valores = {"4", "5", "6", "7", "Q", "J", "K", "A", "2", "3"};

    for (const auto& naipe : naipes) {
        for (const auto& valor : valores) {
            cartas.emplace_back(naipe, valor);
        }
    }
}

void Baralho::embaralharCartas() {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cartas.begin(), cartas.end(), std::default_random_engine(seed));
}

void Baralho::distribuirCartas(std::vector<Jogador>& jogadores) {
    int cartasPorJogador = 3;

    for (int i = 0; i < cartasPorJogador; ++i) {
        for (auto& jogador : jogadores) {
            if (!cartas.empty()) {
                jogador.receberCarta(cartas.back());
                cartas.pop_back();
            }
        }
    }
}

void Baralho::organizarCartas(bool ordemCrescente) {
    std::vector<std::string> ordemForca = {
        "3", "2", "A", "K", "J", "Q", "7", "6", "5", "4"
    };

    auto getPos = [&](const Carta& c) {
        auto it = std::find(ordemForca.begin(), ordemForca.end(), c.getValor());
        return std::distance(ordemForca.begin(), it);
    };

    std::sort(cartas.begin(), cartas.end(), [&](const Carta& a, const Carta& b) {
        int posA = getPos(a);
        int posB = getPos(b);
        return ordemCrescente ? (posA > posB) : (posA < posB);
    });
}

Carta Baralho::getCarta() {
    if (cartas.empty()) {
        throw std::runtime_error("Não há mais cartas no baralho!");
    }

    Carta topo = cartas.back();
    cartas.pop_back();
    return topo;
}

void Baralho::resetar() {
    cartas.clear();

    std::vector<std::string> naipes = {"Paus", "Ouros", "Copas", "Espadas"};
    std::vector<std::string> valores = {"4", "5", "6", "7", "Q", "J", "K", "A", "2", "3"};

    for (const auto& naipe : naipes) {
        for (const auto& valor : valores) {
            cartas.emplace_back(naipe, valor);
        }
    }

    embaralharCartas();
}

const std::vector<Carta>& Baralho::getCartas() const {
    return cartas;
}
