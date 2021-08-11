#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( ) {
    char opcion = 'o', suma = 's', resta = 'r', multiplicacion = 'm', division = 'd', exit = 'e';
    float num1 = 0,num2 = 0, resultado = 0;
    do{
        printf("Programa aritmeticos con dos numeros\n\n");

        printf("Que operacion se va a realizar?\n");
        printf("(s): Suma\n");
        printf("(r): Resta\n");
        printf("(m): Multiplicacion\n");
        printf("(d): Division\n");
        printf("(e): Salir\n");
        printf("Su opcion: ");
        scanf("%c",&opcion);
        
        printf()
        if(strcmp(&opcion,&suma) == 0 || strcmp(&opcion,&resta) == 0 || strcmp(&opcion,&multiplicacion) == 0 || strcmp(&opcion,&division) == 0)
        {
            printf("Ingrese el primer numero: ");
            scanf("%f",&num1);
            printf("Ingrese el segundo numero: ");
            scanf("%f",&num2);
        }

        switch(opcion)
        {
            case 's':
                resultado = num1 + num2;
            break;
            case 'r':  
                resultado = num1 - num2;
            break;
            case 'm':
                resultado = num1 * num2;
            break;
            case 'd':
                if(num2 == 0)
                {
                    printf("No se puede hacer la division entre cero!");
                }
                else
                {
                    resultado = num1 / num2;
                }
            break;
            case 'e':
                printf("Fin del programa\n");
            break;
            default:
                printf("No es una opcion valida\n");
        }
    }while(strcmp(&opcion,&exit) != 0);
    return 0;
}
