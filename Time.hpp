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
        Time();
        void formarTime();
        void getTime();
        int getPontos();
        void ganharQueda();
        void aceitarTruco();

};

#endif