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
    int contador=0;
    for(int i=-1;i<=1;i++){
        for(int j=-1; j<=1;j++){
            if(i==0&&j==0) continue; // ALEX: esto es legal? creo que se puede mejorar con un booleano
            int fila = (x+i+rows) % rows;
            int col = (y+j+cols) % cols;
            contador+=grid[fila][col];
        }
    }
    return contador;
}

void next_generation(int rows, int cols, int current[rows][cols], int next[rows][cols]){
    for(int i=0;i<rows;i++){
        for(int j=0;i<cols;j++){
            int quants=count_neighbors(rows, cols, current, i, j); 
            if(current[i][j]==1){
                next[i][j] = (quants==2||quants==3) ? 1 :0;//sup
            } else{
                next[i][j] = (quants==3)?1:0;//naixement
            }
        }
    }
}

int grids_are_equal(int rows, int cols, int grid1[rows][cols], int grid2[rows][cols]){
    for(int i=0;i<rows;i++){
        for(int j=0; j<cols;j++){
            if(grid1[i][j] != grid2[i][j]){
                return 0;//no son iguals
            }
        }
    }
}
