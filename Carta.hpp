//Criar um baralho de Truco
//Embaralhar, organizar e distribuir as cartas
//Lidar com ações especiais
//Definir quem embaralha e repor cartas

//RESPONSABILIDADES : ARMAZENAR VsALOR E NAIPE, COMPARAR C/ OUTRAS CARTAS, VALIDAR JOGADA, RETORNAR IMAGEM DA CARTA

#ifndef CARTA
#define CARTA
#include <iostream>
#include <string>
class Carta {
    private: 
    std::string naipe;
    std::string valor;
   
    public: 
    Carta(const std::string& naipe, const std::string& valor);
    
    std::string getCarta() const; // aí no cpp vai dar "return valor + " de " naipe;"
    std::string getValor() const; //será usado p/ comparar as não-manilhas
    void comparaCarta(const Carta& card, Carta& outra);
    bool validaJogada(const Carta& card, Carta& outra);
    ~Carta(){}
};
#endif
