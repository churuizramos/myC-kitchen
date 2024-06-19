//Jesus Ruiz Ramos
//CSE 130 Lab 3
//Calculator Program

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

int main(){
	float operand1;
	float operand2;
	float result;
	
	int integerNumber = 0;

	int operationCase;
	
	printf("Welcome to the Calculator Program...\n");
	
	while(operationCase != 7){
		printf("\n1) Add\n2) Substract\n3) Multiply\n4) Divide\n5) Modulus\n6) Check if prime\n7) Exit\nSelection: ");
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
		
		//input error
		if(operationCase > 7 || operationCase < 1){
			printf("\n!!!Invalid entry...!!!\n");
		}
	}
	
	printf("\nThank you for using the program...\n");
	
	return 0;
}