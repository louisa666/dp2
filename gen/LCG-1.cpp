// LCG-1 seed numbytes

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
//#include <io.h>

const unsigned int a = 1664525, c = 1013904223;

int main (int argc, char* argv[])
  {
  unsigned int x;
  int n;
  x = atoi (argv[1]);
  n = atoi (argv[2]);
 // _setmode(_fileno(stdout), _O_BINARY);
  for (; n > 0; n -= 1) 
    {
	x = a * x + c;
 //   putchar((char) x),
 //   putchar((char) (x >> 8)),
    putchar((char) (x >> 16));
//    putchar((char) (x >> 24));
	}
  return 0;
  }
