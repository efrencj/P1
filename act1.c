#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize_grid(int rows, int cols, int grid[rows][cols]);
void display_grid(int rows, int cols, int grid[rows][cols]);



void initialize_grid(int rows, int cols, int grid[rows][cols]){
    srand(time(NULL)); //for generate a random number
    for(int i=0; i<rows; i++){
        for(int j=0;j<cols; j++){
            grid[i][j] = rand() % 2; //if it's 0 is dead and if its 1 is alive
        }
    }
}

void display_grid(int rows, int cols, int grid[rows][cols]){
    for(int i=0; i<rows;i++){
        for(int j=0; j<cols; j++){
            printf("%c ", grid[i][j] ? '#':'.');
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    if(argc!=3){
        return 1;
    }
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    if (rows <= 0 || cols <= 0) {
        printf("Rows and cols must be more than 0.\n");
        return 1;
    }
    int grid[rows][cols];
    initialize_grid(rows, cols, grid);
    display_grid(rows, cols, grid);
}

