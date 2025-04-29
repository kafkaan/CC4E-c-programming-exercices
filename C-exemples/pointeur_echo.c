#include <stdio.h>
#include <string.h>
main(int argc,char *argv[]) 
/* echo arguments; 3rd version */
{
  while (--argc > 0)
    printf((argc > 1) ? "%s " : "%s\n", *++argv);
}