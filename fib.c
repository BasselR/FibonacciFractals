#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibNumbers[] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352};

char* concatenate(char* s1, char* s2){
    char* s3 = malloc(strlen(s1) + strlen(s2) + 1);
    if(s3 == NULL){
        return NULL;      
    }
    strcpy(s3, s1);
    strcat(s3, s2);
    return s3;
}

char* computeFibWord(int n, char* s1, char* s2){

    if(n <= 1){
        return s2;
    }

    char* s3 = concatenate(s2, s1);
    if(s3 == NULL){
        return NULL;
    }
    return computeFibWord(n - 1, s2, s3);

}

typedef enum {
    up,
    right,
    down,
    left
} direction;

void draw(int x, int y, direction dir, int step, int w, RGB* im, RGB c)
{
#define I(i, j) im[(i)*w + j]
    int j;
    if (dir == up)
        for (j = 0; j < step; j++)
            I(x + j, y) = c;
    if (dir == down)
        for (j = 0; j < step; j++)
            I(x - j, y) = c;
    if (dir == right)
        for (j = 0; j < step; j++)
            I(x, y + j) = c;
    if (dir == left)
        for (j = 0; j < step; j++)
            I(x, y - j) = c;
#undef I
}

int fib(int n, int x, int y, int step, RGB bc, RGB fc, int w, int h, RGB* image){

    char* f2 = "0";
    char* f3 = "01";

    char* result = computeFibWord(n - 2, f2, f3);
    if(result == NULL){
        return 0;
    }

    direction dir = 0;
    RGB black = { 0, 0, 0 };
    int length = fibNumbers[n];

    int i;

    for (i = 0; i < w * h; i++){
        image[i] = bc;
    }

    for(i = 0; i < length; i++){
        switch(dir){
            case 0:
                if(x + step > h) return 0;
            case 1:
                if(y + step > w) return 0;
            case 2:
                if(x - step < 0) return 0;
            case 3:
                if(y - step < 0) return 0;
        }
        draw(x, y, dir, step, w, image, black);
        switch(dir){
            case 0:
                x += step;
                break;
            case 1:
                y += step;
                break;
            case 2:
                x -= step;
                break;
            case 3:
                y -= step;
                break;
        }
        if((*(result + i)) == '0'){
            if((i + 1) % 2 == 0){
                if(dir == up){
                    dir = left;
                }
                else{
                    dir -= 1; 
                }
            }
            else{
                if(dir == left){
                    dir = up;
                }
                else{
                    dir += 1; 
                }                
            }
        }
    }
    return length;
}