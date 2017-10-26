#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<dlfcn.h>
#include"support.h"

/* load_and_invoke() - load the given .so and execute the specified function */
void load_and_invoke(char *libname, char *funcname)
{
    //printf("%s:%s\n",libname,funcname);
    /* TODO: complete this function */

    void *dynamic;
    dynamic = dlopen(libname,RTLD_LAZY);;
    void* (*dynFunction)(void*);
    if(!dynamic)
    {
        printf("%s",dlerror());
        exit(1);
    }

    dynFunction = dlsym(dynamic, funcname);
    if(dlerror() != NULL)
    {
        printf("%s",dlerror());
        exit(1);
    }
    (*dynFunction)(NULL);
    dlclose(dynamic);


return;

}

/* help() - Print a help message. */
void help(char *progname)
{
    printf("Usage: %s [OPTIONS]\n", progname);
    printf("Load the given .so and run the requested function from that .so\n");
    printf("  -l [string] The name of the .so to load\n");
    printf("  -f [string] The name of the function within that .so to run\n");
}


/* main() - The main routine parses arguments and invokes hello */
int main(int argc, char **argv)
{
    /* for getopt */
    long opt;

    //holds library and function
     char* library = NULL;
     char* function = NULL;

    /* run a student name check */
    check_team(argv[0]);

    /* parse the command-line options. For this program, we only support */
    /* the parameterless 'h' option, for getting help on program usage.  */
    while((opt = getopt(argc, argv, "hlf")) != -1)
    {

        //Add cases for l and f and two char* to hold respective arguments
        switch(opt)
        {
        case 'h':   help(argv[0]);  break;
        case 'l':   library =argv[optind]; break;
        case 'f':   function =argv[optind]; break;

        }

    }

    /* call load_and_invoke() to run the given function of the given library */
    load_and_invoke(library, function);

    exit(0);

	}