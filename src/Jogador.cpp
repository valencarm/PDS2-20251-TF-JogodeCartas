#include "Jogador.hpp"
#include "Time.hpp"
#include <iostream>
#include <vector>

static int cont = 0;

Jogador::Jogador(std::string nome){
    this->nome = nome;
    this->id = cont;
    cont++;
}
Carta Jogador::Jogar(int id){
    Carta carta = this->cartas.at(id);
    cartas.erase(cartas.begin() + id);
    return carta;
}

std::string Jogador::GetNome(){
    return this->nome;
}

int Jogador::GetId(){
    return this->id;
}

void Jogador::ImprimirCartas(){
    int cont = 0;
    for(Carta c : cartas){
        std::cout << "[" << cont << "] ";
        std::cout << c.getCarta() << std::endl;
        cont++;
    }
}

void Trucar(Time& outroTime){

}

void Jogador::receberCarta(Carta carta){
    this->cartas.push_back(carta);
}