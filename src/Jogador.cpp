#include "Jogador.hpp"
#include "Time.hpp"
#include <iostream>

Jogador::Jogador(std::string nome, int id){
    this->id = id;
    this->nome = nome;
}
void Jogar(){

}

std::string Jogador::GetNome(){
    return this->nome;
}

int Jogador::GetId(){
    return this->id;
}

void Jogador::ImprimirCartas(){
    int cont = 1;
    for(Carta c : cartas){
        std::cout << "[" << cont << "] ";
        std::cout << c.getCarta() << std::endl;
        cont++;
    }
}

void Trucar(Time& outroTime){

}