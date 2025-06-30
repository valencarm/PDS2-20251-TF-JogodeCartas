#ifndef JOGADOR_H
#define JOGADOR_H
#include <iostream>
#include <string>
#include <list>
#include "Carta.hpp"

    class Jogador{
        private:
            std::string nome;
            int id;
            std::vector<Carta> cartas;
            int time;

        public:
            Jogador();
            Jogador(std::string nome, int time);
            Carta Jogar();
            std::string GetNome();
            int GetId();
            int getTime();
            void ImprimirCartas();
            void Trucar(Jogador& outro);
            void receberCarta(Carta carta);
    };

#endif
