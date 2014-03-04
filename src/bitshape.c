#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CHARSIZE 10
#define MAXNUMBER 100

void printbitssimple(int);
void createbitshape(int, char[]);
int guess_num_from_binary(void);
int guess_binary_from_num(void);


int main(void) 
{

int play_on = 1;
int ans;
char response[CHARSIZE];

puts("\t The BitShape Game "); 
    while(play_on)
    {
        puts("Enter a choice, which game you would like to play:");
        puts("1 - Guess a number from it's bit shape ...");
        puts("2 - Given an integer type in it's bit shape ...");
        puts("3 - Exit the game");
        fgets(response, CHARSIZE, stdin);
        printf("Printing s: %s\n", response);
        switch(atoi(response)){
            
            case 1:
                printf("Guess a number from it's bit shape ...\n");
                /* if correct guess_num_from_binary returns 0 */
                ans = guess_num_from_binary();
                if (! ans) {
                    puts("\nThat's Correct!\n"); 
                    } else {
                    printf("\nThat's Wrong! The correct answer is %d\n", ans);
                    }
                break;
            case 2:
                puts("Play version 2\n");
                guess_binary_from_num();
                break;
            case 3:
                puts("Good bye");
                play_on = 0;
                break;
            default:
                puts("Did not understand your input...");
                break;
        
        }
    }
    return 0;   
}

/*show the user a bit shape and compare the input*/
int guess_num_from_binary(void){
    int random_num ;
    char ans[8];
    srand(time(NULL));
    random_num = rand() % MAXNUMBER + 1;
    puts("Here is the number:");
    printbitssimple(random_num);
    puts("\nEnter your answer");
    fgets(ans, 6, stdin);
    putchar('\n');
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
    random_num = rand() % MAXNUMBER + 1;
    printf("Here is the number: %d\n", random_num);
    puts("\nEnter your answer");
    fgets(ans, 20, stdin);
    putchar('\n');
    createbitshape(random_num, bitshp);
    if (! strncmp(bitshp, ans, 8)){
        puts("That's correct !");
        return 1;
    } else {
        printf("you typed: %s \n", ans);
        printf("the correct answer is : %s \n", bitshp);
        putchar('\n');
    }   
    return 0;
}

/* Print n as a binary number */
void printbitssimple(int n)
{
    
    for (unsigned bit = 1<<(sizeof(n) * 2 - 1);  bit != 0; bit >>= 1)
    {
        putchar((n & bit) ? '1' : '0');
    }
}
/*similar to printbitssimple, but instead of Printing
 * write the bitshape into a string */
void createbitshape(int n, char bitshp[])
{
    int c = 0;
    for (unsigned bit = 1<<(sizeof(n) * 2 - 1); bit != 0; bit >>= 1, c++)
    {
        bitshp[c] = ((n & bit) ? '1' : '0');
    }
    bitshp[c] = '\0';
}

