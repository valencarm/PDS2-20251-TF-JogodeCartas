#include "Carta.hpp"
#include "Jogador.hpp"
#include "Partida.hpp"
#include "Time.hpp"
#include "Jogo.hpp"
#include <string>
#include <fstream>
#include <iostream>

void Jogo::Menu(){

    int opcao;

    do{
        ImprimirMenu();
        std::cin >> opcao;
        switch (opcao)
        {
        case '0':
            ImprimirRegras();
            break;
        case '1':
            ImprimirResultados();
            break;
        case '2':
            IniciarJogo();
            break;
        default:
            break;
        }
    }while(opcao != 2);

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
    std::cout << "[0] Veja as Regras!" << std::endl;
    std::cout << "[1] Veja os resultados das partidas anteriores!" << std::endl;
    std::cout << "[2] Comece a jogar!" << std::endl;
    std::cout << "[3] Sair" << std::endl << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
}

void Jogo::IniciarJogo(){
    std::string nome1, nome2;
    std::string nomeJ1T1, nomeJ2T1;
    std::string nomeJ1T2, nomeJ2T2;
    
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "               DEFINA OS TIMES" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl << std::endl;
    std::cout << "Digite o nome dos Jogadores do Time1: " << std::endl;
    std::cin >> nomeJ1T1 >> nomeJ1T2;
    Jogador jogador1Time1(nomeJ1T1, 1);
    Jogador jogador2Time1(nomeJ2T1, 1);

    Time time1(jogador1Time1, jogador2Time1);
    
    std::cout << "Digite o nome dos Jogadores do Time1: " << std::endl;
    std::cin >> nomeJ1T2 >> nomeJ1T2;
    Jogador jogador1Time2(nomeJ1T2, 2);
    Jogador jogador2Time2(nomeJ2T2, 2);

    Time time2(jogador2Time1, jogador2Time2);

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "            ESCOLHA UM MODO DE JOGO" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl << std::endl;
    std::cout << "Escolha uma opção:" << std::endl;
    std::cout << "[0] Normal - 12 pontos" << std::endl;
    std::cout << "[1] Rápido - 10 pontos" << std::endl;
    std::cout << "[2] Duas quedas - 24 pontos" << std::endl << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;

    Partida p(time1, time2);
    int modo, aposta;

    std::cin >> modo;
    p.ConfigurarModo(modo);

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "                  FAÇA A SUA APOSTA" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl << std::endl;
    std::cout << " Digite um valor: ";
    std::cin >> aposta;

    p.ConfigurarPartida(modo, aposta);
    p.Jogar();
}
void Jogo::ImprimirResultados() {
    std::cout << "resultados ";
}