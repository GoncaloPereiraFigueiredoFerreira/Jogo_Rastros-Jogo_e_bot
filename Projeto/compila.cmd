gcc -c mainBOTS.c
cd Logica
gcc -c funcoes.c
cd..
cd interface
gcc -c interface.c
cd..
cd dados
gcc -c dados.c
cd..
cd bot
gcc -c -O2 bot.c
cd..
cd ListasLigadas
gcc -c listasligadas.c
cd..
gcc -o principal main.o interface\interface.o Logica\funcoes.o dados\dados.o bot\bot.o ListasLigadas\listasligadas.o

