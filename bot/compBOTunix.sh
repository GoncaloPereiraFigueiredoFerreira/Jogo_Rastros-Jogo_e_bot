echo "gcc -c mainBOTS.c bot.c dados/dados.c interface/interface.c Logica/funcoes.c"
gcc -c mainBOTS.c bot.c dados.c interface.c funcoes.c
echo "gcc -o botU mainBOTS.o bot.o dados.o interface.o funcoes.o"
gcc -o botU mainBOTS.o bot.o dados.o interface.o funcoes.o