#include <stdio.h> 

int main() {
    int choice;
    // Defining matrices with a maximum size of 10x10 to handle dynamic user inputs
    int mat1[10][10], mat2[10][10], result[10][10];
    int r1, c1, r2, c2, i, j, k; 

    while (1) {
        printf("\n===== MATRIX OPERATIONS MENU =====\n"); //4 choices
        printf("1. Addition of two matrices\n");
        printf("2. Multiplication of two matrices\n");
        printf("3. Transpose of a matrix\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice); 

        switch (choice) {
            case 1:
                // --- MATRIX ADDITION ---
                printf("\nEnter number of rows and columns: ");
                scanf("%d %d", &r1, &c1);
                
                printf("Enter elements of first matrix row-wise:\n");
                for(i = 0; i < r1; i++) {
                    for(j = 0; j < c1; j++) {
                        scanf("%d", &mat1[i][j]);
                    }
                }

                printf("Enter elements of second matrix row-wise:\n");
                for(i = 0; i < r1; i++) {
                    for(j = 0; j < c1; j++) {
                        scanf("%d", &mat2[i][j]);
                    }
                }

                printf("\nThe resultant matrix (Addition) is:\n");
                for(i = 0; i < r1; i++) {
                    for(j = 0; j < c1; j++) {
                        result[i][j] = mat1[i][j] + mat2[i][j];
                        printf("%4d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                // --- MATRIX MULTIPLICATION ---
                printf("\nEnter rows and cols for first matrix: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and cols for second matrix: ");
                scanf("%d %d", &r2, &c2);

                // Multiplication condition: cols of 1st must equal rows of 2nd
                if(c1 != r2) {
                    printf("Error! Columns of first matrix must equal rows of second matrix.\n");
                    break;
                }

                printf("Enter elements of first matrix row-wise:\n");
                for(i = 0; i < r1; i++) {
                    for(j = 0; j < c1; j++) {
                        scanf("%d", &mat1[i][j]);
                    }
                }

                printf("Enter elements of second matrix row-wise:\n");
                for(i = 0; i < r2; i++) {
                    for(j = 0; j < c2; j++) {
                        scanf("%d", &mat2[i][j]);
                    }
                }

                // Initialize result matrix to 0
                for(i = 0; i < r1; i++) {
                    for(j = 0; j < c2; j++) {
                        result[i][j] = 0;
                    }
                }

                // Multiplication logic
                for(i = 0; i < r1; i++) {
                    for(j = 0; j < c2; j++) {
                        for(k = 0; k < c1; k++) {
                            result[i][j] += mat1[i][k] * mat2[k][j];
                        }
                    }
                }

                printf("\nThe resultant matrix (Multiplication) is:\n");
                for(i = 0; i < r1; i++) {
                    for(j = 0; j < c2; j++) {
                        printf("%4d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                // --- MATRIX TRANSPOSE ---
                printf("\nEnter rows and cols of matrix: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter elements of matrix row-wise:\n");
                for(i = 0; i < r1; i++) {
                    for(j = 0; j < c1; j++) {
                        scanf("%d", &mat1[i][j]);
                    }
                }

                // Transpose logic (swapping i and j indices)
                for(i = 0; i < c1; i++) {
                    for(j = 0; j < r1; j++) {
                        result[i][j] = mat1[j][i];
                    }
                }

                printf("\nTranspose of the matrix is:\n");
                for(i = 0; i < c1; i++) {
                    for(j = 0; j < r1; j++) {
                        printf("%4d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}
