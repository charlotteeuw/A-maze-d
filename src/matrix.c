/*
** EPITECH PROJECT, 2024
** matrix.c
** File description:
** Useful functions for matrices
*/

#include <amazed.h>

matrix_t *create_matrix(size_t nb_cols, size_t nb_lines)
{
    matrix_t *matrix = malloc(sizeof(matrix_t));

    matrix->nb_cols = nb_cols;
    matrix->nb_lines = nb_lines;
    matrix->values = malloc(sizeof(int *) * nb_lines);
    for (size_t x = 0; x < nb_lines; x++) {
        matrix->values[x] = malloc(sizeof(int) * nb_cols);
        for (size_t y = 0; y < nb_cols; y++) {
            matrix->values[x][y] = 0;
        }
    }
    return matrix;
}
