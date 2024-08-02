#include "animal.h"

void cat_speak(animal_t *animal, FILE *file) {
    fprintf(file, "meow meow\n");
}

void dog_speak(animal_t *animal, FILE *file) {
    fprintf(file, "bow bow\n");
}

void pig_speak(animal_t *animal, FILE *file) {
    fprintf(file, "my price is %d\n", animal->price.priceInt);
}

void create_animal(animal_t *animal) {
    if (strcmp(animal->type, "cat") == 0) {
        strcpy(animal->price.priceStr, "not for sale");
        animal->action = cat_speak;
    } else if (strcmp(animal->type, "dog") == 0) {
        strcpy(animal->price.priceStr, "i am your friend");
        animal->action = dog_speak;
    } else if (strcmp(animal->type, "pig") == 0) {
        animal->price.priceInt = 500000;
        animal->action = pig_speak;
    }
}

void write_to_file(animal_t *animals, int count) {
    FILE *file = fopen("./out/output.txt", "w");
    if (file == NULL) {
        printf("ERROR\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "----------------------------\n");
        fprintf(file, "Animal type: %s\n", animals->type);
        animals[i].action(&animals[i], file);
    }

    fclose(file);
}
