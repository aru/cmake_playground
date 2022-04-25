#include "big_library.h"

int main() {
  int a = 1, b = 1;
  int c = 0;
  a = aru_no_deps_mod(c, b);
  b = aru_no_deps_sub(b, c);
  c = aru_no_deps_div(a, b);
  return c;
}