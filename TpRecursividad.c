#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//////// punto 1

bool palindromo(char s[], int i, int j)
{

    if (i = j)
    {
        return true;
    }
    else
    {
        if (s[i] != s[j])
        {
            return false;
        }
        else
        {
            palindromo(s, i + 1, j - 1);
        }
    }
}

//////// punto 2

int producto(int m, int n)
{
    if (n <= 1)
    {
        return m;
    }
    else
    {
        return (m + producto(m, n - 1));
    }
}

//////// punto 3

int fibo(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
};

//////// punto 4

float division(int m, int n, float res)
{
    if (m <= 0)
    {
        return res;
    }
    else
    {
        res += 1;
        division(m - n, n, res);
    }
}

//////// punto 5

void agregarSeparadorMilesAux(char *num, char *result, int i, int j, int k)
{
    if (i < 0)
    {
        result[j] = '\0';    // Terminar la cadena con un carácter nulo
        strcpy(num, result); // Copiar el resultado en el número original
        return;
    }
    if (k == 3)
    {
        result[j] = '.';
        j--;
        k = 0;
    }
    result[j] = num[i];
    agregarSeparadorMilesAux(num, result, i - 1, j - 1, k + 1);
}

void agregarSeparadorMiles(char *num)
{
    char result[strlen(num) * 2 + 1];  // Crear un array para el resultado
    memset(result, 0, sizeof(result)); // Inicializar el array a 0
    agregarSeparadorMilesAux(num, result, strlen(num) - 1, strlen(num), 0);
}

//////// punto 6

void mafiaChina(int level)
{
    if (level == 1)
    {
        printf("(-.-)");
    }
    else
    {
        printf("(-.");
        mafiaChina(level - 1);
        printf(".-)");
    }
}

void printNiveles(int level)
{
    if (level > 0)
    {
        printNiveles(level - 1);
        printf("%2d                          ", level);
        mafiaChina(level);
        printf("\n");
    }
}

//////// punto 7

void ondaDigitalAux(char *s, char *gr, int i, bool primerCaracter)
{
    if (i < strlen(s))
    {
        if (s[i] == 'L')
        {
            if (!primerCaracter && (s[i - 1] != 'L'))
            {
                strcat(gr, "| ");
            }
            strcat(gr, "_ ");
        }
        else
        {
            if (!primerCaracter && (s[i - 1] != 'H'))
            {
                strcat(gr, "| ");
            }
            strcat(gr, "¯ ");
        }
        ondaDigitalAux(s, gr, i + 1, false);
    }
}

void ondaDigital(char *s, char *gr)
{
    bool primerCaracter = true;
    ondaDigitalAux(s, gr, 0, primerCaracter);
}

//////// punto 8

void imprimirSubconjunto(int subconjunto[], int n)
{
    if (n == 0)
    { // Si no quedan elementos por imprimir, se sale de la función
        printf("}\n");
        return;
    }
    printf("%d", subconjunto[0]); // Se imprime el primer elemento del subconjunto
    if (n > 1)
    {
        printf(", ");
    }
    imprimirSubconjunto(subconjunto + 1, n - 1); // Se llama recursivamente a la función con el resto del subconjunto
}

void subconjuntosQueSumanNRecursivo(int conjunto[], int n, int i, int suma_actual, int *subconjunto, int j)
{
    if (suma_actual == n)
    { // Si la suma actual es igual a la cantidad buscada, se imprime el subconjunto
        printf("{");
        imprimirSubconjunto(subconjunto, j);
        return;
    }
    if (i == 6 || suma_actual > n)
    { // Si se llega al final del conjunto o la suma actual supera la cantidad buscada, se sale de la función
        return;
    }
    subconjunto[j] = conjunto[i];                                                                      // Se añade el elemento actual al subconjunto
    subconjuntosQueSumanNRecursivo(conjunto, n, i + 1, suma_actual + conjunto[i], subconjunto, j + 1); // Se llama recursivamente a la función con el siguiente elemento del conjunto
    subconjunto[j] = 0;                                                                                // Se elimina el último elemento añadido al subconjunto
    subconjuntosQueSumanNRecursivo(conjunto, n, i + 1, suma_actual, subconjunto, j);                   // Se llama recursivamente a la función sin añadir el elemento actual al subconjunto
}

