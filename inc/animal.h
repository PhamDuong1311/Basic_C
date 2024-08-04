#ifndef ANIMAL_H
#define ANIMAL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ANIMAL 10

typedef struct {
    char priceStr[50];
    int priceInt;
} price_t;

typedef struct animal_t {
    char type[10];
    price_t price;
    void (*action)(struct animal_t *, FILE *);
} animal_t;

void cat_speak(animal_t *animal, FILE *file);
void dog_speak(animal_t *animal, FILE *file);
void pig_speak(animal_t *animal, FILE *file);
void create_animal(animal_t *animal);
void write_to_file(animal_t *animals, int count);

#endif // ANIMAL_H
