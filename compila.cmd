gcc -c main.c
cd Logica
gcc -c interface.c
gcc -c funcoes.c
cd..
gcc -o principal main.o Logica\interface.o Logica\funcoes.o
