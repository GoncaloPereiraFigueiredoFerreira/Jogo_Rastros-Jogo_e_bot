gcc -c main.c
gcc -c funcoes.c
gcc -c interface.c
gcc -c dados.c
gcc -c -O2 bot.c
gcc -c listasligadas.c
gcc -o principal main.o interface.o funcoes.o dados.o bot.o listasligadas.o

