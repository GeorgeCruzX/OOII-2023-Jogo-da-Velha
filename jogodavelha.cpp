#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//---Mostrar o tabuleiro---
void tabuleiro (char casas2 [3] [3]) {
	system("cls");
	printf("\t %c | %c | %c \n", casas2[0] [0], casas2[0] [1],casas2[0] [2]);
	printf("\t-----------\n");
	printf("\t %c | %c | %c \n", casas2[1] [0], casas2[1] [1],casas2[1] [2]);
	printf("\t-----------\n");
	printf("\t %c | %c | %c \n", casas2[2] [0], casas2[2] [1],casas2[2] [2]);
}

int main (){
	char casas[3] [3] = {	{'1','2','3'},
							{'4','5','6'},
							{'7','8','9'},
	};
	char res;
	int opc,cont_jogadas,l,c,vez = 0,i,j;
	
	while(true){
		printf("#########-JOGO DA VELHA-#########\n\n");
		printf("|MENU|\n");
		printf("\n1 - Jogar   2 - Como Jogar   3 - Creditos   4 - Sair\n");
		scanf ("%i",&opc);
		
		switch(opc){
			
			case 1:
				 do{	
					cont_jogadas = 1;
					//---Limpando o tabuleiro---
					for(i=0;i<=2;i++){
						for(j=0;j<=2;j++){
							casas[i] [j] = ' ';
						}
					}
					do{
						tabuleiro (casas);
						if(vez%2==0){
							printf("Jogador 1\n");
						}else{
							printf("Jogador 2\n");
						}
						printf("Digite a linha: ");
						scanf("%i",&l);
						printf("Digite a coluna: ");
						scanf("%i",&c);
						
						//---Jogada inválida---
						if(l < 1 || c < 1 || l > 3 || c > 3) {
							printf("JOGADA INVALIDA!\n");
							system("pause");
							l = 0;
							c = 0;
						}else if(casas[l-1] [c-1] != ' ') {
							printf("JOGADA INVALIDA!\n");
							system("pause");
							l = 0;
							c = 0;	
						}
						//---Jogada Válida---
						else{
							if (vez%2==0) {
								casas[l-1] [c-1] = 'X';
							}else {
								casas[l-1] [c-1] = 'O';
							}
						vez++;
						cont_jogadas++;
						}
						//---JOGADOR Nº 1---
						//---Acertos Horizontais---
						if(casas[0][0]=='X' && casas[0][1]=='X' && casas[0][2]=='X') {cont_jogadas = 11;}
						if(casas[1][0]=='X' && casas[1][1]=='X' && casas[1][2]=='X') {cont_jogadas = 11;}
						if(casas[2][0]=='X' && casas[2][1]=='X' && casas[2][2]=='X') {cont_jogadas = 11;}
						//---Acertos Verticais---
						if(casas[0][0]=='X' && casas[1][0]=='X' && casas[2][0]=='X') {cont_jogadas = 11;}
						if(casas[0][1]=='X' && casas[1][1]=='X' && casas[2][1]=='X') {cont_jogadas = 11;}
						if(casas[0][2]=='X' && casas[1][2]=='X' && casas[2][2]=='X') {cont_jogadas = 11;}
						//---Acertos Diagonais---
						if(casas[0][0]=='X' && casas[1][1]=='X' && casas[2][2]=='X') {cont_jogadas = 11;}
						if(casas[0][2]=='X' && casas[1][1]=='X' && casas[2][0]=='X') {cont_jogadas = 11;}
						
						//---JOGADOR Nº 2---
						//---Acertos Horizontais---
						if(casas[0][0]=='O' && casas[0][1]=='O' && casas[0][2]=='O') {cont_jogadas = 12;}
						if(casas[1][0]=='O' && casas[1][1]=='O' && casas[1][2]=='O') {cont_jogadas = 12;}
						if(casas[2][0]=='O' && casas[2][1]=='O' && casas[2][2]=='O') {cont_jogadas = 12;}
						//---Acertos Verticais---
						if(casas[0][0]=='O' && casas[1][0]=='O' && casas[2][0]=='O') {cont_jogadas = 12;}
						if(casas[0][1]=='O' && casas[1][1]=='O' && casas[2][1]=='O') {cont_jogadas = 12;}
						if(casas[0][2]=='O' && casas[1][2]=='O' && casas[2][2]=='O') {cont_jogadas = 12;}
						//---Acertos Diagonais---
						if(casas[0][0]=='O' && casas[1][1]=='O' && casas[2][2]=='O') {cont_jogadas = 12;}
						if(casas[0][2]=='O' && casas[1][1]=='O' && casas[2][0]=='O') {cont_jogadas = 12;}
						
					//---RESULTADO---
					}
					while(cont_jogadas <= 9);
						tabuleiro(casas);
						if(cont_jogadas==10) {
							printf("VELHA!!!\nJogo Empatado\n");
						}if(cont_jogadas==11){
							printf("JOGADOR 1 VENCEU!!!!\n");
						}if(cont_jogadas==12){
							printf("JOGADOR 2 VENCEU!!!!\n");
						}
						printf("Deseja jogar novamente? [S-N]\n");
						scanf ("%s", &res);
						if(res == 'n' || res == 'N'){
							break;
						}
					}
					while(res == 's' || res == 'S');
				break;
			
			case 2: 
				system("cls");
				printf("#########--COMO JOGAR--#########\n");
				printf("\nO jogador deve escolher uma linha(1 a 3) e uma coluna(1 a 3) para marcar a opcao em uma lacuna que esteja vazia.\nO jogo acaba quando um jogador conseguir completar tres lacunas sequencialmente\n\n");
				break;
			
			case 3:
				system("cls");
				printf("\nSeminario de Linguagens de Programacao\n");
				printf("\nC++ - Jogo da Velha\n");
				break;
			
			case 4:
				printf("Obrigado por jogar! :)\n\n");
				exit(0);
				break;
				
			default:
				printf("Opcao invalida!\n");
				printf("Escolha somente as opcoes (1-4)\n");
				break;
		}
	}
}
