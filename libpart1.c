#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include"support.h"

/* hello() - print some output so we know the shared object loaded.
 *
 * The function signature takes an untyped parameter, and returns an untyped
 * parameter. In this way, the signature *could* support any behavior, by
 * passing in a struct and returning a struct. */
void *hello(void *input)
{
    printf("hello from a .so\n");
    return NULL;
}

/*
Convert method to convert names and emails to uppercase
*/
void  convert(char *field)
{
//implement convert method
    int count = 0;
    while(field[count] != '\0')
    {
        if((field[count]>='a')&&(field[count]<='z'))
        {
            field[count] = field[count] -32;
        }
        count++;
    }
    return;
}


/*ucase()
- takes address in teamstruct as  parameter
-copies the fields of the parameter to the fields of new team struct
*/
void *ucase(struct team_t *inputTeam)
{
    struct team_t *newTeam =malloc(sizeof(struct team_t));
    char n1[strlen(inputTeam->name1)];
    strcpy(n1,inputTeam->name1);
    char n2[strlen(inputTeam->name2)];
    strcpy(n2,inputTeam->name2);
    char n3[strlen(inputTeam->name3)];
    strcpy(n3,inputTeam->name3);
    char e1[strlen(inputTeam->email1)];
    strcpy(e1,inputTeam->email1);
    char e2[strlen(inputTeam->email2)];
    strcpy(e2,inputTeam->email2);
    char e3[strlen(inputTeam->email3)];
    strcpy(e3,inputTeam->email3);
    convert(n2);
    convert(n1);
    convert(n3);
    convert(e1);
    convert(e2);
    convert(e3);

    newTeam->name1 = n1;
    newTeam->name2 = n2;
    newTeam->name3 = n3;
    newTeam->email1 = e1;
    newTeam->email2 = e2;
    newTeam->email3 = e3;

    printf("Student1: %s\nEmail1: %s\nStudent2: %s\nEmail2: %s\nStudent3: %s\nEmail3: %s\n",n1,e1,n2,e2,n3,e3);
    return newTeam;


}

