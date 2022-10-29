#include <stdio.h>
#include <stdlib.h>

// Este projeto não foi criado por mim fiz uma copia do youtube, só para práticar C

char game[3] [3];
char play1[50], play2[50];

void iniciar() {
	int a, b;
	for (a = 0; a < 3; a++) {
		for (b = 0; b < 3; b++) {
			game[a] [b] = 'd';
		}
	}
}

int valendo(char letra) {
	if(letra == 'x' || letra == '0')
		return 1;
	else
		return 0;
}

int cordenacao(int x, int y) {
	if(x >= 0 && x < 3) {
		if(y >= 0 && y < 3)
		return 1;
	}
	return 0;
}

int vazio(int x, int y) {
	if(game[x][y] != 'x' && game[x][y] != '0')
		return 1;
		return 0;
}

int venceulinha() {
	int a, b, igual = 1;
	for(a = 0; a < 3; a++){
		for(b = 0; b < 2; b++){
			if(valendo(game[a][b]) && game[a][b] == game[a][b+1])
			igual++;
		}
		if(igual == 3)
			return 1;
		igual = 1;
	}
	return 0;
}

int venceucoluna() {
	int a, b, igual = 1;
	for(a = 0; a < 3; a++){
		for(b = 0; b < 2; b++){
			if(valendo(game[b][a]) && game[b][a] == game[b+1][a])
			igual++;
		}
		if(igual == 3)
			return 1;
		igual = 1;
	}
	return 0;
}

int venceudiagoum() {
	int a, igual = 1;
	for(a = 0; a < 2; a++) {
		if(valendo(game[a][a]) && game [a][a] == game[a+1][a+1])
			igual++;
	}
	if(igual == 3)
		return 1;
	else
		return 0;
}

int venceudiagodois() {
	int a, igual = 1;
	for(a = 0; a < 2; a++) {
		if(valendo(game[a][3-a-1]) && game [a][3-a-1] == game[a+1][3-a-2])
			igual++;
	}
	if(igual == 3)
		return 1;
	else
		return 0;
}

void visao() {
	int l, c;
	
	printf("\n\t   0   1   2\n");
	for(l = 0; l < 3; l++){
		printf("\t%d ", l);
		for(c = 0; c < 3; c++){
			if(valendo(game[l][c])){
				if(c < 2)
					printf(" %c |", game[l][c]);
				else
					printf(" %c ", game[l][c]);
			}
			else{
				if(c < 2)
					printf("   |");
				else
					printf("   ");
			}
		}
		if(l < 2)
			printf("\n\t   ----------\n");
	}
}

void jogar() {
	int a, b, valendo, jogadas = 0, vencedor = 0, ordem = 1;
	
do{
	do{
		visao();
		printf("\nDigiti a jogada: ");
		scanf("%d%d", &a, &b);
		valendo = cordenacao(a, b);
		if(valendo == 1)
			valendo += vazio(a, b);
	}while(valendo != 2);
	if(ordem == 1)
		game[a] [b] = 'x';
	else
		game[a] [b] = '0';
	jogadas++;
	ordem++;
	if(ordem == 3)
		ordem = 1;
	vencedor += venceulinha();
	vencedor += venceucoluna();
	vencedor += venceudiagoum();
	vencedor += venceudiagodois();
}while(vencedor == 0 && jogadas < 9);
		
		if(vencedor != 0){
			if(ordem - 1 == 1)
	printf("\nParabens!!! Voce ganhou..... %s\n", play1);
			else
	printf("\nParabens!!! Voce ganhou..... %s\n", play2);
	}
		else
	printf("Fim das jogadas nao houve ganhador!!!!!");
}

int main() {
	
	int op;
	
	printf("1 Play digiti seu nome: ");
	fgets(play1, 50, stdin);
	printf("2 Play digiti seu nome: ");
	fgets(play2, 50, stdin);
	
	do {
		iniciar();
		jogar();
		printf("Deseja jogar novamente??\n1 - sim\n2 - nao\n");
		scanf("%d", &op);
	} while(op == 1);
	
	return 0;
}
