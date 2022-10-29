#include <stdio.h>
#include <math.h>

int main() {
	
	float A, B, C, Del, BasOn, BasTwo;
	
	printf("\nDigite o valor de A: ");
	scanf("%f", &A);
	printf("\nDigite o valor de B: ");
	scanf("%f", &B);
	printf("\nDigite o valor de C: ");
	scanf("%f", &C);
	
	Del = B*B-4*A*C;
	
	if(Del < 0.0) {
		printf("\nO Delta Negativo.\n");
	} else{
		printf("\nO valor do Delta e: %.0f\n", Del);
	}
	
	BasOn = -B+sqrt(Del)/2*A; // Há um erro de matemática na formula não conseguir a solução
	
	if(Del < 0.0) {
		printf("\nNao Temos Bhaskara!!!\n");
	} else{
		printf("\nBhaskara Linha'1' Vale: %.3f\n", BasOn);
	}
	
	BasTwo = -B+sqrt(Del)/2*A;
	
	if(Del < 0.0) {
		printf("\nNao Temos Bhaskara!!!\n");
	} else{
		printf("\nBhaskara Linha'2' Vale: %.3f\n", BasTwo);
	}
	
	return 0;
}
