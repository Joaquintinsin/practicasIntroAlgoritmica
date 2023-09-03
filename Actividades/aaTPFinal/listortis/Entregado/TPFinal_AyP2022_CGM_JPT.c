/* Intr. a la algoritmica y programacion
 * Proyecto de final de anio: 2022
 * Integrantes: Celina Gillo Mayer, Joaquin Pablo Tissera
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcat(), strcpy()
#include <time.h>   // strftime(), time_t, struct tm *tm, localtime(), time()

#define Max 256

typedef struct
{
    long int ddmmyyyy;
    int tmax;
    int tmin;
    int HUM;
    int PNM;
    int DV;
    int FF;
    int PP;
    int borrado;
} Tregdiario;

typedef struct TData
{
    Tregdiario a[Max];
    int cant;
} TData;

typedef struct Tnodo
{
    Tregdiario info;
    struct Tnodo *next;
} Tnodo;

int ArchVacio(char nom[20]);                          // Funcion ArchVacio(dato nom e Cadena) → Logico
void PedirAnio(int *anio);                            // Accion PedirAnio(resultado anio e Z)
void PedirFecha(int aA, long int *fecha);             // Accion PedirFecha(dato aA e Z resultado fecha e Z)
TData ArchArray(char nom[25]);                        // Funcion ArchArray(dato nom e Cadena) → TData
void Alta(int anioEntry, char nom[25]);               // Accion Alta(dato anioEntry e Z, nom e Cadena)
void Suprimir(int anioEntry, char nom[20]);           // Accion Suprimir(dato anioEntry e Z, nom e Cadena)
void ModificarRegistro(int anioEntry, char nom[20]);  // Accion ModificarRegistro(dato anioEntry e Z, nom e cadena)
void MostrarArchivo(char nom[25]);                    // Accion MostrarArchivo(dato nom e cadena)
int BuscaPosRecursiva(TData array, int i, int fecha); // Funcion BuscaPosRecursiva(dato registro e TData, i e Z, fecha1 e Z) → Z
void MostrarDatos_Pos(int i, TData registro);         // Accion MostrarDatos_Pos (dato posicion e Z, registro e TData)
void VaciarListaConFict(Tnodo *q);                    // Accion VaciarListaConFict(dato q e puntero a Tnodo)
void MostrarLSETempMax(Tnodo *q);                     // Accion MostrarLSETempMax(dato q e puntero a Tnodo)
void ListarTempMax(char nom[25], Tnodo **s);          // Accion ListarTempMax(dato nom e cadena, resultado s e puntero a Tnodo)
void ListarPrecMax(char nom[25]);                     // Accion ListarPrecMax(dato nom e cadena)
void ListarMayMenVelViento(char nom[25]);             // Accion ListarMayMenVelViento(dato nom e cadena)
void CopiaSeguridad(char nom[25]);                    // Accion CopiaSeguridad(dato nom e Cadena)
void Verificar(char nom[25], FILE **fA);              // Accion Verificar(dato nom e Cadena, dato/resultado fA e Archivo de regdiario)
void OrdenarInsertionReves(TData *arr);               // Accion OrdenarInsertionReves (dato/resultado arr e TData)
void OrdenarBubbleReves(TData *a);                    // Accion OrdenarBubbleReves (dato/resultado a e TData)
void DesplegarMenuDeOpciones();                       // Accion DesplegarMenuDeOpciones ()

int main(int argc, char **argv)
{
    Tregdiario capturarReg;
    TData arregloPos;
    Tnodo *listaTempMax;
    FILE *f;
    char nombreArchivo[25], extension[10];
    int opcionEntry, anioPedido, pos;
    long int obtDia, obtMes, obtAnio, fechaBuscar;

    printf("Inicio del programa.\n");
    printf("A continuacion se manejara un menu de opciones para el modelo de una estacion metereologica. \n");
    printf("Por favor, inserte el nombre del archivo que usara para el programa (sin el .dat): \n");
    scanf("%[^\n]", nombreArchivo);
    strcpy(extension, ".dat");
    strcat(nombreArchivo, extension);
    Verificar(nombreArchivo, &f);

    do
    {
        DesplegarMenuDeOpciones();
        scanf("%d", &opcionEntry);
        // Modelo el Segun en C como Si entonces asi es mas legible. Todas las condiciones de
        // los si son excluyentes uno al otro, por lo tanto resulta equivalente.
        if (opcionEntry == 1)
        {
            printf("Opcion 1: Alta de un registro diario \n");
            printf("Ingresar el anio correspondiente al registro. \n");
            printf("En caso que el archivo ya tenga elementos cargados, debe coincidir con el anio de los que ya esten cargados en el archivo \n");
            PedirAnio(&anioPedido);
            if (ArchVacio(nombreArchivo))
            {
                // Esta vacio, no hay problema con poner cualquier anio
                Alta(anioPedido, nombreArchivo);
            }
            else
            {
                // No esta vacio. Reviso si los anios coinciden:
                f = fopen(nombreArchivo, "r+b");
                fread(&capturarReg, sizeof(Tregdiario), 1, f);
                fclose(f);
                obtDia = capturarReg.ddmmyyyy / 1000000;
                obtMes = capturarReg.ddmmyyyy / 10000 - (obtDia * 100);
                obtAnio = capturarReg.ddmmyyyy - (obtDia * 1000000) - (obtMes * 10000);
                // printf ("obtMes: %ld \n", obtMes);
                // printf ("obtDia: %ld \n", obtDia);
                // printf ("obtAnio: %ld \n", obtAnio);
                if (obtAnio == anioPedido)
                {
                    Alta(anioPedido, nombreArchivo);
                }
                else
                {
                    printf("Los anios no coinciden. El anio cargado es %ld. \n", obtAnio);
                }
            }
        }
        if (opcionEntry == 2)
        {
            printf("Opcion 2: Suprimir un registro diario \n");
            if (ArchVacio(nombreArchivo))
            {
                // Esta vacio o todo suprimido.
                printf("El archivo esta vacio o todos sus registros ya estan borrados. Vuelve al menu principal.\n");
            }
            else
            {
                // Hay cosas presentes en el archivo, se puede proceder a suprimir.
                printf("Ingresar el anio correspondiente al registro que quiere suprimir. \n");
                printf("Debe coincidir con el anio de los que ya esten cargados en el archivo \n");
                PedirAnio(&anioPedido);
                f = fopen(nombreArchivo, "r+b");
                fread(&capturarReg, sizeof(Tregdiario), 1, f);
                fclose(f);
                obtDia = capturarReg.ddmmyyyy / 1000000;
                obtMes = capturarReg.ddmmyyyy / 10000 - (obtDia * 100);
                obtAnio = capturarReg.ddmmyyyy - (obtDia * 1000000) - (obtMes * 10000);
                // printf ("obtMes: %ld \n", obtMes);
                // printf ("obtDia: %ld \n", obtDia);
                // printf ("obtAnio: %ld \n", obtAnio);
                if (obtAnio == anioPedido)
                {
                    Suprimir(anioPedido, nombreArchivo);
                }
                else
                {
                    printf("Los anios no coinciden. El anio cargado es %ld. \n", obtAnio);
                }
            }
        }
        if (opcionEntry == 3)
        {
            printf("Opcion 3: Modificar un registro, se busca por la fecha \n");
            if (ArchVacio(nombreArchivo))
            {
                // Esta vacio o todo suprimido.
                printf("El archivo esta vacio o todos sus registros estan borrados. Vuelve al menu principal.\n");
            }
            else
            {
                // Hay cosas presentes en el archivo, se puede proceder a modificar.
                printf("Ingresar el anio correspondiente al registro que quiere modificar. \n");
                printf("Debe coincidir con el anio de los que ya esten cargados en el archivo \n");
                PedirAnio(&anioPedido);
                f = fopen(nombreArchivo, "r+b");
                fread(&capturarReg, sizeof(Tregdiario), 1, f);
                fclose(f);
                obtDia = capturarReg.ddmmyyyy / 1000000;
                obtMes = capturarReg.ddmmyyyy / 10000 - (obtDia * 100);
                obtAnio = capturarReg.ddmmyyyy - (obtDia * 1000000) - (obtMes * 10000);
                // printf ("obtMes: %ld \n", obtMes);
                // printf ("obtDia: %ld \n", obtDia);
                // printf ("obtAnio: %ld \n", obtAnio);
                if (obtAnio == anioPedido)
                {
                    ModificarRegistro(anioPedido, nombreArchivo);
                }
                else
                {
                    printf("Los anios no coinciden. El anio cargado es %ld. \n", obtAnio);
                }
            }
        }
        if (opcionEntry == 4)
        {
            printf("Opcion 4: Mostrar todos los registros activos \n");
            MostrarArchivo(nombreArchivo);
        }
        if (opcionEntry == 5)
        {
            printf("Opcion 5: Buscar registro de un dia dado y mostrar todos los parametros \n");
            if (ArchVacio(nombreArchivo))
            {
                printf("El archivo esta vacio o todos sus registros estan borrados. Vuelve al menu principal.\n");
            }
            else
            {
                printf("Ingresar la fecha que quiere buscar \n");
                PedirAnio(&anioPedido);
                f = fopen(nombreArchivo, "r+b");
                fread(&capturarReg, sizeof(Tregdiario), 1, f);
                fclose(f);
                obtDia = capturarReg.ddmmyyyy / 1000000;
                obtMes = capturarReg.ddmmyyyy / 10000 - (obtDia * 100);
                obtAnio = capturarReg.ddmmyyyy - (obtDia * 1000000) - (obtMes * 10000);
                // printf ("obtMes: %ld \n", obtMes);
                // printf ("obtDia: %ld \n", obtDia);
                // printf ("obtAnio: %ld \n", obtAnio);
                if (obtAnio == anioPedido)
                {
                    PedirFecha(anioPedido, &fechaBuscar);
                    arregloPos = ArchArray(nombreArchivo);
                    pos = BuscaPosRecursiva(arregloPos, 0, fechaBuscar);
                    // printf ("pos: %d \n", pos);
                    MostrarDatos_Pos(pos, arregloPos);
                }
                else
                {
                    printf("Los anios no coinciden. El anio cargado es %ld. \n", obtAnio);
                }
            }
        }
        if (opcionEntry == 6)
        {
            printf("Opcion 6: Listar el dia o dias de maxima temperatura en lo que va del anio \n");
            ListarTempMax(nombreArchivo, &listaTempMax);
            MostrarLSETempMax(listaTempMax);
        }
        if (opcionEntry == 7)
        {
            printf("Opcion 7: Listar el dia o dias de maxima precipitacion en lo que va del anio \n");
            ListarPrecMax(nombreArchivo);
        }
        if (opcionEntry == 8)
        {
            printf("Opcion 8: Listar las fechas de mayor a menor velocidad de viento \n");
            ListarMayMenVelViento(nombreArchivo);
        }
        if (opcionEntry == 9)
        {
            printf("Opcion 9: Realizar una copia de seguridad del archivo del anio en curso \n");
            CopiaSeguridad(nombreArchivo);
        }
        if (opcionEntry == 10)
        {
            printf("Opcion 10: Salir \n");
        }
        if (opcionEntry != 1 && opcionEntry != 2 && opcionEntry != 3 && opcionEntry != 4 && opcionEntry != 5 && opcionEntry != 6 && opcionEntry != 7 && opcionEntry != 8 && opcionEntry != 9 && opcionEntry != 10)
        {
            // Otros: Osea negar todas las demas condiciones.
            printf("Debe ser un numero del 1 al 10. \n");
        }
    } while (!(opcionEntry == 10));

    printf("Salida exitosa. \n");
    return 0;
}

// Chequea si un archivo esta vacio, ya sea por EOF o porque todos los registros estan borrados
int ArchVacio(char nom[20])
{
    FILE *f;
    Tregdiario r;

    f = fopen(nom, "r+b");
    // Abrirlo con "r+b" posiciono el cabezal al inicio
    if (fread(&r, sizeof(Tregdiario), 1, f) == 0)
    {
        fclose(f);
        return 1;
    }
    else
    {
        do
        {
            if (!r.borrado)
            {
                fclose(f);
                return 0;
            }
        } while (fread(&r, sizeof(Tregdiario), 1, f) > 0);
        if (fread(&r, sizeof(Tregdiario), 1, f) <= 0)
        {
            fclose(f);
            return 1;
        }
    }
    // No llega nunca aca, pero para que no salte el warning
    return 1;
}

// Le pide el anio el usuario. Usada en las opciones que se requiera para que coincida con los anios que ya esten cargados y no avanzar en vano.
void PedirAnio(int *anio)
{
    printf("Anio: ");
    scanf("%d", anio);
    if (*anio < 1000 || *anio > 9999)
    {
        do
        {
            printf("Ingresar un anio valido: ");
            scanf("%d", anio);
        } while (*anio < 1000 || *anio > 9999);
    }
}

// Recibe el anio como dato y dentro de la accion pide el dia y el mes.
// Convierte los tres datos individuales en uno solo que correspondera al formato ddmmyyyy.
void PedirFecha(int aA, long int *fecha)
{
    int EsBisiesto(int checkA)
    {
        return (((checkA % 4) == 0 && (checkA % 100) != 0) || ((checkA % 100) == 0 && (checkA % 400) == 0));
    }
    int dA, mA;

    printf("Mes: ");
    scanf("%d", &mA);
    // Def de meses
    if (mA < 1 || mA > 12)
    {
        do
        {
            printf("Ingresar un mes valido: ");
            scanf("%d", &mA);
        } while (mA < 1 || mA > 12);
    }

    printf("Dia: ");
    scanf("%d", &dA);
    // Def de dias
    if (dA < 1 || dA > 31)
    {
        do
        {
            printf("Ingresar un dia valido: ");
            scanf("%d", &dA);
        } while (dA < 1 || dA > 31);
    }

    // Es bisiesto y puso una fecha invalida de febrero
    if (EsBisiesto(aA) && mA == 2 && dA > 29)
    {
        do
        {
            printf("Ingresar un dia de febrero valido. El anio ingresado es bisiesto: ");
            scanf("%d", &dA);
        } while (dA < 1 || dA > 29);
    }

    // No es bisiesto y puso una fecha invalida de febrero
    if (!EsBisiesto(aA) && mA == 2 && dA > 28)
    {
        do
        {
            printf("Ingresar un dia de febrero valido. El anio ingresado no es bisiesto: ");
            scanf("%d", &dA);
        } while (dA < 1 || dA > 28);
    }

    if ((mA == 4 || mA == 5 || mA == 6 || mA == 9 || mA == 11) && dA == 31)
    {
        do
        {
            printf("Los meses 4, 5, 6, 9 y 11 tienen 30 dias. Ingresar un dia valido: ");
            scanf("%d", &dA);
        } while ((mA == 4 || mA == 5 || mA == 6 || mA == 9 || mA == 11) && dA == 31);
    }

    *fecha = dA * 1000000 + mA * 10000 + aA;
}

// Recibe el nombre externo del archivo y devuelve un arreglo
TData ArchArray(char nom[25])
{
    TData registro;
    Tregdiario reg;
    int i;
    FILE *f;

    f = fopen(nom, "r+b");
    // Si lo abro y esta vacio o todos borrados devuelvo el TData con cant = 0
    // sino devuelvo el TData con las cosas del archivo y el cant actualizado
    if (ArchVacio(nom))
    {
        registro.cant = 0;
    }
    else
    {
        i = 0; // inicializacion
        while (fread(&reg, sizeof(Tregdiario), 1, f) > 0 && (i <= Max))
        {
            registro.a[i] = reg;
            i = i + 1;
        }
        registro.cant = i;
    }
    fclose(f);
    return registro;
}

void Alta(int anioEntry, char nom[25])
{
    void PedirTemp(int *tM)
    {
        scanf("%d", &(*tM));
        if (*tM < -100 || *tM > 100)
        {
            do
            {
                printf("Ingresar una temperatura valida. Entre -100 y 100: ");
                scanf("%d", &(*tM));
            } while (*tM < -100 || *tM > 100);
        }
    }
    void PedirHumedad(int *hA)
    {
        printf("Ingresar el porcentaje de humedad (de 0 a 100): ");
        scanf("%d", &(*hA));
        if (*hA < 0 || *hA > 100)
        {
            do
            {
                printf("Ingresar un porcentaje de humedad valido. Entre 0 y 100: ");
                scanf("%d", &(*hA));
            } while (*hA < 0 || *hA > 100);
        }
    }
    void PedirDirViento(int *dvA)
    {
        printf("Ingresar la direccion del viento (de 0 a 360): ");
        scanf("%d", &(*dvA));
        if (*dvA < 0 || *dvA > 360)
        {
            do
            {
                printf("Ingresar una direccion de viento valida. Entre 0 y 360: ");
                scanf("%d", &(*dvA));
            } while (*dvA < 0 || *dvA > 360);
        }
    }
    void PedirPresAtm(int *prA)
    {
        printf("Ingresar la presion atmosferica (de 900 a 3500): ");
        scanf("%d", &(*prA));
        if (*prA < 900 || *prA > 3500)
        {
            do
            {
                printf("Ingresar una presion atmosferica valida. Entre 900 y 3500: ");
                scanf("%d", &(*prA));
            } while (*prA < 900 || *prA > 3500);
        }
    }
    void PedirVelocViento(int *wA)
    {
        printf("Ingresar la velocidad del viento (mayor que 0): ");
        scanf("%d", &(*wA));
        if (*wA <= 0)
        {
            do
            {
                printf("Ingresar una velocidad de viento valida. Debe ser positivo: ");
                scanf("%d", &(*wA));
            } while (*wA <= 0);
        }
    }
    void PedirPrecPluv(int *ppA)
    {
        printf("Ingresar la precipitacion pluvial (de 0 a 1000): ");
        scanf("%d", &(*ppA));
        if (*ppA < 0 || *ppA > 1000)
        {
            do
            {
                printf("Ingresar una precipitacion pluvial valida. Entre 0 y 1000: ");
                scanf("%d", &(*ppA));
            } while (*ppA < 0 || *ppA > 1000);
        }
    }
    FILE *fA;
    Tregdiario rA, captReg;
    int iguales;

    fA = fopen(nom, "r+b");
    PedirFecha(anioEntry, &rA.ddmmyyyy);
    iguales = 0;
    while (fread(&captReg, sizeof(Tregdiario), 1, fA) > 0 && !iguales)
    {
        iguales = (rA.ddmmyyyy == captReg.ddmmyyyy && !captReg.borrado);
    }
    if (!iguales)
    {
        printf("Ingresar la temperatura maxima de la fecha: ");
        PedirTemp(&rA.tmax);
        printf("Ingresar la temperatura minima de la fecha: ");
        PedirTemp(&rA.tmin);
        PedirHumedad(&rA.HUM);
        PedirPresAtm(&rA.PNM);
        PedirDirViento(&rA.DV);
        PedirVelocViento(&rA.FF);
        PedirPrecPluv(&rA.PP);
        rA.borrado = 0;
        fwrite(&rA, sizeof(rA), 1, fA);
        printf("Registro dado de alta exitosamente! \n");
    }
    else
    {
        printf("Ya existe un registro presente con la fecha indicada. Vuelve al menu. \n");
    }
    fclose(fA);
}

void Suprimir(int anioEntry, char nom[20])
{
    int PropEC(Tregdiario regArch, int fechaPedida)
    {
        return (regArch.ddmmyyyy == fechaPedida && !regArch.borrado);
    }
    long int fecha;
    Tregdiario rA;
    FILE *f;
    int rta;

    f = fopen(nom, "rb+");
    if (ArchVacio(nom))
    {
        printf("No se puede suprimir porque el archivo esta vacio o todos los registro estan borrados.\nVuelve al menu principal. \n");
    }
    else
    {
        printf("¿Desea suprimir un registro? Si = 1 / No = 0: ");
        scanf("%d", &rta);
        if (rta)
        {
            printf("De que fecha es el registro que quiere suprimir?: \n");
            PedirFecha(anioEntry, &fecha);
            do
            {
            } while (fread(&rA, sizeof(Tregdiario), 1, f) > 0 && !PropEC(rA, fecha));
            if (PropEC(rA, fecha))
            {
                rA.borrado = 1;
                fseek(f, (-1) * sizeof(Tregdiario), SEEK_CUR);
                fwrite(&rA, sizeof(Tregdiario), 1, f);
                printf("Suprimido con exito \n");
            }
            else
            {
                printf("No se encontro la fecha %ld para suprimir \n", fecha);
            }
        }
        else
        {
            printf("No se quiso suprimir nada. Vuelve al menu principal \n");
        }
    }
    fclose(f);
}

void ModificarRegistro(int anioEntry, char nom[20])
{
    void PedirTemp(int *tM)
    {
        scanf("%d", &(*tM));
        if (*tM < -100 || *tM > 100)
        {
            do
            {
                printf("Ingresar una temperatura valida. Entre -100 y 100: ");
                scanf("%d", &(*tM));
            } while (*tM < -100 || *tM > 100);
        }
    }
    void PedirHumedad(int *hA)
    {
        printf("Ingresar el porcentaje de humedad (de 0 a 100): ");
        scanf("%d", &(*hA));
        if (*hA < 0 || *hA > 100)
        {
            do
            {
                printf("Ingresar un porcentaje de humedad valido. Entre 0 y 100: ");
                scanf("%d", &(*hA));
            } while (*hA < 0 || *hA > 100);
        }
    }
    void PedirDirViento(int *dvA)
    {
        printf("Ingresar la direccion del viento (de 0 a 360): ");
        scanf("%d", &(*dvA));
        if (*dvA < 0 || *dvA > 360)
        {
            do
            {
                printf("Ingresar una direccion de viento valida. Entre 0 y 360: ");
                scanf("%d", &(*dvA));
            } while (*dvA < 0 || *dvA > 360);
        }
    }
    void PedirPresAtm(int *prA)
    {
        printf("Ingresar la presion atmosferica (de 900 a 3500): ");
        scanf("%d", &(*prA));
        if (*prA < 900 || *prA > 3500)
        {
            do
            {
                printf("Ingresar una presion atmosferica valida. Entre 900 y 3500: ");
                scanf("%d", &(*prA));
            } while (*prA < 900 || *prA > 3500);
        }
    }
    void PedirVelocViento(int *wA)
    {
        printf("Ingresar la velocidad del viento (mayor que 0): ");
        scanf("%d", &(*wA));
        if (*wA <= 0)
        {
            do
            {
                printf("Ingresar una velocidad de viento valida. Debe ser positivo: ");
                scanf("%d", &(*wA));
            } while (*wA <= 0);
        }
    }
    void PedirPrecPluv(int *ppA)
    {
        printf("Ingresar la precipitacion pluvial (de 0 a 1000): ");
        scanf("%d", &(*ppA));
        if (*ppA < 0 || *ppA > 1000)
        {
            do
            {
                printf("Ingresar una precipitacion pluvial valida. Entre 0 y 1000: ");
                scanf("%d", &(*ppA));
            } while (*ppA < 0 || *ppA > 1000);
        }
    }
    int PropEC(Tregdiario reg, int fechaPedida)
    {
        return (reg.ddmmyyyy == fechaPedida && !reg.borrado);
    }
    long int fecha;
    FILE *f;
    Tregdiario regMod, regArch;

    f = fopen(nom, "r+b");
    if (ArchVacio(nom))
    {
        printf("No se puede modificar porque el archivo esta vacio o todos los registro estan borrados.\nVuelve al menu principal. \n");
    }
    else
    {
        printf("¿De que fecha es el registro que quiere modificar?: \n");
        PedirFecha(anioEntry, &fecha);
        do
        {
        } while (fread(&regArch, sizeof(Tregdiario), 1, f) > 0 && !PropEC(regArch, fecha));
        if (PropEC(regArch, fecha))
        {
            fseek(f, (-1) * sizeof(Tregdiario), SEEK_CUR);
            printf("Ingresar la temperatura maxima de la fecha: ");
            PedirTemp(&regMod.tmax);
            printf("Ingresar la temperatura minima de la fecha: ");
            PedirTemp(&regMod.tmin);
            PedirHumedad(&regMod.HUM);
            PedirPresAtm(&regMod.PNM);
            PedirDirViento(&regMod.DV);
            PedirVelocViento(&regMod.FF);
            PedirPrecPluv(&regMod.PP);
            regMod.ddmmyyyy = fecha;
            regMod.borrado = 0;
            fwrite(&regMod, sizeof(Tregdiario), 1, f);
            printf("Modificado con exito \n");
        }
        else
        {
            if (regArch.ddmmyyyy == fecha && regArch.borrado)
            {
                printf("La fecha a modificar esta borrada. \n");
            }
            else
            {
                printf("No se encontro la fecha a modificar. \n");
            }
        }
    }
    fclose(f);
}

void MostrarArchivo(char nom[25])
{
    FILE *f;
    Tregdiario reg;
    int i = 1;

    f = fopen(nom, "r+b");
    if (ArchVacio(nom))
    {
        printf("El archivo esta vacio o todos sus registros estan borrados. \n");
    }
    else
    {
        while (fread(&reg, sizeof(Tregdiario), 1, f) > 0)
        {
            if (!reg.borrado)
            {
                printf("_____________________________\n");
                printf("Registro nro %d: \n", i);
                i++;
                printf("\n");
                printf("Fecha: %ld \n", reg.ddmmyyyy);
                printf("Temperatura maxima: %d \n", reg.tmax);
                printf("Temperatura minima: %d \n", reg.tmin);
                printf("Porcentaje de humedad: %d \n", reg.HUM);
                printf("Presion atmosferica: %d \n", reg.PNM);
                printf("Direccion del viento: %d \n", reg.DV);
                printf("Velocidad del viento: %d \n", reg.FF);
                printf("Precipitacion pluvial: %d \n", reg.PP);
                printf("\n");
                // printf ("reg.borrado = %d \n", reg.borrado);
            }
        }
    }
    fclose(f);
}

int BuscaPosRecursiva(TData registro, int i, int fecha1)
{
    if (i == registro.cant )
    {
        return -1;
    }
    else
    {
        if (registro.a[i].ddmmyyyy == fecha1 && !registro.a[i].borrado)
        {
            return i;
        }
        else
        {
            return BuscaPosRecursiva(registro, i + 1, fecha1);
        }
    }
}

void MostrarDatos_Pos(int i, TData registro)
{
    if (i == -1)
    {
        printf("No se encontro la fecha \n");
    }
    else
    {
        printf("¡Registro encontrado! \n");
        printf("Temp Maxima: %d \n", registro.a[i].tmax);
        printf("Temp Minima: %d \n", registro.a[i].tmin);
        printf("Humedad: %d \n", registro.a[i].HUM);
        printf("Presion atmosferica: %d \n", registro.a[i].PNM);
        printf("Direccion del viento: %d \n", registro.a[i].DV);
        printf("Velocidad de viento: %d \n", registro.a[i].FF);
        printf("Precipitacion anual: %d \n", registro.a[i].PP);
    }
}

void VaciarListaConFict(Tnodo *q)
{
    Tnodo *aux, *aux2;

    aux = q->next;
    aux2 = aux;
    q->next = NULL;
    if (aux != NULL)
    {
        while (aux != NULL)
        {
            aux = aux->next;
            free(aux2);
            aux2 = aux;
        }
    }
}

void MostrarLSETempMax(Tnodo *q)
{
    while (q->next != NULL)
    {
        q = q->next;
        printf("Dia registrado con temp maxima: %ld \n", q->info.ddmmyyyy);
        printf("Temperatura maxima registrada: %d \n", q->info.tmax);
    }
}

void ListarTempMax(char nom[25], Tnodo **s)
{
    FILE *f;
    Tnodo *aux, *nuevo;
    Tregdiario maxima, reg;

    f = fopen(nom, "r+b");
    *s = malloc(sizeof(Tnodo));
    (*s)->next = NULL;
    if (ArchVacio(nom))
    {
        printf("El archivo esta vacio \n");
    }
    else
    {
        do
        {
            fread(&reg, sizeof(Tregdiario), 1, f);
        } while (reg.borrado);
        maxima = reg;
        nuevo = malloc(sizeof(Tnodo));
        nuevo->info = maxima;
        nuevo->next = NULL;
        (*s)->next = nuevo;
        while ( fread(&reg, sizeof(Tregdiario), 1, f) > 0 )
        {
            if (maxima.tmax < reg.tmax && !reg.borrado)
            {
                maxima = reg;
                VaciarListaConFict(*s);
                *s = malloc(sizeof(Tnodo));
                (*s)->next = NULL;
                nuevo = malloc(sizeof(Tnodo));
                nuevo->info = maxima;
                nuevo->next = NULL;
                (*s)->next = nuevo;
            }
            else
            {
                if (maxima.tmax == reg.tmax && !reg.borrado)
                {
                    aux = malloc(sizeof(Tnodo));
                    aux->info = reg;
                    aux->next = NULL;
                    nuevo->next = aux;
                    nuevo = aux;
                }
            }
        }
    }
    fclose(f);
}

void ListarPrecMax(char nom[25])
{
    TData arregloPrecip;
    int i, aux;
    FILE *f;

    f = fopen(nom, "rb");
    if (ArchVacio(nom))
    {
        printf("El archivo esta vacio \n");
    }
    else
    {
        arregloPrecip = ArchArray(nom);
        OrdenarInsertionReves(&arregloPrecip);
        aux = 10;
        for (i = 0; i < aux && i < arregloPrecip.cant; i++)
        {
            if (!arregloPrecip.a[i].borrado)
            {
                printf("Fecha: %ld \n", arregloPrecip.a[i].ddmmyyyy);
                printf("Precipitacion registrada: %d \n", arregloPrecip.a[i].PP);
            }
            else
            {
                aux++;
            }
        }
    }
    fclose(f);
}

void ListarMayMenVelViento(char nom[25])
{
    TData arregloVientos;
    FILE *fA;
    int i, aux;

    fA = fopen(nom, "r+b");

    if (ArchVacio(nom))
    {
        printf("El archivo esta vacio \n");
    }
    else
    {
        arregloVientos = ArchArray(nom);
        OrdenarBubbleReves(&arregloVientos);
        aux = 10;
        for (i = 0; i < aux && i < arregloVientos.cant; i++)
        {
            if (!arregloVientos.a[i].borrado)
            {
                printf("Fecha: %ld \n", arregloVientos.a[i].ddmmyyyy);
                printf("Velocidad del viento registrada: %d \n", arregloVientos.a[i].FF);
            }
            else
            {
                aux++;
            }
        }
    }
    fclose(fA);
}

// Al concatenarse la hora puede que se vean simbolos extranios.
// Una posible solucion seria comentar la línea 938 (strcat(nomArch, hora)).
void CopiaSeguridad(char nom[25])
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char hora[26];
    strftime(hora, sizeof(hora), "%c", tm);
    // hora tiene un formato de hora puesto, de tipo cadena
    FILE *gA, *fOld;
    char nomArch[25], extens[5];
    Tregdiario rA;
    int rta;

    fOld = fopen(nom, "r+b");
    if (ArchVacio(nom))
    {
        printf("El archivo el cual se le realizara la copia de seguridad aun no tiene datos almacenados\n");
    }
    else
    {
        printf("¿Realizar copia de seguridad? Si = 1 / No = 0: ");
        scanf("%d", &rta);
        if (rta)
        {
            printf("Ingresar el nombre del archivo para la copia de seguridad (sin el .dat).\nSe concatenara la hora en que se realizo luego del nombre.\n");
            scanf("%s", nomArch);
            strcat(nomArch, "_");
            strcat(nomArch, hora);
            strcat(extens, ".dat");
            strcat(nomArch, extens);
            gA = fopen(nomArch, "w+b");
            while (fread(&rA, sizeof(Tregdiario), 1, fOld) > 0)
            {
                if (!rA.borrado)
                {
                    fwrite(&rA, sizeof(Tregdiario), 1, gA);
                }
            }
            fclose(gA);
            printf("Copia de seguridad realizada con exito. El archivo se llama: %s\n", nomArch);
        }
        else
        {
            printf("Vuelve al menu principal. \n");
        }
    }
    fclose(fOld);
}

void Verificar(char nom[25], FILE **fA)
{
    Tregdiario aux;

    *fA = fopen(nom, "a+b");
    rewind(*fA);
    fread(&aux, sizeof(aux), 1, *fA);
    if (feof(*fA))
    {
        printf("El archivo %s fue creado. \n", nom);
    }
    else
    {
        printf("Archivo: %s - abierto exitosamente. \n", nom);
    }
    fclose(*fA);
}

void OrdenarInsertionReves(TData *arr)
{
    int i, j;
    Tregdiario aux;

    for (i = 1; i < arr->cant; i++)
    {
        aux = arr->a[i];
        for (j = i - 1; j >= 0 && arr->a[j].PP < aux.PP; j--)
        {
            arr->a[j + 1] = arr->a[j];
        }
        arr->a[j + 1] = aux;
    }
}

void OrdenarBubbleReves(TData *a)
{
    void Intercambiar(Tregdiario * x, Tregdiario * y)
    {
        Tregdiario tmp;
        tmp = *x;
        *x = *y;
        *y = tmp;
    }
    int i, j;

    for (i = 0; i < a->cant; i++)
    {
        for (j = 0; j < (a->cant) - i - 1; j++)
        {
            if (a->a[j].FF < a->a[j + 1].FF)
            {
                Intercambiar(&(a->a[j]), &(a->a[j + 1]));
            }
        }
    }
}

void DesplegarMenuDeOpciones()
{
    printf("\n");
    printf("· Menu principal");
    printf("\n");
    printf("Seleccione una opcion para continuar: \n");
    printf("\t 1. Alta de un registro diario \n");
    printf("\t 2. Suprimir un registro diario \n");
    printf("\t 3. Modificar un registro, se busca por la fecha \n");
    printf("\t 4. Mostrar todos los registros activos \n");
    printf("\t 5. Buscar registro de un dia dado y mostrar todos los parametros \n");
    printf("\t 6. Listar el dia o dias de maxima temperatura en lo que va del anio \n");
    printf("\t 7. Listar el dia o dias de maxima precipitacion en lo que va del anio \n");
    printf("\t 8. Listar las fechas de mayor a menor velocidad de viento \n");
    printf("\t 9. Realizar una copia de seguridad del archivo del anio en curso \n");
    printf("\t 10. Salir \n");
}
