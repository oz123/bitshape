#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CHARSIZE 10

void mainloop(void);
void random_number(void);
int  compare_user_input(char*);


/* Print n as a binary number */
void printbitssimple(int n) 
{
    unsigned int i;
    i = 1<<(sizeof(n) * 8 - 1);
    printf("%i\n", i);
    printf("%i\n", n);
    while (i > 0) 
    {
        if (n & i)  /* check if any of the bits of n is not 0 .*/
            printf("1");
        else
            printf("0");
        i >>= 1;
    }
}

/*
int main(int argc, char *argv[]) 
{
    int i,t;
    int response;
    int *answer;
    int *op1;
    int *op2;
    char *result;
    int x;

    srand(time(NULL));

    printf("\n\tThe BitShape Game");
    printf("\n1\tGuess the bit shape of integer");
    printf("\n2\tGuess an integer from a bit shape");
    printf("Select an option: ");
    scanf("%d", &response);

    if ( response )
    for (i = 0; i < 2; ++i) 
    {
        printbitssimple(i);
        printf("\n");
    }
        
    return 0;
}*/

int main(void) 
{

int random_num = 0;
int guessed_num = 0;
int counter = 0; 
int play_on = 1;
srand(time(NULL));
random_num = rand() % 1000 + 1;
char response[CHARSIZE];

printf("\n\t The BitShape Game \n"); 

    while(play_on)
    {
        fgets(response, CHARSIZE, stdin);
        printf("Printing s: %s\n", response);

        switch(atoi(response)){
            
            case 1:
                printf("Play version 1\n");
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
