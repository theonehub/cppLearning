#include <iostream>

/*

0X0102

    _______________________________
   |      01       |       02      | -- big
    -------------------------------
0x4                 0X5

    _______________________________
   |       02      |       01      | -- little
    -------------------------------
0x4                 0X5
*/


int main(void) {
    union
    {
        short s;
        char c[sizeof(short)];
    }un;
    
    un.s = 0x0102;

    if (sizeof(short) == 2)
    {
        printf("un.c[0] : %p\n", &un.c[0]);
        printf("un.c[1] : %p\n", &un.c[1]);

        if (un.c[0] == 1 && un.c[1] == 2)
        {
            printf("big-endian\n");
        }
        else if (un.c[1] == 1 && un.c[0] == 2)
        {
            printf("little-endian\n");
        }
        else
        {
            printf("Unknown!!!\n");
        }
    }
}