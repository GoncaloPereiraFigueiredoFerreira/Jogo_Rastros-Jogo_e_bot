#include <stdio.h> 

void desenhal(){ 
	printf("  ");
	for(int i = 0;i<8;i++) printf("+---");
	putchar('+');
	putchar('\n');
}

void desenha(char f[8][8]){
	printf("    A   B   C   D   E   F   G   H\n");
	for(int i = 0;i!=8;i++){
		desenhal();
		printf("%d ",i+1);
		for(int j = 0;j!= 8;j++)
			printf("| %c ",f[i][j]);
		putchar('|');
		putchar('\n');
	}
	desenhal();
}

int main(){
	struct pos{int x,y;}pos;
	char m[16];
	char f[8][8] = {{'.','.','.','.','.','.','.','2'},
	                {'.','.','.','.','.','.','.','.'},
	                {'.','.','.','.','.','.','.','.'},
	                {'.','.','.','.','*','.','.','.'},
	                {'.','.','.','.','.','.','.','.'},
	                {'.','.','.','.','.','.','.','.'},
	                {'.','.','.','.','.','.','.','.'},
	                {'1','.','.','.','.','.','.','.'}};

	desenha(f);
	return 0;
}
