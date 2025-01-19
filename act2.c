#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void initialize_grid(int rows, int cols, int grid[rows][cols]);
void display_grid(int rows, int cols, int grid[rows][cols]);
int count_neighbors(int rows, int cols, int grid[rows][cols], int x, int y);
void next_generation(int rows, int cols, int current[rows][cols], int next[rows][cols]);



void initialize_grid(int rows, int cols, int grid[rows][cols]) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void display_grid(int rows, int cols, int grid[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int rows, int cols, int grid[rows][cols], int x, int y){
    int contador=0;
    for(int i=-1;i<=1;i++){
        for(int j=-1; j<=1;j++){
            if(i==0&&j==0) continue;
            int fila = (x+i+rows) % rows;
            int col = (y+j+cols) % cols;
            contador+=grid[fila][col];
        }
    }
    return contador;
}

void next_generation(int rows, int cols, int current[rows][cols], int next[rows][cols]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int quants=count_neighbors(rows, cols, current, i, j);
            if(current[i][j]==1){
                next[i][j] = (quants==2||quants==3) ? 1 :0;//sup
            } else{
                next[i][j] = (quants==3)?1:0;//naixement
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 1;
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    if (rows <= 0 || cols <= 0) {
        printf("Rows and cols must be more than 0.\n");
        return 1;
    }

    int current[rows][cols];
    int next[rows][cols];

    initialize_grid(rows, cols, current);
    printf("First generation:\n");
    display_grid(rows, cols, current);

    // Calcular siguiente generación
    next_generation(rows, cols, current, next);
    printf("Next generation:\n");
    display_grid(rows, cols, next);

    return 0;
}
