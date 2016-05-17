Rust Fibonacci
==============

This project produces two binaries which calculate the Fibonacci sequence.

The first binary (`target/c_fib`) is built from C source (`src/fib.c`).

The second binary (`target/c_rust_fib`) is built from a C-source (`src/rust_fib.c`),
but then linked to a Rust library which performs the actual calculation.

## Build

### Pure C

    $ gcc -L target/release -lrust_fib_lib -o target/c_fib src/fib.c

### Rust from C

    $ cargo build --release
      Compiling fib_lib v0.1.0 (file:///Users/uwe/workspace/rust-experiments/rust_fib_lib)
    $ gcc -L target/release -lrust_fib_lib -o target/c_rust_fib src/rust_fib.c

## Usage

### Pure C

    $ target/c_fib
    Usage: fib <n>
    $ target/c_fib 5
    fib(5) = 5
    $ target/c_fib 6
    fib(6) = 8
    $ target/c_fib 7
    fib(7) = 13

### Rust from C

    $ target/c_rust_fib
    Usage: fib <n>
    $ target/c_rust_fib 5
    fib(5) = 5
    $ target/c_rust_fib 6
    fib(6) = 8
    $ target/c_rust_fib 7
    fib(7) = 13

## File sizes

### Pure C binary

    $ ll target/c_fib
    -rwxr-xr-x  1 uwe  staff  8512 May 17 20:26 target/c_fib

### Rust from C

    $ ll target/c_rust_fib
    -rwxr-xr-x  1 uwe  staff  8528 May 17 20:28 target/c_rust_fib
    $ ll target/release/librust_fib_lib.dylib
    -rwxr-xr-x  1 uwe  staff  1758616 May 17 20:25 target/release/librust_fib_lib.dylib


## Performance

### Pure C

    $ time target/c_fib 48
    fib(48) = 4807526976

    real	0m21.133s
    user	0m21.098s
    sys	0m0.017s

### Rust from C

    $ time target/c_rust_fib 48
    fib(48) = 4807526976

    real	0m10.526s
    user	0m10.503s
    sys	0m0.011s
