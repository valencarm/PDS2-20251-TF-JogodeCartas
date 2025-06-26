#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <string>
#include <vector>
#include "Jogador.hpp"

class Time{
    private: 
        std::vector<Jogador> time;
        int pontos;
    public: 
        Time(Jogador& jogador1, Jogador& jogador2);
        void ImprimirTime();
        int GetPontos();
        void GanharQueda(int valorQueda);

};

#endif