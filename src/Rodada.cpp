#include "Rodada.hpp"
#include "Jogador.hpp"
#include "Time.hpp"
#include "Carta.hpp"
#include <iostream>
#include <algorithm>

Rodada::Rodada(Time* t1, Time* t2, const std::vector<Jogador*>& jogadores, Jogador* vencedorAnterior)
    : Time1(t1), vitoriasT1(0), Time2(t2), vitoriasT2(0), jogadoresRodada(jogadores), numeroRodada(1),
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

// Compara as cartas e define o vencedor da mão
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

    // Incrementa o contador de vitórias do time vencedor
    if (vencedor->getTime() == Time1) {
        vitoriasT1++;
    } else if (vencedor->getTime() == Time2) {
        vitoriasT2++;
    }
    else {
        std::cerr << "Erro: Jogador não pertence a nenhum time.\n";
        return nullptr;
    }

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

void respnderTruco(){

}


void Rodada::pedirTruco(Jogador* jogador) {
    if (trucoPedido) {
        std::cout << "Truco já foi pedido anteriormente!\n";
        return;
    }

    if (pontoRodada != 2) {
        std::cout << "Truco não pode ser pedido agora. Rodada já vale mais que 2 pontos.\n";
        return;
    }

    if (jogador != jogadorAtual) {
        std::cout << "Apenas o jogador da vez pode pedir truco.\n";
        return;
    }

    trucoPedido = true;
    pontoRodada = NivelAposta::Truco;

    std::cout << jogador->getNome() << " pediu TRUCO!\n";
}


void Rodada::pedirSeis() {
    //Verificar se o mesmo time pediu seis, e pediu truco
    if (pontoRodada == NivelAposta::Truco) {
        pontoRodada = NivelAposta::Seis;
        std::cout << "Seis pedido!\n";
    }
    else{
        std::cout << "Não pode pedir seis!\n";
    }
}

void Rodada::pedirNove() {
    if (pontoRodada == NivelAposta::Seis) {
        pontoRodada = NivelAposta::Nove;
        std::cout << "Nove pedido!\n";
    }
    else{
        std::cout << "Não pode pedir nove!\n";
    }
}

void Rodada::pedirDoze() {
    if (pontoRodada == NivelAposta::Nove) {
        pontoRodada = NivelAposta::Doze;
        std::cout << "Doze pedido!\n";
    }
    else{
        std::cout << "Não pode pedir nove!\n";
    }
}

//
void Rodada::aceitarTruco() {
    trucoPedido = true;
    pontoRodada = NivelAposta::Truco;
    std::cout << "Truco aceito! Rodada valendo " << static_cast<int>(pontoRodada) << " pontos.\n";
}

void Rodada::correrTruco() {
    std::cout << "Truco recusado! Adversário ganha " << static_cast<int>(pontoRodada) << " ponto(s).\n";

    if (jogadorAtual->getTime() == Time1){
        Time2->GanharQueda(static_cast<int>(pontoRodada));
    }
    else{
        Time1->GanharQueda(static_cast<int>(pontoRodada));
    }
    finalizarRodada();
}



// Termina a rodada, define o vencedor e atualiza os pontos
void Rodada::finalizarRodada() {
    Time* vencedor = DefinirVencedorRodada();
    if (vencedor) {
        vencedor->GanharQueda(static_cast<int>(pontoRodada));
        std::cout << "Rodada finalizada. Pontos: " << static_cast<int>(pontoRodada) << "\n";
    } else {
        std::cout << "Rodada empatada.\n";
    }

    cartasRodada.clear();
    pontoRodada = NivelAposta::Normal;
    trucoPedido = false;
    numeroRodada++;
}

void Rodada::getvalorRodada() {
    std::cout << "Rodada vale " << static_cast<int>(pontoRodada) << " ponto(s).\n";

}

void Rodada::getrodadaAtual() {
    std::cout << "Estamos na rodada " << numeroRodada << "\n";
}

void Rodada::getjogadorAtual(){
    std::cout <<  "O jogador atual é " << jogadorAtual << "\n";
}

// Realiza uma rodada do jogo
void Rodada::executarRodada() {
    std::cout << "Executando rodada " << numeroRodada << "\n";
    if (jogadoresRodada.empty()) {
        std::cout << "Erro: Nenhum jogador disponivel para jogar.\n";
        return;
    }
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
