#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long rust_fib(int n);

long c_fib(int n) {
  if (n <= 2) {
    return 1;
  }
  return c_fib(n - 2) + c_fib(n - 1);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: fib <n>\n");
    return 1;
  }
  int n = atoi(argv[1]);
  printf("fib(%d) = %ld\n", n, c_fib(n));
  return 0;
}
