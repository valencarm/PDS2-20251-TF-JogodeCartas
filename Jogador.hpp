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
            std::list<Carta> cartas;

        public:
            Jogador();
            Jogador(int nome, int id);
            void jogar();
            std::string getNome();
            void imprimirCartas();
            void trucar();
    };

#endif