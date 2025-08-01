#include<stdio.h>

struct automobile{
    int year;
    char model[8];
    int engine_power;
    float weight;
};

int main(){
    struct automobile cars[5];
    for (int i = 0; i < 5; i++){
        printf("\nMobil ke-%d\n", i + 1);
        printf("Tahun: ");
        scanf("%d", &cars[i].year);
        printf("Model: ");
        scanf(" %[^\n]", cars[i].model);
        printf("Daya Mesin (HP): ");
        scanf("%d", &cars[i].engine_power);
        printf("Berat (kg): ");
        scanf("%f", &cars[i].weight);
    }

    printf("\n=== Daftar Mobil ===\n");
    for (int i = 0; i < 5; i++) {
        printf("\nMobil %d\n Tahun: %d\n Model: %s\n Daya: %d HP\n Berat: %.2f kg\n",
               i + 1, cars[i].year, cars[i].model, cars[i].engine_power, cars[i].weight);
    }
    return 0;
}

