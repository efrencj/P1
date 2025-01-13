#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize_grid(int rows, int cols, int grid[rows][cols]){
    srand(time(NULL)); //for generate a random number
    for(int i=0; i<rows; i++){
        for(int j=0;j<cols; j++){
            grid[i][j] = rand() % 2; //if it's 0 is dead and if its 1 is alive
        }
    }
}

void display_grid(int rowss, int cols, int grid[rows][cols]){
    for(int i=0; i<rows;i++){
        for(int j=0; j<cols; j++){
            printf("%c ", grid[i][j] ? '#':'.');
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int rows, int cols, int grid[rows][cols], int x, int y){
    
}