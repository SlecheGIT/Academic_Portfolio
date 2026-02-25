1) Instalar as bibliotecas básicas da SDL que são usadas pela minha gfx. As bibliotecas que você precisa instalar nesse passo são as seis seguintes:

libsdl1.2debian e libsdl1.2-dev
libsdl-ttf2.0-0 e libsdl-ttf2.0-dev
libsdl-gfx1.2 e libsdl-gfx1.2-dev

Para instalar essas bibliotecas, digite o seguinte comando: 

sudo apt-get install libsdl1.2debian libsdl1.2-dev libsdl-ttf2.0-0 libsdl-ttf2.0-dev libsdl-gfx1.2 libsdl-gfx1.2-dev

2) Baixar e descompactar a biblioteca gfx em um diretório do seu usuário no Linux. Para ver se a gfx está funcional, entre no diretório gfx a partir de onde instalou a biblioteca e digite o comando "make clean" e depois "make". Não pode ocorrer erro. Depois disso, volte para o diretório onde se encontra o programa exemplo.c e digite novamente "make clean" e depois "make". Se não houve erro, execute o programa "exemplo", que abrirá uma janela como a mostrada na Figura 1.