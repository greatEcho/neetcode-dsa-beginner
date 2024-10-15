#include <cassert>

struct Solution {
  unsigned int numComb(unsigned n) {
    if (n < 3) return n;
    return numComb(n-2) + numComb(n-1);
  }
};

int main(void)
{
  Solution stairs;
  assert( stairs.numComb(3) == 3 );
  assert( stairs.numComb(4) == 5 );
  assert( stairs.numComb(5) == 8 );
  assert( stairs.numComb(10) == stairs.numComb(8) + stairs.numComb(9) );
}
