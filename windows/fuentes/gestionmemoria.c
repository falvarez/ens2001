/*gestionmemoria.c*/
#include "gestionmemoria.h"

int memoria[MAXINT+1]; /*Memoria*/
int codigo1; /*Limite inferior del codigo*/
int codigo2; /*Limite superior del codigo*/
/*-------------------------------------------------------------------------*/
int EscribirMemoria(int direccion,int valor)
{
    if(direccion<MININT || direccion>MAXINT)
    {
        return -1;
    }
    else if(valor<MININT || valor>MAXINT)
    {
    	return -1;
    }
    else
    {
        memoria[direccion]=valor;
        /*Actualizamos limites*/
        if(direccion<=codigo1)
        {
            codigo1=direccion;
        }
        if(direccion>=codigo2)
        {
            codigo2=direccion;
        }
        return 0;
    }
}
/*-------------------------------------------------------------------------*/
int InicializarMemoria(void)
{
    int i;

    for(i=0;i<(MAXINT+1);i++)
    {
        memoria[i]=0;
    }
    codigo1=MAXINT;
    codigo2=0;
    return 0;
}
/*-------------------------------------------------------------------------*/
int LeerMemoria(int direccion)
{
    if(direccion<MININT || direccion>MAXINT)
    {
        return -1;
    }
    else
    {
        return memoria[direccion];
    }
}
/*-------------------------------------------------------------------------*/
int VolcarMemoria(char *nombrefichero,int *inicio,int *fin)
{
    int i;
    int valorretorno;
    int elementosescritos;
    unsigned char fichero[(MAXINT+1)*2];
    FILE *fd;

    valorretorno=0;
    fd=fopen(nombrefichero,"wb");
    if(fd!=NULL)
    {
        for(i=0;i<(MAXINT+1);i++)
        {
            fichero[2*i]=memoria[i]/256;
            fichero[(2*i)+1]=memoria[i]%256;
        }
        elementosescritos=fwrite(fichero,sizeof(unsigned char),(MAXINT+1)*2,fd);
        fclose(fd);
        *inicio=codigo1;
        *fin=codigo2;
        if(elementosescritos!=(MAXINT+1)*2)
        {
            /*No se ha escrito correctamente el fichero*/
            remove(nombrefichero);
            valorretorno=-1;
        }
    }
    else
    {
      *inicio=0;
      *fin=0;
      valorretorno=-1;
    }
    return valorretorno;
}
/*-------------------------------------------------------------------------*/
