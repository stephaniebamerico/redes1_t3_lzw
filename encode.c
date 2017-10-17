#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEFAULTENTRYSIZE 500
#define LARGERENTRY 10000
#define DICSIZE 100000



char *dic[DICSIZE*2];

int main(int argc, char const *argv[])
{
    char p[LARGERENTRY + 1],aux[LARGERENTRY + 1], c;
    int tam;
    for (int i = 0; i <= DICSIZE; ++i)
    {
        //aloca a mem inicial
        dic[i] = malloc (DEFAULTENTRYSIZE*sizeof(char));
        dic[i][0] = '\0';
        tam = 0;
    }
    p[0]='\0';
    //enquanto não é o fim da entrada  
    while (scanf ("%c", &c ) != EOF)
    {
        //aux = p
        strcpy (aux,p);
        if ((strlen(aux))<LARGERENTRY && tam < DICSIZE)
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
                            printf("%d ", i+128);
                        }
                }
                else 
                {
                    printf("%d ", (int)p[0]);
                }


                if (strlen (aux) > DEFAULTENTRYSIZE)
                    dic[tam] = (char *)realloc (dic[tam], strlen (aux)*sizeof(char));
                strcpy(dic[tam],aux);
                tam++;
                p[0] = c;
                p[1] = '\0';
            }
        }
        else if (tam < DICSIZE)
        {
            if (strlen (p) > 1) 
                {
                    int print = 0;
                    for (int i = 0; i < tam && !print; ++i)
                        if (strcmp(p,dic[i]) == 0)
                        {
                            print = 1;
                            printf("%d ", i+128);
                        }
                }
                else 
                {
                    printf("%d ", (int)p[0]);
                }


                if (strlen (aux) > DEFAULTENTRYSIZE)
                    dic[tam] = (char *)realloc (dic[tam], strlen (aux)*sizeof(char));
                strcpy(dic[tam],aux);
                tam++;
                p[0] = c;
                p[1] = '\0';

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
                            printf("%d ", i+128);
                        }
                }
                else 
                {
                    printf("%d ", (int)p[0]);
                }
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
                printf("%d", i+128);
            }
    }
    else 
        printf("%d", (int)p[0]);
      
    printf("\n");


    return 0;
}