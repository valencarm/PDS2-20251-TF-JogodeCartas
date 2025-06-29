#include "Partida.hpp"

Partida::Partida(int conjuntoRegras, int modoJogo, int aposta, int pontuacaoMaxima)
    : conjuntoRegras(conjuntoRegras), modoJogo(modoJogo), aposta(aposta), pontuacaoMaxima(pontuacaoMaxima) {
    pontuacao = {0, 0}; 
}

Partida::~Partida() {
    // Ainda preencher
}

// ---- Configurações ----

void Partida::setModojogo(int modoJogo){
    setPontuacaoMaxima(modoJogo);
}

void Partida::setPontuacaoMaxima(int modoJogo){
    if(modoJogo == 0){
        pontuacaoMaxima = 12;
    }
    else if(modoJogo == 1){
        pontuacaoMaxima = 10;
    }
    else if(modoJogo == 2){
        pontuacaoMaxima = 24;
    }
}

void Partida::ConfigurarModo(int modo) {
    setModojogo(modo);
    std::cout << "Modo de jogo configurado para: ";
    if(modo == 0){
      std::cout << "modo normal\n";
    }
    else if(modo == 1){
      std::cout << "modo rápido\n";
    }
    else    if(modo == 2){
      std::cout << "modo duas quedas\n";
    }
}

void Partida::setConjuntoregras(int regras) {
    conjuntoRegras = regras;
}

void Partida::ConfigurarRegras(int regras) {
    setConjuntoregras(regras);
    std::cout << "Conjunto de regras configurado: " << regras << "\n";
}

void Partida::setAposta(int valor) {
    aposta = valor;
}

void Partida::ConfigurarAposta(int valor) {
    setAposta(valor);
    std::cout << "Aposta configurada: " << valor << "\n";
}

void Partida::ConfigurarPartida(int modo, int regras, int valor_aposta) {
    ConfigurarModo(modo);
    ConfigurarRegras(regras);
    ConfigurarAposta(valor_aposta);
}

// ---- Pontuação ----

void Partida::atualizarPontuacao(int time, int pontos) {
    if (time < 0 || time >= (int)pontuacao.size()) {
        std::cerr << "⚠️ Erro: Índice de time inválido (" << time << ")\n";
        return;
    }

    pontuacao[time] += pontos;
    std::cout << "Time " << (time + 1) << " recebeu " << pontos
              << " ponto(s). Total: " << pontuacao[time] << "\n";

    if (verificarFimDeJogo()) {
        int vencedor = getTimeVencedor();
        if (vencedor != -1) {
            std::cout << " Time " << (vencedor + 1)
                      << " venceu a partida com " << pontuacao[vencedor] << " pontos!\n";
        } else {
            std::cout << " Erro! Empate: ambos os times atingiram a pontuação máxima.\n";
        }
    }
}

int Partida::getPontuacao(int time) const {
    if (time < 0 || time >= (int)pontuacao.size()) {
        std::cerr << " Erro! Índice de time inválido ao consultar pontuação.\n";
        return -1;
    }
    return pontuacao[time];
}

// ---- Verificação de fim de jogo ----

bool Partida::verificarFimDeJogo() const {
    return pontuacao[0] >= pontuacaoMaxima || pontuacao[1] >= pontuacaoMaxima;
}

int Partida::getTimeVencedor() const {
    bool time1Venceu = pontuacao[0] >= pontuacaoMaxima;
    bool time2Venceu = pontuacao[1] >= pontuacaoMaxima;

    if (time1Venceu && !time2Venceu) return 0;
    if (time2Venceu && !time1Venceu) return 1;
    return -1; // Nenhum time venceu, ou a partida esta empatada
}

// ---- Visualização ----

void Partida::exibirEstado() const {
    std::cout << "\n===== ESTADO DA PARTIDA =====\n";
    std::cout << "Modo de Jogo: " << modoJogo << "\n";
    std::cout << "Conjunto de Regras: " << conjuntoRegras << "\n";
    std::cout << "Aposta Atual: " << aposta << "\n";
    std::cout << "Pontuação - Time 1: " << pontuacao[0] << "\n";
    std::cout << "Pontuação - Time 2: " << pontuacao[1] << "\n";
    std::cout << "Pontuação Máxima: " << pontuacaoMaxima << "\n";
    std::cout << "==============================\n";
}
  bool Partida::isMaoDeDez() const {
    return pontuacao[0] == 10 || pontuacao[1] == 10;
  }

   bool Partida::isMaoDeFerro() const {
    return pontuacao[0] == 10 && pontuacao[1] == 10;
}
