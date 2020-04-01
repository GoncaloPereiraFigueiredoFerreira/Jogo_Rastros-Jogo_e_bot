
ESTADO* cpEst(*est){
	ESTADO *est1 = malloc(sizeof(ESTADO));
	int i,i1;
	for(i=0;i<8;i++)
		for(i1=0;i1<8;i1++)
			est1->tab[i][i1] = est->tab[i][i1];
	est1->pos.x = est->pos.x;
	est1->pos.y = est->pos.y;
	est1->num_jogadas = est->num_jogadas; 
	est1->jogador_atual = est->jogador_atual;
	return est1;
}

int max(int v[],int n){
	int i = v[--n];
	for(--n;n!=0;n--)
		if (v[n]>v[i]) i = n;
	return i;
}

COORDENADA bot (ESTADO *est){
	int n,i,v[8];
	COORDENADA m[8];
	ESTADO *est1;
	est1 = cpEst(est);
	n = jogPoss(est,m);
	for(i = 0;i<n;i++){
		joga(est1,m[i]);
		v[i] = minmax(est1);
		est1 = cpEst(est);
	}
}

