#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//maior demora muito pra alocar
#define DEFAULTENTRYSIZE 5
#define DEFAULTCOLLISION 10
//a partir de alguns valores nao precisa mais aumentar
#define LARGERENTRY 4096
//10000 é um tam bom mas demora
//1000000 é impossível
#define DICSIZE 100000
#define DICTYPE 256

typedef struct lzw_t
{
    char* entry;
    int position;
}lzw_t;

lzw_t **dic[LARGERENTRY+2];
int collisions[LARGERENTRY+2];
int *output;

int findPosition(char *a)
{
    
    unsigned long soma = 0;
    for (int i = 0; a[i] != '\0'; ++i)
    {

        soma+=a[i];
    }
    soma%=LARGERENTRY;
    
    int i;
    for (i = 0; i < collisions[soma] && dic[soma][i]->entry[0] != '\0' && strcmp(dic[soma][i]->entry,a); ++i);
        
    if (i < collisions[soma] && !strcmp(dic[soma][i]->entry,a))
    {
        
        return dic[soma][i]->position;
    }
    return -1;
}

void updadeDic(char *a, int pos)
{
    
    unsigned long soma = 0;
    for (int i = 0; a[i] != '\0'; ++i)
        soma+=a[i];
    soma%=LARGERENTRY;
    int i;
    for (i = 0; i < collisions[soma] && dic[soma][i]->entry[0] != '\0'; ++i)
    {
    }

    if (i == collisions[soma])
    {

        dic[soma] =  realloc (dic[soma],2*collisions[soma]*sizeof(lzw_t));
        for (int j = collisions[soma]; j < 2*collisions[soma]; ++j)
        {
            dic[soma][j] = malloc(sizeof(lzw_t));
            dic[soma][j]->entry = malloc (DEFAULTENTRYSIZE * sizeof (char));
            dic[soma][j]->entry[0] = '\0';
        }
        
        collisions[soma]=2*collisions[soma];
    }
    int len;
    if (len = strlen(a) > LARGERENTRY)
    {
        dic[soma][collisions[soma]]->entry = realloc(dic[soma][collisions[soma]]->entry, len*sizeof(char));

    }
    strcpy(dic[soma][i]->entry, a);

    dic[soma][i]->position = pos;

}

int main(int argc, char const *argv[])
{
    unsigned char p[LARGERENTRY + 1],aux[LARGERENTRY + 1], c;
    int tam = 0, pos;
    for (int i = 0; i <= LARGERENTRY; ++i)
    {
        //aloca a mem inicial
        dic[i] = malloc (DEFAULTCOLLISION*sizeof(lzw_t)*2);
        collisions[i] = 5;
        for (int j = 0; j < DEFAULTCOLLISION; ++j)
        {
            dic[i][j] = malloc(sizeof(lzw_t));
            dic[i][j]->entry = malloc (DEFAULTENTRYSIZE * sizeof (char));
            dic[i][j]->entry[0] = '\0';
        }
    }
    output = malloc (LARGERENTRY * sizeof (int));
    int outSize = LARGERENTRY;
    p[0]='\0';
    int k =0;
    aux[0] = '\0';
    int x = 0;
    //enquanto não é o fim da entrada  
    while (scanf ("%c", &c ) != EOF)
    {
        if (x >= outSize-1)
        {
            outSize = outSize*2;
            output = realloc (output, outSize*sizeof(int));
        }
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
            {
                
                if (findPosition(aux) != -1)
                {
                    isInDic = 1;
                }
            }

            else
            {
                isInDic = 1;
            }
            // p + c está no dicionátio
            if (isInDic)
            {  

                //p = p + c
                strcpy (p,aux);
            }
            else
            {

                //imprime P
                if (strlen (p) > 1) 
                {
                    pos = findPosition(p);            
                    output[x] = pos + DICTYPE;
                    x++;
                }
                else 
                {                    
                    output[x] = (int)p[0];
                    x++;
                }
                if (tam < DICSIZE)
                {
                    updadeDic(aux, tam);
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
                    pos = findPosition(p);            
                    output[x] = pos + DICTYPE;
                    x++;
                }
                else 
                {                    
                    output[x] = (int)p[0];
                    x++;
                }


                if (tam < DICSIZE)
                {
                    updadeDic(aux, tam);
                    tam++;
                }
                p[0] = c;
                p[1] = '\0';

        }

    }

    if (strlen (p) > 1) 
    {

        pos = findPosition(p);
        output[x] = pos + DICTYPE;
        x++;
    }
    else
    {        
        output[x] = (int)p[0];
        x++;
    }
      
    FILE *fp, *faux;

    fp = fopen( "compressed" , "w" );
    faux = fopen( "tmp", "w");
    fprintf(faux,"%d\n",x );

    fwrite(output , x , sizeof(int) , fp );
    for (int i = 0; i <= LARGERENTRY; ++i)
    {
        //aloca a mem inicial
        free(dic[i]);
    }


    return 0;
}