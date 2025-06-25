// Organizar ordem das Acoes
// Validar jogadas e determinar vencedor
// Gerenciar pontos e fim da rodada

// Colaboracoes: Time, Partida, Jogador

#ifdef RODADA_H
#define RODADA_H
#include "Time.hpp"
#include "Partida.hpp"
#include "Jogador.hpp"
#include "Carta.hpp"
#include <vector>


class Rodada {
    private:

   int numeroRodada;
   std::vector<Jogador*> jogadoresRodada;
   std::vector<Carta*> cartasRodada;

   Time* Time1;
   Time* Time2;
   int vitoriasT1, vitoriasT2;

   Jogador* jogadorAtual;
   Jogador* vencedorAnterior;

   int pontoRodada;
   bool trucoPedido;

   public:

   Rodada(Time* t1, Time* t2, const std::vector<Jogador*>& jogadores, Jogador* vencedorAnterior) {}

   void ordenarJogadores(Jogador* ultimoVencedor);

   bool ValidarJogada(Carta& carta, Jogador* jogador);
   void AdicionarCartaRodada(Carta& carta, Jogador* jogador);
   Jogador* DefinirVencedorMao();
   Time* DefinirVencedorRodada();
   void proximoJogador();

   void pedirTruco();
   void pedirSeis();
   void pedirNove();
   void pedirDoze();
   void aceitarTruco();
   void correrTruco();

   void finalizarRodada();

   void getvalorRodada();
   void getrodadaAtual();
   void getjogadorAtual();
   void getvencedorAnterior();

   void executarRodada();

};

#endif