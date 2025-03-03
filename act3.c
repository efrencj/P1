#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // usleep()

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
    if (argc != 4) {
        printf("Use: %s <NumRows> <NumCols> <NumGenerations>\n", argv[0]);
        return 1;
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    int generations = atoi(argv[3]);

    if (rows <= 0 || cols <= 0 || generations <= 0) {
        printf("Rows and cols must be more than 0.\n");
        return 1;
    }

    int current[rows][cols];
    int next[rows][cols];

    initialize_grid(rows, cols, current);

    for (int g = 0; g < generations; g++) {
        system("clear");
        printf("Generation %d:\n", g+1);
        display_grid(rows, cols, current);
        next_generation(rows, cols, current, next);

        // Copy of the actual generation for the next cycle
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                current[i][j] = next[i][j];
            }
        }

        usleep(500000);  // 0,5 segs
    }

    return 0;
}
