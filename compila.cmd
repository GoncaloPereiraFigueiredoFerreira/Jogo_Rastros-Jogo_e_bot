gcc -c main.c
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
gcc -c bot.c
cd..
cd "Listas Ligadas"
gcc -c listasligadas.c
cd..
gcc -o principal main.o interface\interface.o Logica\funcoes.o dados\dados.o bot\bot.o "Listas Ligadas"\listasligadas.o

