#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int W; 
    int H; 
    scanf("%d%d", &W, &H);
    int N; 
    scanf("%d", &N);
    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);
    int X = X0;
    int Y = Y0;
    char *direction;
    
    int right= W + 1;
    int down= H + 1;
    int up= 0;
    int left= 0;

    while (1) {
        char bombDir[4]; 
        scanf("%s", bombDir);
        direction = bombDir;
        while(*direction != '\0'){ 
            if(*direction == 'D'){
                up = Y + 1;
                Y += (down - Y) / 2;
            }
            else if(*direction == 'U')
            {
                down = Y;
                Y -= (Y - up) / 2 + 1;
            }
            else if(*direction == 'R')
            {
                left = X + 1;
                X +=(right - X) / 2;    
            }
            else if(*direction == 'L')
            {
                right = X;
                X -= (X - left) / 2 + 1;
            }
            direction++;   
        }
        printf("%d %d\n", X, Y);
    }

    return 0;
}