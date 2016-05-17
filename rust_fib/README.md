Rust Fibonacci
==============

This project produces a binary that calculates the Fibonacci sequense:

## Build

    $ cargo build
       Compiling rust_fib v0.1.0 (file:///Users/uwe/workspace/rust-experiments/rust_fib)

## Usage

    $ target/debug/rust_fib
    Usage: fib <n>

    $ target/debug/rust_fib 1
    fib(1) = 1
    $ target/debug/rust_fib 2
    fib(2) = 1
    $ target/debug/rust_fib 3
    fib(3) = 2
    $ target/debug/rust_fib 4
    fib(4) = 3
    $ target/debug/rust_fib 5
    fib(5) = 5

## File sizes

### Debug build

    $ cargo build
      Compiling rust_fib v0.1.0 (file:///Users/uwe/workspace/rust-experiments/rust_fib)
    $ ll target/debug/rust_fib
    -rwxr-xr-x  1 uwe  staff  357516 May 17 19:40 target/debug/rust_fib

### Build for release

    $ cargo build --release
       Compiling rust_fib v0.1.0 (file:///Users/uwe/workspace/rust-experiments/rust_fib)
    $ ll target/release/rust_fib
    -rwxr-xr-x  1 uwe  staff  308460 May 17 19:47 target/release/rust_fib


### Prefer dynamic

    $ rustc -C prefer-dynamic -o target/rust_fib src/main.rs
    $ ll target/rust_fib
    -rwxr-xr-x  1 uwe  staff  42636 May 17 19:45 rust_fib


## Performance

### Debug build

    $ time target/debug/rust_fib 48
    fib(48) = 4807526976

    real	0m37.258s
    user	0m37.204s
    sys	0m0.020s

### Prefer dynamic

    $ time target/rust_fib 48
    fib(48) = 4807526976

    real	0m37.859s
    user	0m37.792s
    sys	0m0.031s

### Release build

    $ cargo build --release
       Compiling rust_fib v0.1.0 (file:///Users/uwe/workspace/rust-experiments/rust_fib)
    $ time target/release/rust_fib 48
    fib(48) = 4807526976

    real	0m10.458s
    user	0m10.420s
    sys	0m0.019s
