# Jogo-Rastros-LI2-19-20---MIEI-UM
Jogo"Rastros" em C, Grupo 4 PL6, Gonçalo Ferreira a93218, Gonçalo Santos a93279, Tiago Carneiro a93207
	 	
  Neste projeto desenvolvido ao longo da UC de LI2, tivemos de criar uma versão no terminal de comandos, do jogo de tabuleiro Rastros.
  Na pasta projeto, encontra-se o jogo completamente operacional, com todos os comandos requiridos, 
e uma versão atualizada do bot, que se chamada apresenta a recomendação de jogada do nosso bot, 
desenvolvido para o jogo e usado para debug do mesmo.
	Na pasta bot, encontra-se a versão utilizada no torneio de bots entre os alunos;
	
#Bot

  No que diz respeito ao nosso bot, utilizamos como algoritmo principal, minmax, e para o otimizar utilizamos
estratégia alpha-beta pruning, que reduz bastante o tempo de processamento. Para as valorações atribuidas às
jogadas no algoritmo, criamos um algoritmo baseado no flood fill para nos indicar, as distâncias de cada casa ao
bot e se as era possivel alcançar. Por fim a profundidade do minmax, é também adaptativa, aumentando consoante o jogo
se desenrola, de forma a ganhar performance.
