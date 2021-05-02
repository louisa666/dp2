#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctime>
#include <unistd.h>
//#include <io.h>

const int MaxSize = 10000000;
unsigned char M [MaxSize]; // message
int *X;  // index
int n;  // actual size, n <= MaxSize
int P = 1; // position of initial char

int Less (int i, int j)
  {
  register int k = n - 2;
  while ((M[(i + k) % n] == M[(j + k) % n]) && (k > 0)) k--;
  if (M[(i + k) % n] < M[(j + k) % n]) return 1;
  else return 0;
  }

void Swap (int i, int j)
  {
  int t;
  t = X[i], X[i] = X[j], X[j] = t;
  if (i == P) P = j;
  else if (j == P) P = i;
  }

void QSort (int L, int R)
  {
  int i, j, x, t;
  while (L < R)
    {
    x = X[L], i = L, j = R;
    while (i <= j)
      {
      while (Less (X[i], x)) i++;
      while (Less (x, X[j])) j--;
      if (i <= j) Swap (i, j), i++, j--;
      }
    if ((j - L) > (R - i)) 
	  {
	  if (i < R) QSort (i, R);
	  R = j;
	  }
    else 
	  {
	  if (L < j) QSort (L, j);
	  L = i;
	  }
    }
  }

int main (int argc, char *argv[])
  {
  int i, j;
  int t1, t2;
  //_setmode(_fileno(stdout), _O_BINARY);
  //_setmode(_fileno(stdin), _O_BINARY);
  
  
 n = read (0, M, MaxSize);
  fprintf (stderr, "n = %d\n", n);
  X = new int[n];
  for (i = 0; i < n; i++) X[i] = i;
  
/*
  for (i = 0; i < n; i++) 
    {
    for (j = 0; j < n; j++) printf ("%c", M[(i + j) % n]);
    printf ("\n");
    }
*/
  fprintf (stderr, "qsort...\n"); 
  t1 = time (0);
  QSort (0, n-1);
  t2 = time (0);
  fprintf (stderr, "...qsort t = %d\n", t2 - t1);
//  printf ("\n");

/*
  for (i = 0; i < n; i++) 
    {
    for (j = 0; j < n; j++) printf ("%c", M[(X[i] + j) % n]);
    printf ("\n");
    }
*/
  
  for (i = 0; i < n; i++) printf ("%c", M[(X[i] + n - 1) % n]);
//  printf ("\nP = %d\n", P);


//  getchar ();
  return EXIT_SUCCESS;
  }


