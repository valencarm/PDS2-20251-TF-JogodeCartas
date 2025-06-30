#include "Jogador.hpp"
#include "Time.hpp"
#include "Rodada.hpp"
#include <iostream>
#include <vector>

static int cont = 0;

Jogador::Jogador(std::string nome, int time){
    this->nome = nome;
    this->id = cont;
    this->time = time;
    cont++;
}
Carta Jogador::Jogar(){
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "                   FAÇA UMA AÇÃO" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl << std::endl;
    std::cout << "Escolha uma opção:" << std::endl;
    std::cout << "[T] Trucar" << std::endl;
    std::cout << "Para jogar uma carta na mesa, digite o seu número: " << std::endl;
    this->ImprimirCartas();
    std::cout << "---------------------------------------------------" << std::endl;

    char op;
    std::cin >> op;

    if(op == 'T'){
        
    }
 
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

int Jogador::getTime(){
    return this->time;
}

void Trucar(Time& outroTime){

}

void Jogador::receberCarta(Carta carta){
    this->cartas.push_back(carta);
}