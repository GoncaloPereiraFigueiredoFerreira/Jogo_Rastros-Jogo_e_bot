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
gcc -c bot.c
gcc -o botW mainBOTS.o bot.o dados/dados.o interface/interface.o Logica/funcoes.o
