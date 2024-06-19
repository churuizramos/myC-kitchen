//Jesus Ruiz Ramos
//CSE 130 Lab 4
//Calculator Program - 2

#include <stdio.h>
#include <stdbool.h>

float add(float x, float y){
	return x + y;
}
float substract(float x, float y){
	return x - y;
}
float multiply(float x, float y){
	return x * y;
}
float divide(float x, float y){
	return x / y;
}
int modulus(int x, int y){
	return x % y;
}

bool checkIfPrime(int x){
	int a;
	for (a = 2; a < x; a++){
		if(x%a==0 && x!=a){
			return false;
		}
	}
	return true;
}

int factorial(int x){
	int factor;
	int facResult = x;
	
	for(factor = x-1; factor > 0; factor--){
		facResult *= factor;
	}
	
	return facResult;
}

float power(int x, int y){
	float powerResult = x;

	for(int factor = 1; factor < y; factor++){
		powerResult *= x;
	}
	
	return powerResult;
	
}

void fibonachi(int n){	
	int fibSeq[n];
	
	fibSeq[0] = 1;
	fibSeq[1] = 1;
	
	for(int x = 2; x <= n; x++){
		fibSeq[x] = fibSeq[x-1] + fibSeq[x-2];
	}
	for(int y = 0; y < n; y++){
		printf("\n%d",fibSeq[y]);
	}
}

int main(){
	float operand1;
	float operand2;
	float result;
	
	int integerNumber = 0;

	int operationCase = 10;
	
	printf("Welcome to the Calculator Program...\n");
	
	while(operationCase != 0){
		printf("\n1) Add\n2) Substract\n3) Multiply\n4) Divide\n5) Modulus\n6) Check if prime\n7) Factorial\n8) Power\n9) Fibonachi Sequence\n0) Exit\nSelection: ");
		scanf("%d", &operationCase);
				
		//addition
		if(operationCase == 1){
			printf("\nWhat is the first number: ");
			scanf("%f", &operand1);
			
			printf("\nWhat is the second number: ");
			scanf("%f", &operand2);
			
			result = add(operand1, operand2);
			printf("\n%.2f + %.2f = %.2f\n", operand1, operand2, result);
		}
		
		//substraction
		if(operationCase==2){
			printf("\nWhat is the first number: ");
			scanf("%f", &operand1);
			
			printf("\nWhat is the second number: ");
			scanf("%f", &operand2);
			
			result = substract(operand1, operand2);
			printf("\n%.2f - %.2f = %.2f\n", operand1, operand2, result);
		}
		
		//multiplication
		if(operationCase==3){
			printf("\nWhat is the first number: ");
			scanf("%f", &operand1);
		
			printf("\nWhat is the second number: ");
			scanf("%f", &operand2);
			
			result = multiply(operand1, operand2);
			printf("\n%.2f x %.2f = %.2f\n", operand1, operand2, result);
		}
		
		//division
		if(operationCase==4){
			printf("\nWhat is the first number: ");
			scanf("%f", &operand1);
		
			printf("\nWhat is the second number: ");
			scanf("%f", &operand2);
			
			while(operand2==0){
				printf("\n!!!Cannot divide by 0...!!!\n");
				
				printf("\nWhat is the second number: ");
				scanf("%f", &operand2);
			}
		
			result = divide(operand1, operand2);
			printf("\n%.2f / %.2f = %.2f\n", operand1, operand2, result);	
		}
		
		//modulus
		if(operationCase==5){
			printf("\nWhat is the first number: ");
			scanf("%f", &operand1);
			
			printf("\nWhat is the second number: ");
			scanf("%f", &operand2);
			
			result = modulus(operand1, operand2);
			printf("\n%.0f %% %.0f = %.0f\n", operand1, operand2, result);
		}
		
		//prime
		if(operationCase==6){
			printf("\nWhat is the number: ");
			scanf("%d", &integerNumber);
			
			if(checkIfPrime(integerNumber) == true){
				printf("\n%d is prime.\n", integerNumber);
			}
			else{
				printf("\n%d is not prime.\n", integerNumber);
			}
		}
		
		//factorial
		if(operationCase==7){
			printf("\nWhat is the number: ");
			scanf("%d", &integerNumber);
			
			if(integerNumber==0){
				printf("\n!0 is 0\n");
			}
			else if(integerNumber==1){
				printf("\n!1 is 1");
			}
			else{
				printf("\n!%d is %d\n", integerNumber, factorial(integerNumber));
			}
		}
		
		//power
		if(operationCase==8){
			printf("\nWhat is the number: ");
			scanf("%f", &operand1);
			
			printf("\nWhat is the power: ");
			scanf("%f", &operand2);
			
			if(operand2 == 0){
				printf("\n%.2f to the power of %.2f is 1\n", operand1, operand2);

			}
			printf("\n%.2f to the power %.2f is 1/%.2f\n", operand1, operand2, power(operand1, operand2));			
		}
		
		//fibonachi sequence
		if(operationCase==9){
			printf("\nHow many numbers from the Sequence: ");
			scanf("%d", &integerNumber);
			
			fibonachi(integerNumber);
			printf("\n");
		}
	}
	
	printf("\nThank you for using the program...\n");
	printf("\nGood Bye!");
	
	return 0;
}