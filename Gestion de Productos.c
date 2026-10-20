#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char Descrip[30];
    float PrecioU;
    int UnidadesV;
    float TotalRec;
} Productos;

int IngreseEnteroVal(int,int);
float IngreseRealVal(float,float);
int CargaProd(Productos[],int);
int Busqueda(Productos[],int,int);
void ProcesarVentas(Productos[],int);
void Informe(Productos[],int,float*);

int main()
{
    Productos VecP[80];
    int ce;
    float *Resumen=NULL;
    ce = CargaProd(VecP,80);
    ProcesarVentas(VecP,ce);
    Informe(VecP,ce,Resumen);
    return 0;
}

int IngreseEnteroVal(int min, int max)
{
    int dato;
    do
    {
        printf(" Entero (entre %d y %d): ",min,max);
        scanf("%d",&dato);
        if (dato<min||dato>max)
            printf("Dato invalido\n");
    }while(!(dato>=min&&dato<=max));
    return dato;
}

float IngreseRealVal (float min, float max)
{
    float dato;
    do
    {
        printf(" Real (entre %.2f y %.2f): ",min,max);
        scanf("%f",&dato);
        if (dato<min||dato>max)
            printf("\nDato invalido");
    }while(!(dato>=min&&dato<=max));
    return dato;
}

int CargaProd(Productos v[],int max)
{
    int cod,i=0;
    printf("\nIngrese el codigo del producto (0 para terminar)");
    cod=IngreseEnteroVal(0,999);
    while(i<max && cod!=0)
    {
        if(Busqueda(v,i,cod)!=-1)
        {
            printf("\nEl codigo %d ya existe, ingrese otro",cod);
        }
        else
        {
            v[i].codigo=cod;
            printf("\nIngrese la descripcion del producto: ");
            getchar();
            fgets(v[i].Descrip,30,stdin);
            v[i].Descrip[strcspn(v[i].Descrip, "\n")] = '\0';
            printf("\nIngrese el Precio Unitario ");
            v[i].PrecioU=IngreseRealVal(1.00,100.00);
            printf("\nIngrese las Unidades Vendidas ");
            v[i].UnidadesV=IngreseEnteroVal(0,1000);
            v[i].TotalRec=v[i].PrecioU*v[i].UnidadesV;
            i++;
        }
        printf("\nIngrese el codigo del producto (0 para terminar)");
        cod=IngreseEnteroVal(0,999);
    }
    return i;
}

int Busqueda(Productos vC[],int ce,int datoabuscar)
{
    int pos=-1,i=0;
    while(pos==-1 && i<ce)
    {
        if(vC[i].codigo==datoabuscar)
        {
            pos=i;
        }
        else
            i++;
    }
    return pos;
}

void ProcesarVentas(Productos VectorCargado[],int ce)
{
    int pos,UniV,cod;
    printf("\nIngrese la cantidad vendida a actualizar(0 si no desea actualizar nada) ");
    UniV=IngreseEnteroVal(0,1000);
    while(UniV!=0)
    {
        printf("\nIngrese el codigo del producto a actualizar ");
        cod=IngreseEnteroVal(0,999);
        pos=Busqueda(VectorCargado,ce,cod);
        if(pos==-1)
        {
            printf("\nProducto no encontrado");
        }
        else
        {
            VectorCargado[pos].UnidadesV += UniV;
            VectorCargado[pos].TotalRec += (UniV * VectorCargado[pos].PrecioU);
        }
        printf("\nIngrese la cantidad vendida a actualizar(0 para terminar) ");
        UniV=IngreseEnteroVal(0,1000);
    }
}

void Informe(Productos VecP[],int ce,float* Resumen)
{
    int i=0;
    Resumen=(float*)malloc(ce*sizeof(float));
    if(Resumen==NULL)
    {
        printf("\nError al reservar memoria...");
        exit(1);
    }
    for(i=0;i<ce;i++)
    {
        Resumen[i]=VecP[i].TotalRec;
    }
    printf("\n=====TOTAL RECAUDADO=====");
    printf("\n%-12s | %-30s | %-17s | %10s", "Producto", "Descripcion", "Unidades Vendidas", "Total");
    for(i=0;i<ce;i++)
    {
        printf("\nProducto %3d | %-30s | %17d | %10.2f",i + 1, VecP[i].Descrip, VecP[i].UnidadesV, VecP[i].TotalRec);
    }
    printf("\n");
    free(Resumen);
}
