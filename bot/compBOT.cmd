gcc -c mainBOTS.c
gcc -c funcoes.c
gcc -c interface.c
gcc -c dados.c
gcc -c -O2 bot.c
gcc -o botW mainBOTS.o bot.o dados.o interface.o funcoes.o
