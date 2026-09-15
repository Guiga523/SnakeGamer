#  Snake Game - C++ & Raylib

Um clássico jogo da cobrinha (Snake) desenvolvido em C++ utilizando a biblioteca gráfica [Raylib](https://www.raylib.com/). Este projeto foi criado com foco em recriar as mecânicas clássicas de movimento em grade (grid), além de implementar um sistema de câmera com feedback visual.

##  Gameplay

![Demonstração do Gameplay do Snake](<img width="426" height="240" alt="Demostração do GameSnaker" src="https://github.com/user-attachments/assets/78f6ebf2-dc51-4709-b702-d7102b44c20b" />
)

##  Funcionalidades

* **Movimentação Clássica em Grid:** A cobrinha se move perfeitamente alinhada a uma grade fixa no cenário.
* **Sistema de Crescimento:** O corpo cresce dinamicamente e segue perfeitamente o rastro da cabeça usando vetores matemáticos.
* **Sistema de Colisões:** Detecção precisa de colisão com as bordas do mapa e com o próprio corpo (Game Over).
* **Screen Shake (Tremor de Tela):** Efeito visual de impacto utilizando `Camera2D` da raylib sempre que o jogador perde a partida.
* **Tela Cheia Responsiva:** Suporte para Fullscreen sem bordas pressionando `F11`, mantendo o mapa centralizado e preservando a proporção em qualquer monitor.
* **Sistema de Pontuação:** Acumule pontos a cada maçã consumida.
* **Prevenção de Bugs Clássicos:** Sistema de trava de direção (input lock) implementado para evitar comandos conflitantes que causam morte instantânea.

##  Controles

* **W, A, S, D:** Movimentam a cobrinha.
* **F11:** Alterna entre Modo Janela e Tela Cheia.
* **ENTER:** Reinicia a partida após a tela de Game Over.

##  Tecnologias e Ferramentas

* **Linguagem:** C++
* **Biblioteca Gráfica:** Raylib
* **IDE:** Visual Studio

##  Como Executar o Projeto Localmente

1. Certifique-se de ter o **Visual Studio** instalado com a carga de trabalho de "Desenvolvimento para Desktop com C++".
2. Clone este repositório no seu computador:
   ```bash
   git clone [https://github.com/SEU_USUARIO/SEU_REPOSITORIO.git](https://github.com/SEU_USUARIO/SEU_REPOSITORIO.git)
