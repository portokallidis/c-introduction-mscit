#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    
    
    srand(time(NULL));
    int maxSN;
    int maxTries;
    int tries = 0;
    int secretNumber;
    int num;
    int games = 0;
    int wins = 0;
    int playAgain = 0;
    
    // validators
    int validMaxSecret (int val){
        return val>100;
    } 
    int validMaxTries (int val){
        return val>=3;
    } 
    int validTries (int val){
        return val<maxTries;
    } 
    
    do {
        tries=0;
        games++;
        do {
            printf("\nChoose maximum for the secret number : ");
            scanf("%d",&maxSN);
            
            if (!validMaxSecret(maxSN)) {
                printf("\nSecret number must be greater than 100\n");
            }
        } while (!validMaxSecret(maxSN));
        
        secretNumber = rand()%maxSN+1;
        printf("SN: %d",secretNumber);
        
        do {
            printf("\nChoose maximum tries : ");
            scanf("%d",&maxTries);
            
            if (!validMaxTries(maxTries)) {
                printf("\nMaximum tries must be greater than or equal to  3\n");
            }
        } while (!validMaxTries(maxTries));
        
        printf("\nOk a secret number has been set and its your job to find it!");
        
        do {
            tries++;
            printf("\n\nGuess the number : ");
            scanf("%d",&num);
            if(num==secretNumber) {
                break;
            } else if(num>secretNumber) {
                printf("This number is greater than the secret number. Please try again.");
            } else {
                printf("This number is lower than the secret number. Please try again.");
            }
        
        } while(validTries(tries));
        
        if(num==secretNumber) {
            wins++;
            printf("\n\n========================");
            printf("\n******  YOU WIN!  ******");
            printf("\n\n========================");
        } else {
            printf("\n\n========================");
            printf("\n------- GAME OVER ------");
            printf("\n\n========================");
        }
        
        playAgain = 0;
        do {
            printf("\n\n1. Play again");
            printf("\n2. Exit");
            printf("\nChoose what to do: ");
            scanf("%d",&playAgain);
        } while(playAgain!=1&&playAgain!=2);
        
    } while (playAgain==1);
    
    // exit phase
    // display stats
    printf("\n\nFinal score: ");
    if(games-wins==wins) {
        printf("Its a tie!");
    } else if(games-wins>wins) {
        printf("Computer wins!");
    } else {
        printf("Player wins!");
    }
    
    printf("\n\n====Game Statistics====");
    printf("\nTotal games: %d",games);    
    printf("\nComputer score: %d",games-wins);
    printf("\nPlayer score: %d",wins);
    
    
	return 0;
}
