

<!DOCTYPE html>
<html lang="pt-BR">
<head>
  <meta charset="UTF-8">
 
</head>
<body>

  <h1>tp-pds2: truco</h1>
  <p>Trabalho prático para a matéria de PDS2</p>
  <p>Participantes: Aurora Cristina Bombassaro, Gabriel dos Reis Rezende da Silva, Vitor Alencar de Mello</p>

  <h3>User Stories</h3>

  <div class="story">
    <p><strong>1 - Um jogador leigo que gostaria de assistência para jogar.</strong><br>
    <em>Critérios de aceitação:</em></p>
    <ul>
      <li>Menu com regras do jogo</li>
      <li>Mostrar a ordem das cartas</li>
      <li>Glossário de termos</li>
      <li>Dicas que variam do contexto</li>
    </ul>
  </div>

  <div class="story">
    <p><strong>2 - Um jogador casual, que quer se divertir.</strong><br>
    <em>Critérios de aceitação:</em></p>
    <ul>
      <li>Jogar com os amigos</li>
      <li>Interface simples e intuitiva</li>
      <li>Regras simplificadas</li>
    </ul>
  </div>

  <div class="story">
    <p><strong>3 - Um jogador competitivo, que usa de artimanhas e técnicas não usuais.</strong><br>
    <em>Critérios de aceitação:</em></p>
    <ul>
      <li>Ocultar cartas ou estratégias</li>
      <li>Formas de passar sinais ou comunicar com o parceiro</li>
      <li>Definir ordem de pessoas na mesa</li>
    </ul>
  </div>

  <div class="story">
    <p><strong>4 - Um jogador rígido que gostaria de ter regras muito bem definidas e firmes.</strong><br>
    <em>Critérios de aceitação:</em></p>
    <ul>
      <li>Conjunto de regras restritas</li>
      <li>Situações bem definidas e sem incertezas</li>
      <li>Prevenir jogadas maliciosas</li>
    </ul>
  </div>

  <div class="story">
    <p><strong>5 - Um jogador mais experiente que quer opções de customização.</strong><br>
    <em>Critérios de aceitação:</em></p>
    <ul>
      <li>Customização do baralho</li>
      <li>Opções de cores e temas</li>
    </ul>
  </div>

  <div class="story">
    <p><strong>6 - Um jogador que gostaria de poder apostar nos seus jogos.</strong><br>
    <em>Critérios de aceitação:</em></p>
    <ul>
      <li>Consentimento entre os participantes</li>
      <li>Identificar participantes e valores</li>
      <li>Limites mínimos e máximos de aposta</li>
    </ul>
  </div>

  <div class="story">
    <p><strong>7 - Um jogador que gostaria de jogar partidas mais rápidas, para passar o tempo.</strong><br>
    <em>Critérios de aceitação:</em></p>
    <ul>
      <li>Regras alternativas que aceleram o jogo</li>
      <li>Repetição da partida com as mesmas configurações</li>
      <li>Tempo máximo por jogada</li>
    </ul>
  </div>

  <div class="story">
    <p><strong>8 - Um jogador que quer jogar apenas com um único outro jogador.</strong><br>
    <em>Critérios de aceitação:</em></p>
    <ul>
      <li>Modo 1x1</li>
      <li>Regras adaptadas para 2 jogadores</li>
    </ul>
  </div>

  <h3>Cartões CRC</h3>

  <div class="crc">
    <p><strong>1 - Partida</strong></p>
    <p><em>Responsabilidades:</em></p>
    <ul>
      <li>Controlar o estado da partida</li>
      <li>Controlar a pontuação dos times e o estado do jogo</li>
      <li>Definir o modo de jogo e o conjunto de regras</li>
      <li>Gerenciar apostas</li>
    </ul>
    <p><em>Colaborações:</em> Time, Rodada, Jogador</p>
  </div>

  <div class="crc">
    <p><strong>2 - Baralho</strong></p>
    <p><em>Responsabilidades:</em></p>
    <ul>
      <li>Criar um baralho de Truco</li>
      <li>Embaralhar, organizar e distribuir as cartas</li>
      <li>Lidar com ações especiais</li>
      <li>Definir quem embaralha e repor cartas</li>
    </ul>
    <p><em>Colaborações:</em> Jogador, Carta</p>
  </div>

  <div class="crc">
    <p><strong>3 - Carta</strong></p>
    <p><em>Responsabilidades:</em></p>
    <ul>
      <li>Armazenar valor e naipe</li>
      <li>Comparar com outras cartas</li>
      <li>Validar jogada</li>
      <li>Retornar imagem da carta</li>
    </ul>
    <p><em>Colaborações:</em> Baralho, Jogador, Rodada</p>
  </div>

  <div class="crc">
    <p><strong>4 - Jogador</strong></p>
    <p><em>Responsabilidades:</em></p>
    <ul>
      <li>Guardar cartas</li>
      <li>Utilizar cartas válidas</li>
      <li>Realizar ações no turno</li>
      <li>Comunicar-se com parceiro</li>
      <li>Armazenar dados do jogador</li>
    </ul>
    <p><em>Colaborações:</em> Carta, Time, Partida</p>
  </div>

  <div class="crc">
    <p><strong>5 - Rodada</strong></p>
    <p><em>Responsabilidades:</em></p>
    <ul>
      <li>Organizar ordem das ações</li>
      <li>Validar jogadas e determinar vencedor</li>
      <li>Gerenciar pontos e notificar fim da rodada</li>
    </ul>
    <p><em>Colaborações:</em> Time, Partida, Jogador, Carta</p>
  </div>

  <div class="crc">
    <p><strong>6 - Time</strong></p>
    <p><em>Responsabilidades:</em></p>
    <ul>
      <li>Definir jogadores e armazenar pontuação</li>
      <li>Definir ações da dupla e comunicação</li>
      <li>Mostrar estatísticas do time</li>
    </ul>
    <p><em>Colaborações:</em> Jogador, Partida, Rodada</p>
  </div>

</body>
</html>
