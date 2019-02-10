// Name: Becky Chao
// Class: CS362
// Assignment: Random Quiz

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function

    // note that possibilities for ascii values are 0-125 (add one to make sure 125 is a possibility)
    // generate a random number, divide by the max possible value and the char generated is value of the leftover value
    int max = 94;
    int c = rand() % max + 32;
    return (char)c;
}

char *inputString()
{
    // TODO: rewrite this function
    static char s[6];
    int max = 16;
    int max2 = 2;
    int c1 = rand() % max + 101;
    int c2 = rand() % max + 101;
    int c3 = rand() % max + 101;
    int c4 = rand() % max + 101;
    int c5 = rand() % max + 101;
    int c6 = rand() % max2;
    s[0] = (char)c1;
    s[1] = (char)c2;
    s[2] = (char)c3;
    s[3] = (char)c4;
    s[4] = (char)c5;
    s[5] = (char)c6;
    return s;
}

void testme()
{
    int tcCount = 0;
    char *s;
    char c;
    int state = 0;
    while (1)
    {
        tcCount++;
        c = inputChar();
        s = inputString();
        printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

        if (c == '[' && state == 0) state = 1;
        if (c == '(' && state == 1) state = 2;
        if (c == '{' && state == 2) state = 3;
        if (c == ' '&& state == 3) state = 4;
        if (c == 'a' && state == 4) state = 5;
        if (c == 'x' && state == 5) state = 6;
        if (c == '}' && state == 6) state = 7;
        if (c == ')' && state == 7) state = 8;
        if (c == ']' && state == 8) state = 9;
        if (s[0] == 'r' && s[1] == 'e'
            && s[2] == 's' && s[3] == 'e'
            && s[4] == 't' && s[5] == '\0'
            && state == 9)
        {
            printf("error ");
            exit(200);
        }
    }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
