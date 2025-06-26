
#include "Rodada.hpp"
#include <iostream>
#include <algorithm>

 Rodada::Rodada(Time* t1, Time* t2, const std::vector<Jogador*>& jogadores, Jogador* vencedorAnterior)
    : Time1(t1), Time2(t2), jogadoresRodada(jogadores), numeroRodada(1),
      pontoRodada(2), trucoPedido(false), jogadorAtual(nullptr) {}


void Rodada::ordenarJogadores(Jogador* ultimoVencedor) {
    auto it = std::find(jogadoresRodada.begin(), jogadoresRodada.end(), vencedorRodadaAnterior);
    if (it != jogadoresRodada.end()) {
        std::rotate(jogadoresRodada.begin(), it, jogadoresRodada.end());
        jogadorAtual = jogadoresRodada[0]; 
        std::cout << "Nova ordem dos jogadores (iniciando por: " << vencedorRodadaAnterior->getNome() << ")\n";
    } else {
        std::cerr << "Erro: Vencedor da rodada anterior não encontrado na lista de jogadores.\n";
        jogadorAtual = jogadoresRodada[0];
    }
}


bool Rodada::ValidarJogada(Carta& carta, Jogador* jogador) {
    return jogador == jogadorAtual;
}


void Rodada::AdicionarCartaRodada(Carta& carta, Jogador* jogador) {
    if (!ValidarJogada(carta, jogador)) {
        std::cout << "Jogada inválida de " << jogador->getNome() << "\n";
        return;
    }

    cartasRodada.push_back(&carta);
    std::cout << jogador->getNome() << " jogou: " << carta.toString() << "\n";

    
    proximoJogador();
}


Jogador* Rodada::DefinirVencedorMao() {
    if (cartasRodada.empty()) return nullptr;

    Carta* melhor = cartasRodada[0];
    Jogador* vencedor = jogadoresRodada[0];

    for (size_t i = 1; i < cartasRodada.size(); ++i) {
        if (cartasRodada[i]->getValorTruco() > melhor->getValorTruco()) {
            melhor = cartasRodada[i];
            vencedor = jogadoresRodada[i];
        }
    }

    std::cout << "Vencedor da mão: " << vencedor->getNome() << "\n";
    // Adicionar o contador de vitorias ao time
    return vencedor;
}


Time* Rodada::DefinirVencedorRodada() {
    int vitoriasT1, vitoriasT2;

    if (vitoriasT1 > vitoriasT2) return Time1;
    else if (vitoriasT2 > vitoriasT1) return Time2;
    else return nullptr;
}

void Rodada::proximoJogador(){

}


void Rodada::pedirTruco() {
    if (!trucoPedido) {
        pontoRodada = 4;
        trucoPedido = true;
        std::cout << "Truco pedido!\n";
    }
    else if(pontuacao.find() == 10){
        std::cout << "Não pode pedir truco!\n";
    }
}

void Rodada::pedirSeis() {
    if (pontoRodada == 4) {
        pontoRodada = 6;
        std::cout << "Seis pedido!\n";
    }
    else{
        std::cout << "Não pode pedir seis!\n";
    }
}

void Rodada::pedirNove() {
    if (pontoRodada == 6) {
        pontoRodada = 9;
        std::cout << "Nove pedido!\n";
    }
    else{
        std::cout << "Não pode pedir nove!\n";
    }
}

void Rodada::pedirDoze() {
    if (pontoRodada == 9) {
        pontoRodada = 12;
        std::cout << "Doze pedido!\n";
    }
    else{
        std::cout << "Não pode pedir nove!\n";
    }
}

void Rodada::aceitarTruco() {
    std::cout << "Truco aceito! Rodada valendo " << pontoRodada << " pontos.\n";
}

void Rodada::correrTruco() {
    std::cout << "Truco recusado! Adversário ganha " << pontoRodada << " ponto(s).\n";

    if (jogadorAtual->getTime() == Time1)
        Time2->adicionarPontos(pontoRodada);
    else
        Time1->adicionarPontos(pontoRodada);

    finalizarRodada();
}


void Rodada::finalizarRodada() {
    Time* vencedor = DefinirVencedorRodada();
    if (vencedor) {
        vencedor->adicionarPontos(pontoRodada);
        std::cout << "Rodada finalizada. Pontos: " << pontoRodada << "\n";
    } else {
        std::cout << "Rodada empatada.\n";
    }

    cartasRodada.clear();
    pontoRodada = 2;
    trucoPedido = false;
    numeroRodada++;
}

void Rodada::getvalorRodada() {
    std::cout << "Rodada vale " << pontoRodada << " ponto(s).\n";
}

void Rodada::getrodadaAtual() {
    std::cout << "Estamos na rodada " << numeroRodada << "\n";
}

void Rodada::getjogadorAtual(){
    std::cout <<  "O jogador atual é " << jogadorAtual << "\n";
}


void Rodada::executarRodada() {
    std::cout << "Executando rodada " << numeroRodada << "\n";
    ordenarJogadores();

    for (int i = 0; i < 3; ++i) {
        for (Jogador* j : jogadoresRodada) {
            Carta carta = j->jogar();
            AdicionarCartaRodada(carta, j);
        }
        DefinirVencedorMao();
        cartasRodada.clear(); 
    }

    finalizarRodada();
}
