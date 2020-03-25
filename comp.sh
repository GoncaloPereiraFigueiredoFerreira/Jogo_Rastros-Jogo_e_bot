
echo "gcc -c interface/interface.c main.c Logica/funcoes.c dados/dados.c"
gcc -c interface/interface.c main.c Logica/funcoes.c dados/dados.c
echo "gcc -o main main.o interface.o funcoes.o dados.o"
gcc -o main main.o interface.o funcoes.o dados.o

for i in *.o
do 
	echo "rm $i"
	rm $i
done
for i in *.txt
do
	echo "rm $i"
	rm $i
done