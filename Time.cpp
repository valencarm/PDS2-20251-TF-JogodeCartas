#include "Jogador.hpp"
#include "Time.hpp"
#include "Rodada.hpp"
#include <iostream>
#include <string>

//Formar time
Time::Time(Jogador& jogador1, Jogador& jogador2){
    this->time.push_back(jogador1);
    this->time.push_back(jogador2);
    
    this->pontos = 0;
}

//Imprimir os membros do time
void Time::ImprimirTime(){
    for(Jogador j : time){
        std::cout << "Jogador " << j.GetId() + 1 << ": " << j.GetNome();
    }
}

//Retorna a quantidade de pontos do time
int Time::GetPontos(){
    return this->pontos;
}

//Acrescenta ao total de pontos do jogador o valor da queda
void Time::GanharQueda(int valorQueda){
    this->pontos += valorQueda;
}

//Método para os jogadores aceitarem o truco
bool AceitarTruco(){
    char res1, res2;
    std::cout << "Jogador 1 aceita? [S/N]";
    std::cin >> res1;

    if(toupper(res1) == 'N'){
        return false;
    }

    std::cout << "Jogador 2 aceita? [S/N]";
    std::cin >> res2;
    
    if(toupper(res2) == 'S'){
        return true;
    }

    return false;
}