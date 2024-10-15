#include <cassert>


int fibonacciLoop(int n)
{
  int first = 0, second = 1, tmp;
  for (int i=1; i<n; ++i) {
    tmp = first + second;
    first = second;
    second = tmp;
  }
  return second;
}

int fibonacciRecursion(int n)
{
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fibonacciRecursion(n-1) + fibonacciRecursion(n-2);
}

int main(void)
{
  assert(fibonacciRecursion(5) == 5);
  assert(fibonacciRecursion(6) == 8);
  assert(fibonacciRecursion(5) == fibonacciLoop(5));
  assert(fibonacciRecursion(6) == fibonacciLoop(6));
  assert(fibonacciRecursion(7) == fibonacciLoop(7));
  assert(fibonacciRecursion(8) == fibonacciLoop(8));
}
