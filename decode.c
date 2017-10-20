#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LARGERENTRY 1000

#define DICTYPE 256

#define DICSIZE 10000


char *dic[DICSIZE+2];

int main(int argc, char const *argv[])
{
    setvbuf (stdout, 0, _IONBF, 0) ;
    int old, new, tam = 0, len;
    char s[LARGERENTRY+1], aux[LARGERENTRY+1],c = '\0';

    for (int i = 0; i <= DICSIZE; ++i)
    {
        //aloca a mem inicial
        dic[i] = malloc (LARGERENTRY*sizeof(unsigned char));
        dic[i][0] = '\0';
    }

    scanf("%d", &old);
    printf("%c",(char)old );
    c = (char)old;
    while (scanf("%d", &new) != EOF)
    {
        if (strlen(aux) < LARGERENTRY)
        {
            int isInDic = 0;
            if (new < DICTYPE)
            {
                isInDic = 1;
                s[0] = (char)new;
                s[1] = '\0';
            }
            else
                if (tam > new - DICTYPE)
                    isInDic = 1;
            if (isInDic)
            {
                if ( !(new < DICTYPE) && tam > new - DICTYPE)
                    strcpy(s, dic[new - DICTYPE]);
            }
            else
            {
                strcpy(s, dic[old - DICTYPE]);
                len = strlen (s);
                s[len] = c;
                s[len+1] = '\0';
            }
            printf("%s",s );
            
            c = s[0];
            // aux = translation of old
            if (old >= DICTYPE) 
            {
                strcpy (aux,dic[old - DICTYPE]);
            }

            else
            {
                aux[0] = (char)old;
                aux[1] = '\0';
            }
            len = strlen (aux);
            //aux = aux + c
            aux[len] = c;
            aux[len+1] = '\0';
            //add old + c to the dic

            strcpy (dic[tam],aux);
            tam++;
            old = new;

        }
        
    }
    return 0;
}

