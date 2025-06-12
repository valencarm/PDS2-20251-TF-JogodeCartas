// Organizar ordem das Acoes
// Validar jogadas e determinar vencedor
// Gerenciar pontos e fim da rodada

// Colaboracoes: Time, Partida, Jogador, Carta

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
   Jogador* jogadorAtual;

   int pontoRodada;
   bool trucoPedido;

   public:

   Rodada(Time* t1, Time* t2, const std::vector<Jogador*>& jogadores) {}

   void ordenarJogadores();

   bool ValidarJogada(Carta& carta, Jogador* jogador);
   void AdicionarCartaRodada(Carta& carta, Jogador* jogador);
   Jogador* DefinirVencedorMao();
   Time* DefinirVencedorRodada();

   void pedirTruco();
   void pedirSeis();
   void pedirNove();
   void pedirDoze();
   void aceitarTruco();
   void correrTruco();

   void finalizarRodada();
   void distribuirPontos();

   void getvalorRodada();
   void getrodadaAtual();

   void executarRodada();

};

#endif