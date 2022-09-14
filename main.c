/*
** EPITECH PROJECT, 2022
** IMC-Calculator
** File description:
** Main
*/

#include "include/calculator.h"

int check_space(char *tmp)
{
    int a = 0;
    int i = 0;

    for (; tmp[i + 1] != '\0'; i++)
        if (tmp[i] == ' ' || tmp[i] == '\t')
            a++;
    if (a == i)
        return (1);
    else
        return (0);
}

void result(struct_t *use)
{
    use->height /= 100;
    use->result = use->weight / (use->height * use->height);
    printf("Your BMI is %0.2f\nSo you are ", use->result);
    if (use->result <= 18.5)
        printf("Underweight\n");
    else if (use->result <= 24.9)
        printf("in normal weight\n");
    else if (use->result <= 29.9)
        printf("in Overweight\n");
    else if (use->result >= 30 && use->result <= 40)
        printf("in Obesity\n");
    else if (use->result > 40)
        printf("in Severe Obesity\n");
}

int height(struct_t *use)
{
    size_t bufsize = 0;
    char *tmp = NULL;

    printf("Enter your height (in cm): ");
    if (getline(&tmp, &bufsize, stdin) == -1) {
        free(tmp);
        return 0;
    }
    if (tmp[0] == '\n' || check_space(tmp) == 1)
        height(use);
    for( int i = 0; i < strlen(tmp) - 1; i++ )
        if (!isdigit(tmp[i])) {
            printf("We don't need a letter to write an height ??\n");
            height(use);
        }
    use->height = atoi(tmp);
    free(tmp);
    result(use);
    return 0;
}

int weight(struct_t *use)
{
    size_t bufsize = 0;
    char *tmp = NULL;

    printf("Enter your weight (in kg): ");
    if (getline(&tmp, &bufsize, stdin) == -1) {
        free(tmp);
        return 0;
    }
    if (tmp[0] == '\n' || check_space(tmp) == 1)
        weight(use);
    for( int i = 0; i < strlen(tmp) - 1; i++ )
        if (!isdigit(tmp[i])) {
            printf("We don't need a letter to write a weight ??\n");
            weight(use);
        }
    use->weight = atoi(tmp);
    free(tmp);
    height(use);
    return 0;
}

int main(int ac, char **av)
{
    struct_t *use = malloc(sizeof(struct_t));

    if (ac != 1) {
        write(2, "No need arguments\n", 19);
        free(use);
        return 84;
    } else
        if (weight(use) == 84) {
            free(use);
            return 84;
        }
    free(use);
    return 0;
}