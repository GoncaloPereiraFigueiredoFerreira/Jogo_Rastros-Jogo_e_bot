echo "gcc -c mainBOTS.c"
gcc -c mainBOTS.c
echo "gcc -o botU mainBOTS.o bot.o ../dados/dados.o ../interface/interface.o ../ListasLigadas/listasligadas.o ../Logica/funcoes.o"
gcc -o bot mainBOTS.o bot.o ../dados/dados.o ../interface/interface.o ../ListasLigadas/listasligadas.o ../Logica/funcoes.o