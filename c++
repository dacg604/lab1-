#include <stdio.h>



// Estructura para almacenar la información del usuario
typedef struct {
    float height; // Altura en cm
    float weight; // Peso en kg
} User;

// Prototipos de las funciones
void classifyWeight(User users[], int count);
void printWeightDistribution(int underweight, int normal_weight, int overweight, int obese, int total);

int main() {
    int numUsers;

    // Preguntar cuántos usuarios se van a ingresar
    printf("Ingrese el número de usuarios: ");
    scanf("%d", &numUsers);

    // Crear un arreglo de usuarios
    User users[numUsers];

    // Leer la información de cada usuario
    for (int i = 0; i < numUsers; i++) {
        printf("Ingrese la altura (en cm) para el usuario %d: ", i + 1);
        scanf("%f", &users[i].height);
        printf("Ingrese el peso (en kg) para el usuario %d: ", i + 1);
        scanf("%f", &users[i].weight);
    }

    // Clasificar el peso de cada usuario y calcular las estadísticas
    classifyWeight(users, numUsers);

    return 0;
}

// Función para clasificar el peso y calcular el porcentaje en cada categoría
void classifyWeight(User users[], int count) {
    int underweight = 0, normal_weight = 0, overweight = 0, obese = 0;

    for (int i = 0; i < count; i++) {
        float heightInMeters = users[i].height / 100.0;
        float bmi = users[i].weight / (heightInMeters * heightInMeters);

        if (bmi < 18.5) {
            underweight++;
        } else if (bmi >= 18.5 && bmi < 24.9) {
            normal_weight++;
        } else if (bmi >= 25 && bmi < 29.9) {
            overweight++;
        } else {
            obese++;
        }
    }

    // Imprimir la distribución de peso
    printWeightDistribution(underweight, normal_weight, overweight, obese, count);
}

// Función para imprimir la distribución de peso en porcentaje
void printWeightDistribution(int underweight, int normal_weight, int overweight, int obese, int total) {
    if (total == 0) {
        printf("No hay usuarios para analizar.\n");
        return;
    }

    printf("Porcentaje de usuarios con bajo peso: %.2f%%\n",
           (underweight / (float)total) * 100);
    printf("Porcentaje de usuarios con peso normal: %.2f%%\n",
           (normal_weight / (float)total) * 100);
    printf("Porcentaje de usuarios con sobrepeso: %.2f%%\n",
           (overweight / (float)total) * 100);
    printf("Porcentaje de usuarios con obesidad: %.2f%%\n",
           (obese / (float)total) * 100);
}
