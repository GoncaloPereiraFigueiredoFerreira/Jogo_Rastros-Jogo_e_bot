
echo "gcc -c interface/interface.c main.c Logica/funcoes.c dados/dados.c bot/bot.c"
gcc -c interface/interface.c main.c Logica/funcoes.c dados/dados.c bot/bot.c
echo "gcc -o main main.o interface.o funcoes.o dados.o bot.o"
gcc -o main main.o interface.o funcoes.o dados.o bot.o
#echo "gcc -o bot bot.o interface.o funcoes.o dados.o"
#gcc -o b bot.o interface.o funcoes.o dados.o

for i in *.o
do 
	echo "rm $i"
	rm $i
done
for i in *.txt
do
	if [ "$i" != 'test.txt' ] && [ "$i" != 'test1.txt' ]
	then
		echo "rm $i"
		rm $i
	fi
done 