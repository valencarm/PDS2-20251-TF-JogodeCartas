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
            Jogador(std::string nome, int id);
            void Jogar();
            std::string GetNome();
            int GetId();
            void ImprimirCartas();
            void Trucar(Jogador& outro);
    };

#endif
