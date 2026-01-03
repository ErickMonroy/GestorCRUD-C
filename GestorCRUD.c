/*Crear un programa relacionado Bajas y actualización  de registros en un archivo. 
Validar que el registro exista y si no mandar un mensaje, 
si el registro existe enviar el mensaje que va hacer la actualización del registro.*/

#include <stdio.h> //*contiene las definiciones de las macros, las constantes, las declaraciones de funciones de la biblioteca estándar del lenguaje de programación C*// 
#include <stdlib.h> //lo usamos para evitar los errores (exit)//
#include <string.h> // proporciona funciones y macros para manipular cadenas de caracteres.//
#include <locale.h> // se usa para poder determinar el idioma //
typedef struct {    //Definir un nuevo tipo de dato en este caso es el de persona, apartado de variables del registro//
    int folio;
    char nombre[50];
    char apellido1[50];
    char apellido2[50];
    int edad;
    char telefono[20];
} tpersona;


void continuar() { //determinar que una función no retorna un valor, apartado para mostrar en pantalla que el usuario desea continuar//
    printf("\nPresione la tecla enter para continuar..."); //"	printf: imprimir en pantalla//
    getchar();  // Esperar entrada del usuario
}

void agregar() { //apartado de la opción 1: agregar registro//
    setlocale (LC_ALL, "spanish");
    FILE *arch;
    arch = fopen("registro.txt", "a"); //Abrir un archivo específico//
    if (arch == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    tpersona persona; //solicitar datos//
    printf("Ingrese el folio de la persona: ");
    scanf("%d", &persona.folio); //analiza la entrada de los datos y prosigue con el aguardado en la variable//
    fflush(stdin); //limpiar el búfer//

    printf("Ingrese el nombre de la persona sin acentos: ");
    scanf("%s", persona.nombre);
    fflush(stdin);

    printf("Ingrese el primer apellido de la persona sin acentos: ");
    scanf("%s", persona.apellido1);
    fflush(stdin);

    printf("Ingrese el segundo apellido de la persona sin acentos: ");
    scanf("%s", persona.apellido2);
    fflush(stdin);

    printf("Ingrese la edad de la persona: ");
    scanf("%d", &persona.edad);
    fflush(stdin);

    printf("Ingrese el número de teléfono de la persona: ");
    scanf("%s", persona.telefono);
    fflush(stdin);

    fprintf(arch, "%d %s %s %s %d %s\n", persona.folio, persona.nombre, persona.apellido1, persona.apellido2, persona.edad, persona.telefono); //guardar datos en el registro//
    printf("\nEl registro se ha guardado correctamente.\n"); 

    fclose(arch);
    continuar();
}


    
void actualizar() { //apartado de la opción 2: actualizar//
    setlocale (LC_ALL, "spanish");
    FILE *arch;
    FILE *temp;
    arch = fopen("registro.txt", "r");
    temp = fopen("temp.txt", "w");
    if (arch == NULL || temp == NULL) {
        printf("Error al abrir los archivos.\n");
        exit(1);
    }

    int folio;
    printf("Ingrese el folio de la persona a actualizar: ");
    scanf("%d", &folio);
    fflush(stdin);
    
    
    tpersona persona;
    int encontrado = 0;
    while (fscanf(arch, "%d %s %s %s %d %[^\n]", &persona.folio, persona.nombre, persona.apellido1, persona.apellido2, &persona.edad, persona.telefono) == 6) {
        if (persona.folio == folio) {
            encontrado = 1;
            printf("\nEl registro se va a actualizar.\n");

            // Solicitar nueva información
            printf("Ingrese el nombre sin acentos: ");
            scanf("%s", persona.nombre);
            fflush(stdin);

            printf("Ingrese el primer apellido sin acentos: ");
            scanf("%s", persona.apellido1);
            fflush(stdin);

            printf("Ingrese el segundo apellido sin acentos: ");
            scanf("%s", persona.apellido2);
            fflush(stdin);

            printf("Ingrese la edad: ");
            scanf("%d", &persona.edad);
            fflush(stdin);

            printf("Ingrese el número de teléfono: ");
            scanf("%s", persona.telefono);
            fflush(stdin);

            fprintf(temp, "%d %s %s %s %d %s\n", persona.folio, persona.nombre, persona.apellido1, persona.apellido2, persona.edad, persona.telefono);
            printf("\nSe ha actualizado el registro.\n");
        } else {
            fprintf(temp, "%d %s %s %s %d %s\n", persona.folio, persona.nombre, persona.apellido1, persona.apellido2, persona.edad, persona.telefono);
        }
    }

    if (!encontrado) {
        printf("No se encontró ningún registro con el folio ingresado.\n");
    }

    fclose(arch);
    fclose(temp);
    remove("registro.txt");
    rename("temp.txt", "registro.txt");

    continuar();
}

void eliminar() { //apartado de la opción 3: eliminar registro//
    setlocale (LC_ALL, "spanish");
    FILE *arch;
    FILE *temp;
    arch = fopen("registro.txt", "r");
    temp = fopen("temp.txt", "w");
    if (arch == NULL || temp == NULL) {
        printf("Error al abrir los archivos.\n");
        exit(1);
    }

    int folioEliminar;
    printf("Ingrese el folio de la persona a eliminar: ");
    scanf("%d", &folioEliminar);
    fflush(stdin);

    tpersona persona;
    int eliminado = 0;

    while (fscanf(arch, "%d %s %s %s %d %[^\n]", &persona.folio, persona.nombre, persona.apellido1, persona.apellido2, &persona.edad, persona.telefono) == 6) {
        if (persona.folio == folioEliminar) {
            eliminado = 1;
            printf("\nSe ha eliminado el registro.\n");
        
    
        } else { //si o no)
            fprintf(temp, "%d %s %s %s %d %s\n", persona.folio, persona.nombre, persona.apellido1, persona.apellido2, persona.edad, persona.telefono);
        }
    }

    if (!eliminado) { //si  (condición)//
        printf("No se encontró ningún registro con el folio ingresado.\n");
    }

    fclose(arch);
    fclose(temp);
    remove("registro.txt");//se ejecuta el proceso de eliminación del registro específico//
    rename("temp.txt", "registro.txt");

    continuar();
}

int main() { // Se define el menú de las opciones//
    setlocale (LC_ALL, "spanish");
    int opcion; //definir la variable opción//
    do { //se utiliza para crear un bucle que ejecuta un bloque del código//
        printf("1 - Agregar registro\n");
        printf("2 - Actualizar registro\n");
        printf("3 - Eliminar registro específico\n");
        printf("4 - Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) { //bloques de instrucciones dependiendo del valor de la variable opción.//
            case 1:
                agregar();
                break;

            case 2:
                actualizar();
                break;

            case 3:
                eliminar();
                break;

            case 4:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción inválida. Por favor, ingrese un número válido.\n");
                break;
        }
    } while (opcion != 4); //es una estructura de control que permite repetir un bloque de código mientras se verifique la condición determinada//

    return 0;
}

