#include "Carta.hpp"
#include "Jogador.hpp"
#include "Partida.cpp"
#include "Time.hpp"
#include "Jogo.hpp"
#include <string>
#include <fstream>
#include <iostream>

void Jogo::Menu(){

    int opcao;

    do{
        std::cin >> opcao;
        switch (opcao)
        {
        case '1':
            ImprimirRegras();
            break;
        case '2':
            ImprimirResultados();
            break;
        case '3':
            //iniciar jogo
            break;
        default:
            break;
        }
    }while(opcao != 3);

}

void Jogo::ImprimirRegras(){
    std::string nomeArquivo = "C:\\teste\\tp\\PDS2-20251-TF-JogodeCartas\\regras.txt", saida;
    std::fstream Regras(nomeArquivo);

    if (!Regras) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return;
    }
    
    std::string linha;
    while(getline(Regras, linha)){
        std::cout << linha << std::endl;
    }    
}

void Jogo::ImprimirMenu(){
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "                       MENU" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl << std::endl;
    std::cout << "Escolha uma opção:" << std::endl;
    std::cout << "[1] Veja as Regras!" << std::endl;
    std::cout << "[2] Veja os resultados das partidas anteriores!" << std::endl;
    std::cout << "[3] Comece a jogar!" << std::endl;
    std::cout << "[4] Sair" << std::endl << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
}