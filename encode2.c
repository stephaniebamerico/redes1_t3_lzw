#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//maior demora muito pra alocar
#define DEFAULTENTRYSIZE 5
//a partir de alguns valores nao precisa mais aumentar
#define LARGERENTRY 1000
//10000 é um tam bom mas demora
//1000000 é impossível
#define DICSIZE 100000
#define DICTYPE 256


unsigned char *dic[DICSIZE+2];

int main(int argc, char const *argv[])
{
    unsigned char p[LARGERENTRY + 1],aux[LARGERENTRY + 1], c;
    int tam = 0;
    for (int i = 0; i <= DICSIZE; ++i)
    {
        //aloca a mem inicial
        dic[i] = malloc (DEFAULTENTRYSIZE*sizeof(unsigned char));
        dic[i][0] = '\0';
    }
    p[0]='\0';
    int k =0;
    //enquanto não é o fim da entrada  
    while (scanf ("%c", &c ) != EOF)
    {
        //aux = p
        strcpy (aux,p);
        if ((strlen(aux))<LARGERENTRY)
        {
            int isInDic = 0;
            //aux = p + c
            int len = (strlen(aux));
            aux[len+1] = '\0';
            aux[len] = c;
            if (strlen (aux) > 1)
                for (int i = 0; i < tam && !isInDic; ++i)
                {
                    if (strcmp(aux,dic[i]) == 0)
                        isInDic = 1;
                }
            else
                isInDic = 1;
            // p + c está no dicionátio
            if (isInDic)
            {
                //p = p + c
                strcpy (p,aux);
            }
            else
            {
                //imprime P
                int print = 0;
                if (strlen (p) > 1) 
                {
                    for (int i = 0; i < tam && !print; ++i)
                        if (strcmp(p,dic[i]) == 0)
                        {
                            print = 1;
                            printf("%x ", i+DICTYPE);
                        }
                }
                else 
                {
                    printf("%x ", (int)p[0]);
                }
                if (tam < DICSIZE)
                {
                    if (strlen (aux) > DEFAULTENTRYSIZE)
                        dic[tam] = (unsigned char *)realloc (dic[tam], strlen (aux)*sizeof(unsigned char));
                    strcpy(dic[tam],aux);
                    tam++;
                }
                p[0] = c;
                p[1] = '\0';
            }
        }
        else
        {
            if (strlen (p) > 1) 
                {
                    int print = 0;
                    for (int i = 0; i < tam && !print; ++i)
                        if (strcmp(p,dic[i]) == 0)
                        {
                            print = 1;
                            printf("%x ", i+DICTYPE);
                        }
                }
                else 
                {
                    printf("%x ", (int)p[0]);
                }


                if (strlen (aux) > DEFAULTENTRYSIZE)
                    dic[tam] = (unsigned char *)realloc (dic[tam], strlen (aux)*sizeof(unsigned char));
                strcpy(dic[tam],aux);
                tam++;
                p[0] = c;
                p[1] = '\0';

        }

    }

    if (strlen (p) > 1) 
    {
        int print = 0;
        for (int i = 0; i < tam && !print; ++i)
            if (strcmp(aux,dic[i]) == 0)
            {
                print = 1;
                printf("%x", i+DICTYPE);
            }
    }
    else 
        printf("%x", (int)p[0]);
      
    printf("\n");
    for (int i = 0; i <= DICSIZE; ++i)
    {
        //aloca a mem inicial
        free(dic[i]);
    }


    return 0;
}