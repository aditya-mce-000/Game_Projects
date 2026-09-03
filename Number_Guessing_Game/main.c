#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void true_game(int level, int random_number);

int main(void)
{
    printf("Welcome to Number Guessing Game.\nIn this game, you will guess the random number chosen by computer.\nThere are three difficulty levels.\nYou must complete the prior to have acccess to the next level\n");

    srand(time(NULL));

    int choice;
    int game = 0;
    do{
        int level = 1;
        int random_number = (rand() % 100) + 1; // generates random number
        printf("Computer has guessed its number.\n");
        true_game(level, random_number);
        game++;

        printf("Now you have three choices.\n1.) Play again with same level of difficulty(aka level 1).\n2.) Play again with next level of difficult(aka level 2).\n3.) End the game.\n");
        do{
            printf("Please choose a valid option: ");
            scanf("%d", &choice);
        }while (choice != 1 && choice != 2 && choice != 3);

        if (choice == 3){
            printf("Congrats on completing %d games\n", game);
            printf("Thanks for Playing.\n");
            return 3;
        }
    }while (choice == 1); 
    
    do{
        int level = 2;
        int random_number = (rand() % 1000) + 1; // generates random number
        printf("Computer has guessed its number.\n");
        true_game(level, random_number);
        game++;
        
        printf("Now you have three choices.\n1.) Play again with same level of difficulty(aka level 2).\n2.) Play again with next level of difficult(aka level 3).\n3.) End the game.\n");
        do{
            printf("Please choose a valid option: ");
            scanf("%d", &choice);
        }while (choice != 1 && choice != 2 && choice != 3);

        if (choice == 3){
            printf("Congrats on completing %d games\n", game);
            printf("Thanks for Playing.\n");
            return 3;
        }
    }while (choice == 1); 
    
    do{
        int level = 3;
        int random_number = (rand() % 10000) + 1; // generates random number
        printf("Computer has guessed its number.\n");
        true_game(level, random_number);
        game++;
        
        printf("Now you have two choices.\n1.) Play again with same level of difficulty(aka level 3).\n2.) End the game.\n");
        do{
            printf("Please choose a valid option: ");
            scanf("%d", &choice);
        }while (choice != 1 && choice != 2);

        if (choice == 2){
            printf("Congrats on completing %d games\n\n", game);
            printf("Thanks for Playing.\n");
            return 2;
        }

    }while (choice == 1); 

    return 0;
} 

void true_game(int level, int random_number)
{
    int guessed_number = 0; // user number
    int tries = 0;
    while (guessed_number != random_number){
        tries++;
        printf("Guess the number between 1 and %d: ", (int)round(10 * (pow(10,level))));
        scanf("%d", &guessed_number);
        if (guessed_number < random_number){
            printf("Try a larger number.\n");
        }
        if (guessed_number > random_number)
        {
            printf("Try a smaller number.\n");
        }
    }
        printf("You guessed correct in %d tries.\n", tries);
}