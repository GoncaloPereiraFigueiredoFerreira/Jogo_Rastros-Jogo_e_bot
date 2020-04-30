#include "interface/interface.h"
#include <time.h>
#include <stdlib.h>

#define POP 100
#define CAR 2

int jogo(int gen[],int gen1[]){
	clock_t diff,t = clock();
	ESTADO *est = malloc(sizeof(ESTADO));
	inicia(est);
	while(!verificaFim(est)){
		if (est->jogador_atual == 1) jogar(est,bot(est,gen));
		else jogar(est,bot(est,gen1));
	}
	diff = clock() - t;

	free(est);
	return verificaFim(est);
}

int pick(int score[],int t){
	int i,r;
	r = rand()%t;
	for(i = 0;i<POP;i++){
		if (r<=score[i]) {r = i;i = POP;}
		else r-=score[i];
	}
	return r;
}

void next(int gen[],int score[]){
	int i,i1,p,p1,r,ngen[POP*CAR],t=0;
	for(i = 0;i<POP;i++){
		score[i] += score[i];
		t +=score[i]; 
	}
	for(i = 0;i<POP;i++){
		p = pick(score,t);
		p1 = pick(score,t);
		for(i1 = 0;i1<CAR;i1++){
			r = rand()%2;
			ngen[i*CAR+i1] = gen[p*CAR+i1]*r + gen[p*CAR+i1]*((r+1)%2)+(rand()%3-1); 
			if (ngen[i*CAR+i1]>30) ngen[i*CAR+i1] = 30;
			else if (ngen[i*CAR+i1]<0) ngen[i*CAR+i1] = 0;
		}
	}
	for(i = 0;i<CAR*POP;i++) gen[i] = ngen[i];
}

int main(){
	clock_t diff,t1 = clock();
	int i2,i3,i,i1,t = 0;
	int gen[POP*CAR],score[POP];
	FILE *f;
	srand(time(0));
	for(i = 0;i<(POP)*CAR;i++) gen[i] = rand()%31;
	for(t = 0;t<100;t++){
		for(i1 = 0;i1<POP;i1++) score[i1] = 0;
		for(i = 0;i<POP;i++){
			for(i1 = i+1;i1<POP;i1++){
				if (jogo(gen+(i*CAR),gen+(i1*CAR)) == 1) score[i]++;
				else score[i1]++;
				if (jogo(gen+(i1*CAR),gen+(i*CAR)) == 1) score[i1]++;
				else score[i]++;
			}
		}
		printf("%d\n",t);
		for(i2 = 0;i2<POP;i2++){ 
			for (i3 = 0;i3 <CAR;i3++){
				printf("%d,",gen[i2*CAR+i3]);
			}
			printf("|%d",score[i2]);
			putchar('\n');
		}
		printf("%d\n",t );
		next(gen,score);
	}
	diff = clock() - t1;
	printf("tempo-%ldms\n",diff*1000/CLOCKS_PER_SEC);
	f = fopen("number.txt","w");
	for(i = 0;i<POP;i++){
		for(i1 = 0;i1<CAR;i1++){
			fprintf(f, "%d,",gen[i*CAR+i1]);
		}
		fprintf(f,"|%d\n",score[i]);
	}
	fclose(f);
	return 0;
}