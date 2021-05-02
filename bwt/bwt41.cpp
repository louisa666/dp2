#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
//#include <io.h>
#include <time.h>
#include <algorithm>
#include <unistd.h>
const int MaxSize = 10000000;
unsigned char M [MaxSize]; // message
int *X;  // index
int n;  // actual size, n <= MaxSize
int P = 1; // position of initial char
int C = 0;

int Less (int _i, int _j)
  {
  int i = _i, j = _j;
  int k = n - 1;
  i += k; if (i >= n) i -= n;
  j += k; if (j >= n) j -= n;
C++;
  do
    {
    k--;
    i--; if (i < 0) i += n;
    j--; if (j < 0) j += n;
    }
  while ((M[i] == M[j]) && (k > 0));
  if (M[i] < M[j]) return 1;
  else return 0;
  }

int LessEq (int _i, int _j)
  {
  int i = _i, j = _j;
  int k = n - 1;
  i += k; if (i >= n) i -= n;
  j += k; if (j >= n) j -= n;
C++;
  do
    {
    k--;
    i--; if (i < 0) i += n;
    j--; if (j < 0) j += n;
    }
  while ((M[i] == M[j]) && (k > 0));
  if (M[i] <= M[j]) return 1;
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
  int i, j, x, m;
//fprintf (stderr, "L = %d  R = %d\n", L, R);
  if ((R - L) <= 56) // insertion sort
    {
    for (i = L + 1; i <= R; i++)
      {
      x = X[i], j = i - 1;
      while ((j >= 0) && (Less (x, X[j]))) X[j+1] = X[j], j--;
      X[j+1] = x;
      }
  	return;
    }
  while (L < R)
    {
    m = (L + R) / 2;
    if (Less (X[m], X[L])) std::swap (X[L], X[m]);
    if (Less (X[R], X[L])) std::swap (X[L], X[R]);
    if (Less (X[m], X[R])) std::swap (X[R], X[m]);
    x = X[R];
	i = L - 1;
    for (j = L; j < R; j++)
      if (LessEq (X[j], x)) i++, std::swap(X[i], X[j]);
    std::swap(X[i + 1], X[R]); // left: L..i, right: i+2..R
    if ((i - L) > (R - (i+2))) 
	  {
	  if ((i+2) < R) QSort (i+2, R);
	  R = i;
	  }
    else 
	  {
	  if (L < i) QSort (L, i);
	  L = i+2;
	  }
    }
  }

int main (int argc, char *argv[])
  {
  int i, j;
  int t1, t2;
  //_setmode(_fileno(stdout), _O_BINARY);
 // _setmode(_fileno(stdin), _O_BINARY);
  n = 0;
  while (i = read (0, M, MaxSize - n)) n += i;
  fprintf (stderr, "n = %d\n", n);
  X = new int[n];
  fprintf (stderr, "X = %x\n", X);
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
  fprintf (stderr, "...qsort t = %d C = %d\n", t2 - t1, C);
//  printf ("\n");

/*
  for (i = 0; i < n; i++) 
    {
    for (j = 0; j < n; j++) printf ("%c", M[(X[i] + j) % n]);
    printf ("\n");
    }
*/
  
  for (i = 0; i < n; i++) printf ("%c", M[(X[i] + n - 1) % n]);
  fprintf (stderr, "P = %d\n", P);


//  getchar ();
  return EXIT_SUCCESS;
  }


