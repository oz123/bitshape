#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CHARSIZE 10

void mainloop(void);
void random_number(void);
void printbitssimple(int);
void createbitshape(int, char[]);
int  compare_user_input(char*);
int guess_num_from_binary(void);
int guess_binary_from_num(void);


int main(void) 
{

int play_on = 1;
int ans;
char response[CHARSIZE];


printf("\n\t The BitShape Game \n"); 
    while(play_on)
    {
        printf("Enter a choice, which game you would like to play:\n");
        printf("1 - Guess a number from it's bit shape ...\n");
        printf("2 - Given an integer type in it's bit shape ...\n");
        printf("3 - Exit the game\n");
        fgets(response, CHARSIZE, stdin);
        printf("Printing s: %s\n", response);
        switch(atoi(response)){
            
            case 1:
                printf("Guess a number from it's bit shape ...\n");
                /* if correct guess_num_from_binary returns 0 */
                ans = guess_num_from_binary();
                if (! ans) {
                    printf("\nThat's Correct!\n"); 
                    } else {
                    printf("\nThat's Wrong! The correct answer is %d\n", ans);
                    }
                break;
            case 2:
                printf("Play version 2\n");
                guess_binary_from_num();
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
    /* printf("The sizeof of n is %ld\n", sizeof(n));*/
    i = 1<<(sizeof(n) * 2 - 1);
    while (i > 0) 
    {
        if (n & i)  /* check if any of the bits of n is not 0 .*/
            printf("1");
        else
            printf("0");
        i >>= 1;
    }
}


/*similar to printbitssimple, but instead of Printing
 * write the bitshape into a string */
void createbitshape(int n, char bitshp[]){
    unsigned int i;
    /* printf("The sizeof of n is %ld\n", sizeof(n));*/
    int c = 0;
    i = 1<<(sizeof(n) * 2 - 1);
    
    while (i > 0) 
    {
        if (n & i)  /* check if any of the bits of n is not 0 .*/
        {
            //printf("1");
            bitshp[c] = '1';
        }
        else
        {
            //printf("0");
            bitshp[c] = '0';
        }
        i >>= 1;
    c=c+1;
    }
    bitshp[c] = '\0';
}

/*show the user a bit shape and compare the input*/
int guess_num_from_binary(void){
    int random_num ;
    char ans[8];
    srand(time(NULL));
    random_num = rand() % 100 + 1;
    printf("Here is the number:\n");
    printbitssimple(random_num);
    printf("\nEnter your answer\n");
    fgets(ans, 6, stdin);
    printf("\n");
    printf("you typed: %s \n", ans);
    if ( atoi(ans) == random_num ) {
        return 0;
    } else {
        return random_num;
    }
}


/*show the user an integer and compare the bit input */
int guess_binary_from_num(void){
    int random_num ;
    char ans[20];
    char bitshp[8]; 
    srand(time(NULL));
    random_num = rand() % 100 + 1;
    printf("Here is the number: %d\n", random_num);
    printf("\nEnter your answer\n");
    fgets(ans, 20, stdin);
    printf("\n");
    createbitshape(random_num, bitshp);
    if (! strncmp(bitshp, ans, 8)){
        printf("That's correct ! \n");
        return 1;
    } else {
        printf("you typed: %s \n", ans);
        printf("the correct answer is : %s \n", bitshp);
        printf("\n");
    }   
    return 0;
}