void subconjuntosQueSumanN(int conjunto[], int n)
{
    int subconjunto[6] = {0}; // Se inicializa el subconjunto a cero
    subconjuntosQueSumanNRecursivo(conjunto, n, 0, 0, subconjunto, 0);
}

//////// punto 9

void divisiblePor7(int n)
{
    if (n <= 70)
    {
        if (n % 7 == 0)
        {
            printf("%d es divisible por 7\n", n);
        }
        else
        {
            printf("%d no es divisible por 7\n", n);
        }
    }
    else
    {
        printf("%d -> ", n);
        int r = n % 10; // Separar la última cifra
        n = n / 10;     // Descartar la última cifra
        printf("%d x 2 = %d\n", r, r * 2);
        printf("%d - %d = \n", n, r * 2);
        divisiblePor7(n - r * 2);
    }
}

//////// punto 10

void explosion(int N, int B, int *result, int *len)
{
    if (N <= B)
    {
        result[(*len)++] = N;
        return;
    }
    int N1 = N / B;
    int N2 = N - N1;
    explosion(N1, B, result, len);
    explosion(N2, B, result, len);
}

void main()
{
    int opcion;
    printf("Por favor ingrese un número entero para acceder a un punto (del 1 al 10): ");
    /*scanf("%d", &opcion);
    while (scanf("%d", &opcion) != 1)
    {
        printf("Error: Se esperaba un número entero válido.\n");
    }
    while (opcion < 0 || opcion > 10)
    {
        printf("Error: El número debe estar entre 0 y 10.\n");
        scanf("%d", &opcion);
    }*/
    char buffer[256]; // Se declara un arreglo de caracteres para almacenar la entrada

    printf("Ingrese una cadena de texto: ");
    fgets(buffer, sizeof(buffer), stdin); // Se lee una línea de texto desde la entrada estándar y se almacena en el arreglo 'buffer'

    printf("La cadena de texto ingresada es: %s\n", buffer); // Se imprime la cadena de texto ingresada

    switch (opcion)
    {
    case 1:
    {
        printf("Seleccionaste la opción 1\n");
        break;
    }

    case 2:
    {
        printf("Seleccionaste la opción 2\n");
        // printf("%d", producto(10, 2));
        break;
    }

    case 3:
    {
        printf("Seleccionaste la opción 3\n");
        /*j = fibo(3);
        printf("%d", j);*/
        break;
    }

    case 4:
    { // division(10, 2, 0);
        break;
    }

    case 5:
    {
        // char num1[] = "123456";
        /*char num[] = "12345678";
        agregarSeparadorMiles(num);
        printf("%s\n", num);*/
        break;
    }

    case 6:
    {
        int level = 4;
        /* printf("Ingrese el nivel de la reunión: ");
        scanf("%d", &level);
        printf("Vista frontal de la delegación: ");*/
        printf("\n");
        printNiveles(level);
        break;
    }
    case 7:
    {
        /*char resultado[50];
        char cadenaEntrada[] = "HHHHLLLLHHHHHLLHH";
        ondaDigital(cadenaEntrada, resultado);
        printf("%s\n", resultado);*/
        break;
    }
    case 8:
    { /*
    int conjunto[] = {10, 3, 1, 7, 4, 2};
    int n = 10;
    printf("Subconjuntos que suman %d:\n", n);
    subconjuntosQueSumanN(conjunto, n);
    */
        break;
    }

    case 9:
    { /* int n = 32291;
    divisiblePor7(n);*/
        break;
    }

    case 10:
    { /* int N = 10;
    int B = 3;
    printf("Número: %d \n", N);
    printf("Bomba: %d \n", B);
    int result[N];
    int len = 0;
    explosion(N, B, result, &len);
    for (int i = 0; i < len; i++)
    {
    printf("%d ", result[i]);
    }*/
        break;
    }

    default:
    {
        printf("Seleccionaste una opción inválida\n");
        break;
    }
    }
}