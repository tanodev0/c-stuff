#include "main.hpp"

void Matrix::printMatrix()
{
    printf("------------\n\n");
    printf("| x1 y1 z1 |\n");
    printf("| x2 y2 z2 |\n");
    printf("| x3 y3 z3 |\n\n");
    printf("------------\n\n");
    printf("Insert the numbers of the matrix in order: x1 y1 z1 -> x2 y2 z2 -> x3 y3 z3\n");
}

void Matrix::printMatrix(double mat[])
{
    printf("------------\n\n");
    printf("| %lf %lf %lf |\n", mat[0], mat[1], mat[2]);
    printf("| %lf %lf %lf |\n", mat[3], mat[4], mat[5]);
    printf("| %lf %lf %lf |\n\n", mat[6], mat[7], mat[8]);
    printf("------------\n\n");
    
}

void Matrix::solveDeterminant(double mat[])
{
    double part1 = (mat[0] * mat[4] * mat[8]) + (mat[3] * mat[7] * mat[2]) + (mat[6] * mat[1] * mat[5]);
    double part2 = (mat[2] * mat[4] * mat[6]) + (mat[5] * mat[7] * mat[0]) + (mat[8] * mat[1] * mat[3]);
    double res = part1 - part2;
    printf("Determinant Solution: %lf", res);
}

int main()
{
    Matrix m;
    m.printMatrix();

    double mat[9];

    for (int i = 0; i < 9; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%lf", &mat[i]);
    }

    m.printMatrix(mat);
    m.solveDeterminant(mat);

    return 0;
}

