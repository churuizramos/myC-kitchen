// CSE 130 Lab 5 - Interactive Story (Using pointers AND arrays)
// By Jesus Ruiz Ramos
// Feb 16, 2024

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int chance;
	chance = (rand() % 3) + 1;
		
//	printf("Chance: %d\n", chance);

	char opinion[20];
	char *pOpinion = &opinion;
	
	char name[20];
	char *pName = &name;
	
	char sport[20];
	char *pSport = &sport;
	
	int height = 0;
	
	printf("Name: ");
	scanf("%s", pName);
	printf("Height (cm): ");
	scanf("%d", &height);
	printf("Favorite Sport: ");
	scanf("%s", pSport);
	
	if(chance == 1){
		pOpinion= "hates";
	}
	else if(chance == 2){
		pOpinion = "loves";
	}
	else if(chance == 3){
		pOpinion = "doesn't care about";
	}
	
	printf("%s is %dcm tall and %s %s.\n", pName, height, pOpinion, pSport);

	return 0;	
}