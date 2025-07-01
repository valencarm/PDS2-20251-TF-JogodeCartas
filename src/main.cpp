#include "Jogo.hpp"
#include "Partida.hpp"
#include "Time.hpp"
#include "Rodada.hpp"
#include "Baralho.hpp"
#include "Jogador.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    std::cout << "======================================\n";
    std::cout << "      Bem-vindo ao Jogo de Truco      \n";
    std::cout << "======================================\n";

    int opcao = 0;
    Jogo jogo;

    do {
        jogo.ImprimirMenu();
        std::cout << "Digite sua opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                jogo.ImprimirRegras();
                break;

            case 2:
                jogo.ImprimirResultados();
                break;

            case 3: {
                std::cout << "\nIniciando nova partida...\n";

            
                int modo = 0, regras = 1, aposta = 2;

                std::cout << "Escolha o modo de jogo [0: Normal, 1: Rápido, 2: Duas Quedas]: ";
                std::cin >> modo;

                std::cout << "Escolha o conjunto de regras (número): ";
                std::cin >> regras;

                std::cout << "Digite o valor da aposta inicial: ";
                std::cin >> aposta;

               Partida partida(0, 0, 0, 12);
                partida.ConfigurarPartida(modo, aposta);

            
                std::vector<Jogador*> jogadores;
                std::string nome;
                for (int i = 0; i < 4; ++i) {
                    std::cout << "Digite o nome do jogador " << i + 1 << ": ";
                    std::cin >> nome;
                    jogadores.push_back(new Jogador(nome, i % 2)); // Alterna entre time 0 e 1
                }

                Time* time1 = new Time(*jogadores[0], *jogadores[2]);
                Time* time2 = new Time(*jogadores[1], *jogadores[3]);

           
                Baralho baralho;
                baralho.embaralharCartas();
                std::vector<Jogador> jogadoresObj = {
                    *jogadores[0],
                    *jogadores[1],
                    *jogadores[2],
                    *jogadores[3]
                 };

                  baralho.distribuirCartas(jogadoresObj);

            
                Rodada rodada(time1, time2, jogadores, nullptr);
                rodada.executarRodada();

               
                partida.exibirEstado();

            
                for (Jogador* j : jogadores) delete j;
                delete time1;
                delete time2;

                break;
            }

            case 4:
                std::cout << "Encerrando o jogo. Obrigado por jogar!\n";
                break;

            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }

    } while (opcao != 4);

    return 0;
}
