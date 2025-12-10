#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void print(int grid[9][9]) {
    printf("+--------+----------+----------+\n");
    for (int i = 0; i < 9; i++) {
        if (i != 0 && i % 3 == 0) {
            printf("+--------+----------+----------+\n");
        }
        for (int j = 0; j < 9; j++) {
            if (j != 0 && j % 3 == 0) {
                printf("| ");
            }
            if (grid[i][j] == 0) {
                printf(" . ");
            } else {
                printf(" %d ", grid[i][j]);
            }
        }
        printf("|\n");
    }
    printf("+--------+----------+----------+\n");
}

void read_grid(const char *path, int grid[9][9]){
    FILE *f = fopen(path,"r");
    if (f == NULL) {
        printf("Error: Could not open file %s\n", path);
        exit(1);
    }
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (fscanf(f, "%d,", &grid[i][j]) != 1) {
                printf("Error reading grid format.\n");
                fclose(f);
                exit(1);
            }
        }
    }
    fclose(f);
}

bool check_row(int grid[9][9], int row, int column, int vtest) {
    for (int j = 0; j < 9; j++) {
        if (j != column && grid[row][j] == vtest) return false;
    }
    return true;
}

bool check_column(int grid[9][9], int row, int column, int vtest) {
    for (int i = 0; i < 9; i++) {
        if (i != row && grid[i][column] == vtest) return false;
    }
    return true;
}

bool check_square(int grid[9][9], int row, int column, int vtest) {
    int startRow = 3 * (row / 3);
    int startColumn = 3 * (column / 3);
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startColumn; j < startColumn + 3; j++) {
            if ((i != row || j != column) && grid[i][j] == vtest) return false;
        }
    }
    return true;
}

bool check(int grid[9][9], int row, int col, int val) {
    return check_row(grid, row, col, val) &&
           check_column(grid, row, col, val) &&
           check_square(grid, row, col, val);
}

bool find_empty_location(int grid[9][9], int *row, int *col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (grid[*row][*col] == 0) return true;
        }
    }
    return false;
}

bool solve(int grid[9][9]){
    int row, col;
    
    if (!find_empty_location(grid, &row, &col)) return true;

    for (int num = 1; num <= 9; num++){
        if (check(grid, row, col, num)){
            grid[row][col] = num;

            if (solve(grid)) return true;

            grid[row][col] = 0; 
        }
    }
    return false; 
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename.txt>\n", argv[0]);
        return 1;
    }

    int grid[9][9];
    
    printf("Loading puzzle from '%s'...\n", argv[1]);
    read_grid(argv[1], grid);
    print(grid);

    printf("\nSolving...\n");
    if (solve(grid)) {
        printf("\n Solved Grid:\n");
        print(grid);
    } else {
        printf("\n No solution exists for this puzzle.\n");
    }

    return 0;
}