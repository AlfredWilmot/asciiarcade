#include <stdio.h>

/*Simply print input params as a single column; a noddy echo*/
int main(int argc, char **argv)
{
  for (int i=1; i < argc; i++) {
    printf("%s\n", argv[i]);
  }
}
