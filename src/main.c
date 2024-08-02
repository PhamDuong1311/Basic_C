#include "animal.h"

int main() {
    srand(time(NULL));
    animal_t animals[MAX_ANIMAL];

    for (int i = 0; i < MAX_ANIMAL; i++) {
        int value = rand() % 3;
        if (value == 0) strcpy(animals[i].type, "cat");
        else if (value == 1) strcpy(animals[i].type, "dog");
        else if (value == 2) strcpy(animals[i].type, "pig");

        create_animal(&animals[i]);
    }

    write_to_file(animals, MAX_ANIMAL);

    return 0;
}
