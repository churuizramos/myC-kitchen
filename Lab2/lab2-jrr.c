//Jesus Ruiz Ramos
//CSE 130 Lab 2
//
//This is a conversion table,
//
//inputs: currency, amount
//outputs: table of conversion amounts for 5 currencies

#include <stdio.h>

int main(){
	int currency;
	float moneyInput = 0.00;
	float usdOut, gbpOut, cadOut, eurOut, audOut; //output  variables for each currency
	
	start:
	
	printf("\nThis is a currency converter.");
	printf("\nWhat currency are you using:\t1. USD|\t2. GBP|\t3. CAD|\t4. EUR|\t5. AUD|\t6. More info...\n");
	scanf("%d", &currency);
	
	printf("\nAmount being converted: ");
	scanf("%f", &moneyInput);
	
	switch(currency){
		case 1: //USD to others
			usdOut = moneyInput;
			gbpOut = moneyInput * 1.8264;
			cadOut = moneyInput * 0.9499;
			eurOut = moneyInput * 1.4684;
			audOut = moneyInput * 0.8618;
		break;
		case 2: //GBP to others
			usdOut = moneyInput * 0.5475;
			gbpOut = moneyInput;
			cadOut = moneyInput * 0.5201;
			eurOut = moneyInput * 0.8040;
			audOut = moneyInput * 0.4718;
		break;
		case 3: //CAD to others
			usdOut = moneyInput * 1.0527;
			gbpOut = moneyInput * 1.9226;
			cadOut = moneyInput;
			eurOut = moneyInput * 1.5458;
			audOut = moneyInput * 0.9072;
		break;
		case 4: //EUR to others
			usdOut = moneyInput * 0.6809;
			gbpOut = moneyInput * 1.2437;
			cadOut = moneyInput * 0.6468;
			eurOut = moneyInput;
			audOut = moneyInput * 0.5868;
		break;
		case 5: //AUD to others
			usdOut = moneyInput * 1.1603;
			gbpOut = moneyInput * 2.1192;
			cadOut = moneyInput * 1.1022;
			eurOut = moneyInput * 1.7039;
			audOut = moneyInput;
		break;
		case 6: //Definitions of each option and returns user to the beginning
			printf("\n1. United States Dollars\n2. Great British Pounds\n3. Canadian Dollars\n4. Euros\n5. Australian Dollars\n");
			goto start;
	}
	
	printf("\nConversions:\n");
	printf("\nUSD: %.2f\t", usdOut);
	printf("GBP: %.2f\t", gbpOut);
	printf("CAD: %.2f\t", cadOut);
	printf("EUR: %.2f\t", eurOut);
	printf("AUD: %.2f\n", audOut);
}