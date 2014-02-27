#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CHARSIZE 10

void mainloop(void);
void random_number(void);
void printbitssimple(int);
int  compare_user_input(char*);

int guess_num_from_binary(void);


int main(void) 
{

int random_num = 0;
int guessed_num = 0;
int counter = 0; 
int play_on = 1;
char response[CHARSIZE];

printf("\n\t The BitShape Game \n"); 
    while(play_on)
    {
        printf("Enter a choice, which game you would like to play:\n");
        printf("1 - Guess a number from it's bit shape ...\n");
        printf("2 - Given an integer type in it's bit shape ...2\n");
        fgets(response, CHARSIZE, stdin);
        printf("Printing s: %s\n", response);
        switch(atoi(response)){
            
            case 1:
                printf("Guess a number from it's bit shape ...\n");
                guess_num_from_binary();
                break;
            case 2:
                printf("Play version 2\n");
                break;
            case 3:
                printf("Good bye\n");
                play_on = 0;
                break;
            default:
                printf("Did not understand your input...\n");
                break;
        
        }
    }
    return 0;   
}

/* Print n as a binary number */
void printbitssimple(int n) 
{
    unsigned int i;
    i = 1<<(sizeof(n) * 4 - 1);
    while (i > 0) 
    {
        if (n & i)  /* check if any of the bits of n is not 0 .*/
            printf("1");
        else
            printf("0");
        i >>= 1;
    }
}
/*show the user a bit shape and compare the input*/
int guess_num_from_binary(void){
    int random_num ;
    char ans[8];
    srand(time(NULL));
    random_num = rand() % 1000 + 1;
    
    printf("Here is the number:\n");
    printbitssimple(random_num);
    printf("\nEnter your answer\n");
    fgets(ans, 2, stdin);
    printf("\n");
    printf("you typed: %s \n", ans);
    return 1;
}
