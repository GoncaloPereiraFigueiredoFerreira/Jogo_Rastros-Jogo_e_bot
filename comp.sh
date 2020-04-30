echo "gcc -c -O2 interface/interface.c main.c Logica/funcoes.c dados/dados.c bot/bot.c ListasLigadas/listasligadas.c"
gcc -c -O2 -lm interface/interface.c main.c Logica/funcoes.c dados/dados.c bot/bot.c ListasLigadas/listasligadas.c 
echo "gcc -o main main.o interface.o funcoes.o dados.o bot.o listasligadas.o"
gcc -o main main.o interface.o funcoes.o -lm dados.o bot.o listasligadas.o
#echo "gcc -o gen gen.o interface.o funcoes.o dados.o bot.o listasligadas.o"
#gcc -o gen gen.o interface.o funcoes.o -lm dados.o bot.o listasligadas.o

for i in *.o
do 
	echo "rm $i"
	rm $i
done
for i in *.txt
do
	if [ "$i" != 'test.txt' ] && [ "$i" != 'test1.txt' ] && [ "$i" != 'bug.txt' ]
	then
		echo "rm $i"
		rm $i
	fi
done 