/**
 * Programa que realiza operaciones aritmeticas basicas entre dos numeros. 
 * 
 * Por Fernando Daniel Ramirez Cruz
 * 10 de agosto de 2021
*/

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( ) {
    
    char opcion = 'o'; // variable para elegir la operacion
    float num1 = 0,num2 = 0, resultado = 0; // variables para los numeros num1 y num2, sobre los cuales se realizaran operaciones aritmeticas
                                            // El resultado se almacena en la variable resultado    

    printf("Programa aritmeticos con dos numeros\n\n"); // Mensaje de bienvenida

    do{
        //Mensajes del menu de opciones de operaciones aritmeticas
        printf("Que operacion se va a realizar?\n");
        printf("(s): Suma\n");
        printf("(r): Resta\n");
        printf("(m): Multiplicacion\n");
        printf("(d): Division\n");
        printf("(e): Salir\n");
        printf("Su opcion (escriba una letra ej. s para suma): "); // Mensaje para pedir que el usuario ingrese una opcion

        scanf("%c",&opcion); // El usuario ingresa una letra
                
        // Se revisa si el caracter fue para seleccionar una operacion aritmetica
        if(opcion == 's' || opcion == 'r' || opcion == 'm' || opcion == 'd')
        {
            // En caso de realizarse una operacion aritmetica, pide los numeros al usuario
            printf("Ingrese el primer numero: "); // Mensaje para pedir el primer numero
            scanf("%f",&num1); // Pide el primer numero
            printf("Ingrese el segundo numero: "); // Mensaje para pedir el segundo numero
            scanf("%f",&num2); // Pide el segundo numero
        }

        switch(opcion) // Este switch-case realiza la operacion matematica correspondiente a la seleccionada
        {
            case 's': // Realiza la suma
                resultado = num1 + num2; 
            break;
            case 'r': // Realiza la resta
                resultado = num1 - num2;
            break;
            case 'm': // Realiza la multiplicacion
                resultado = num1 * num2;
            break;
            case 'd': // Realiza la division
                if(num2 == 0) // Revisa si el segundo numero es cero, puesto que no se puede hacer la division entre cero
                {
                    printf("\nNo se puede hacer la division entre cero!\n"); // Mensaje que indica que no se puede hacer la division
                }
                else
                {
                    // En caso de ser posible la realizacion de la division, se realiza la operacion
                    resultado = num1 / num2;
                }
            break;
            case 'e': // Indica el final del programa
                printf("\nFin del programa\n");
            break;
            default: // Manda un mensaje si se ingreso alguna opcion que no realiza nada
                printf("No es una opcion valida\n");
        }

        // Revisa si se realizo alguna operacion
        if(opcion == 's' || opcion == 'r' || opcion == 'm' || (opcion == 'd' && num2!=0))
        {
            // Imprime el resultado en consola
            printf("\nResultado: %.3f\n",resultado);
        }
        
        printf("\n");

        getchar(); // Esta funcion es para limpiar la entrada del usuario, en caso de que haya basura por leer
    }while(opcion != 'e'); // Revisa si el usuario eligio salir, de lo contrario, repite el programa
    
    return 0;
}
