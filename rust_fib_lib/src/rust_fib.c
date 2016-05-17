#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long rust_fib(int n);

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: fib <n>\n");
    return 1;
  }
  int n = atoi(argv[1]);
  printf("fib(%d) = %ld\n", n, rust_fib(n));
  return 0;
}
