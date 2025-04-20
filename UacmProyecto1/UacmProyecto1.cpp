#include <stdio.h>
#include <locale.h>

void menuPrincipal();
void menuPalanca();
void menuTorno();
void menuPolea();
void menuPlanoInclinado();

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");
    menuPrincipal();
    printf("\nProyecto de Miguel Ángel Suárez Zavala. Prohibida su venta o distribución sin autorización ©\n");
    return 0;
}

void menuPrincipal() {
    int opcion;
    do {
        printf("\n=== Menú Principal ===\n");
        printf("1. Palanca\n");
        printf("2. Torno\n");
        printf("3. Polea\n");
        printf("4. Plano Inclinado\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf_s("%d", &opcion);

        switch (opcion) {
        case 1: menuPalanca(); break;
        case 2: menuTorno(); break;
        case 3: menuPolea(); break;
        case 4: menuPlanoInclinado(); break;
        case 5: printf("Saliendo...\n"); break;
        default: printf("Opción no válida.\n");
        }
    } while (opcion != 5);
}

void menuPalanca() {
    int opcion;
    do {
        printf("\n--- Palanca ---\n");
        printf("1. Calcular ventaja mecánica\n");
        printf("2. Calcular longitudes de brazos\n");
        printf("3. Regresar\n");
        printf("Seleccione una opción: ");
        scanf_s("%d", &opcion);

        switch (opcion) {
        case 1: {
            float fuerzaResistente, fuerzaEsfuerzo, ventaja;
            printf("\nIngrese la fuerza resistente (Fr): ");
            scanf_s("%f", &fuerzaResistente);
            printf("Ingrese la fuerza de esfuerzo (Fe): ");
            scanf_s("%f", &fuerzaEsfuerzo);

            if (fuerzaEsfuerzo > 0 && fuerzaResistente > 0) {
                ventaja = fuerzaResistente / fuerzaEsfuerzo;
                printf("Ventaja mecánica: %.2f (sin unidad)", ventaja);
            }
            else {
                printf("La fuerza de esfuerzo no puede ser cero.\n");
            }
            break;
        }
        case 2: {
            float fuerzaResistente, fuerzaEsfuerzo;
            printf("\nIngrese la fuerza resistente (Fr): ");
            scanf_s("%f", &fuerzaResistente);
            printf("Ingrese la fuerza de esfuerzo (Fe): ");
            scanf_s("%f", &fuerzaEsfuerzo);

            if (fuerzaResistente > 0 && fuerzaEsfuerzo > 0) {
                float proporcion = fuerzaEsfuerzo / fuerzaResistente;
                printf("Relación de longitudes (Lr/Le): %.2f\n", proporcion);
            }
            else {
                printf("Las fuerzas no pueden ser cero.\n");
            }
            break;
        }
        case 3: break;
        default: printf("Opción no válida.\n");
        }
    } while (opcion != 3);
}

void menuTorno() {
    int opcion;
    do {
        printf("\n--- Torno ---\n");
        printf("1. Calcular ventaja mecánica\n");
        printf("2. Calcular fuerza aplicada o resistencia\n");
        printf("3. Regresar\n");
        printf("Seleccione una opción: ");
        scanf_s("%d", &opcion);

        switch (opcion) {
        case 1: {
            float radioMayor, radioMenor, ventaja;
            printf("\nIngrese el radio del cilindro (R): ");
            scanf_s("%f", &radioMayor);
            printf("Ingrese el radio del eje (r): ");
            scanf_s("%f", &radioMenor);

            if (radioMenor > 0 && radioMayor > 0) {
                ventaja = radioMayor / radioMenor;
                printf("Ventaja mecánica: %.2f\n", ventaja);
            }
            else {
                printf("El radio del eje no puede ser cero.\n");
            }
            break;
        }
        case 2: {
            int tipo;
            float fuerza, otra, resultado;
            printf("\n¿Qué desea calcular?\n");
            printf("1. Fuerza de resistencia (Fr)\n");
            printf("2. Fuerza de esfuerzo (Fe)\n");
            printf("Seleccione una opción: ");
            scanf_s("%d", &tipo);

            if (tipo == 1) {
                printf("Ingrese la fuerza de esfuerzo (Fe): ");
                scanf_s("%f", &fuerza);
                printf("Ingrese la ventaja mecánica (VM): ");
                scanf_s("%f", &otra);
                resultado = fuerza * otra;
                printf("Fuerza de resistencia (Fr): %.2f N", resultado);
            }
            else if (tipo == 2) {
                printf("Ingrese la fuerza de resistencia (Fr): ");
                scanf_s("%f", &fuerza);
                printf("Ingrese la ventaja mecánica (VM): ");
                scanf_s("%f", &otra);
                if (otra != 0) {
                    resultado = fuerza / otra;
                    printf("Fuerza de esfuerzo (Fe): %.2f N", resultado);
                }
                else {
                    printf("La ventaja mecánica no puede ser cero.\n");
                }
            }
            else {
                printf("Opción no válida.\n");
            }
            break;
        }
        case 3: break;
        default: printf("Opción no válida.\n");
        }
    } while (opcion != 3);
}

void menuPolea() {
    int opcion;
    do {
        printf("\n--- Polea ---\n");
        printf("1. Calcular fuerza necesaria\n");
        printf("2. Calcular ventaja mecánica\n");
        printf("3. Regresar\n");
        printf("Seleccione una opción: ");
        scanf_s("%d", &opcion);

        switch (opcion) {
        case 1: {
            float fuerzaResistencia;
            int cuerdas;
            printf("\nIngrese la fuerza de resistencia (Fr): ");
            scanf_s("%f", &fuerzaResistencia);
            printf("Ingrese el número de cuerdas que soportan la carga: ");
            scanf_s("%d", &cuerdas);

            if (cuerdas > 0) {
                float fuerzaNecesaria = fuerzaResistencia / cuerdas;
                printf("Fuerza necesaria: %.2f N", fuerzaNecesaria);
            }
            else {
                printf("El número de cuerdas debe ser mayor que cero.\n");
            }
            break;
        }
        case 2: {
            int cuerdas;
            printf("\nIngrese el número de cuerdas que soportan la carga: ");
            scanf_s("%d", &cuerdas);

            if (cuerdas > 0) {
                printf("Ventaja mecánica: %d (sin unidad)", cuerdas);
            }
            else {
                printf("El número de cuerdas debe ser mayor que cero.\n");
            }
            break;
        }
        case 3: break;
        default: printf("Opción no válida.\n");
        }
    } while (opcion != 3);
}

void menuPlanoInclinado() {
    int opcion;
    do {
        printf("\n--- Plano Inclinado ---\n");
        printf("1. Calcular fuerza necesaria\n");
        printf("2. Calcular ventaja mecánica\n");
        printf("3. Regresar\n");
        printf("Seleccione una opción: ");
        scanf_s("%d", &opcion);

        switch (opcion) {
        case 1: {
            float peso, angulo, fuerza;
            printf("\nIngrese el peso del objeto (N): ");
            scanf_s("%f", &peso);
            printf("Ingrese el ángulo de inclinación (grados): ");
            scanf_s("%f", &angulo);

            float rad = angulo * 3.14159265 / 180.0;
            float seno;

            if (angulo == 30) seno = 0.5;
            else if (angulo == 45) seno = 0.7071;
            else if (angulo == 60) seno = 0.866;
            else seno = rad;

            fuerza = peso * seno;
            printf("Fuerza necesaria para subir el plano: %.2f N\n", fuerza);
            break;
        }
        case 2: {
            float longitud, altura, ventaja;
            printf("\nIngrese la longitud del plano inclinado (L): ");
            scanf_s("%f", &longitud);
            printf("Ingrese la altura del plano (h): ");
            scanf_s("%f", &altura);

            if (altura > 0 && longitud > 0) {
                ventaja = longitud / altura;
                printf("Ventaja mecánica: %.2f\n", ventaja);
            }
            else {
                printf("La altura no puede ser cero.\n");
            }
            break;
        }
        case 3: break;
        default: printf("Opción no válida.\n");
        }
    } while (opcion != 3);
}
