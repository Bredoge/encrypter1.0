#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct lett_num
{
 char letter[2];
 int num;
};

char nword[20];

struct lett_num alp[26];

void dbread(void)
{
    FILE* fp;
	int rep;

	fp = fopen("alphabet.txt", "r");

	if(fp == NULL)
    {
        printf("Error with opening file");
        exit(1);
    }

    for (rep = 0; rep <= 50; rep++)
	{
        if(feof(fp))
        {
            break;
        }
		fscanf(fp, "%d", &alp[rep].num);
		fscanf(fp, "%s", alp[rep].letter);
	}

	fclose(fp);
};

int swap(int i, int move, int word)
{
    int rep=0;
    for(; rep < 26; rep++)
    {
        if(alp[rep].letter[0] == word)
        {
            nword[i] = alp[rep + move].letter[0];
            break;
        }
    }
}

void caesar(void)
{
    int rep=0, i=0, move, word;
    printf ("displacement: ");
    scanf ("%d", &move);
    while(getchar() != 10);
    printf("word / sentence: ");
    for(i < 20; ; i++)
    {
        word = getchar();

        if (word == 10)
        {
            /*for(; rep < i ; rep++)*/
            printf("encrypted text: %s", nword);
            break;
        }

        if (word == ' ')
        {
            nword[i] = ' ';
        }
        else
        {
            swap(i, move, word);
        }


    }
    while(getchar() != 10);
}

void list(void)
{
    int rep;
    for(rep = 0; rep < 26;rep++)
    {
        printf("%s - ", alp[rep].letter);
        printf("%d\n", alp[rep].num);
    }
}

int main()
{
    int ln=0;
    char command;
    dbread();

    while (1)
    {
        printf ("q - quit\n");
        printf ("c - caesar cypher\n");
        printf ("l - list\n");
        printf ("\n");
        ln = 0;
        printf("> ");
        command = getchar();
        printf("\n");

        if(command != 10)
            while(getchar() != 10);

        if(command == 'q')
        {
            exit(0);
        }

        else if (command == 'c')
        {
            caesar();
            ln = 1;
        }

        else if(command == 'l')
        {
            list();
            ln = 1;
        }

        if(ln == 1)
            printf("\n");
        command = 0;
    }

}
