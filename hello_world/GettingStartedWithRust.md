Getting Started With Rust
=========================

## Documentation

* https://www.rust-lang.org/
* https://github.com/kud1ing/awesome-rust

## History

Created by Mozilla.
Version 1.0.0 (2015-05-15)
Version 0.1 (2012-01-20)

## Installation

### Mac

    brew cask install rust

## Hello World

    $ echo 'fn main() {println!("Hello, world!")}' > hello_world.rs
    $ rustc hello_world.rs
    $ ./hello_world
    Hello, world!

### In a project

    $ cargo new hello_world --bin
    $ cd hello_world
    $ tree
    .
    ├── Cargo.toml
    └── src
        └── main.rs

    1 directory, 2 files

    $ cat src/main.rs
    fn main() {
        println!("Hello, world!");
    }

    $ cat Cargo.toml
    [package]
    name = "hello_world"
    version = "0.1.0"
    authors = ["Uwe Kubosch <uwe@kubosch.no>"]

    [dependencies]

### Project build

    $ cargo build
    Compiling hello_world v0.1.0 (file:///Users/uwe/workspace/rust/hello_world)
    $ target/debug/hello_world
    Hello, world!

### Compile and Run

    $ cargo run
       Compiling hello_world v0.1.0 (file:///Users/uwe/workspace/rust/hello_world)
         Running `target/debug/hello_world`
    Hello, world!

### Binary size

    $ ll target/debug/hello_world
    -rwxr-xr-x  1 uwe  staff  303308 May 14 16:52 target/debug/hello_world

    $ ll target/release/hello_world
    -rwxr-xr-x  1 uwe  staff  302436 May 16 03:35 target/release/hello_world

    $ rustc -C prefer-dynamic -o hello_world_dyn src/main.rs
    $ ll hello_world_dyn
    -rwxr-xr-x  1 uwe  staff  8944 May 16 11:04 hello_world_dyn

## Macros

    println!("'!' marks a macro");

## Performance

    $ time ./a.out 48
    fib(48) = 4807526976

    real	0m21.393s
    user	0m21.358s
    sys	0m0.019s

    $ time cargo run 48
         Running `target/debug/hello_world 48`
    rust_fib(48) = 4807526976

    real	0m39.190s
    user	0m39.011s
    sys	0m0.095s

    $ time cargo run 48 --release
         Running `target/release/hello_world 48`
    rust_fib(48) = 4807526976

    real	0m10.464s
    user	0m10.421s
    sys	0m0.033s

## Error handling

* C happily calculated the wrong result using 32 bit integers for fib(48).
* Rust gave an arithmetic overflow error.

## Call from C

    $ rust new rust_fib_lib

Cargo.toml:
```toml
[lib]
name = "rust_fib_lib"
crate-type = ["dylib"] # could be `staticlib` or `dylib`
```

src/lib.rs:
```rust
#[no_mangle]
pub extern fn rust_fib(n: i32) -> i64 {
    if n <= 2 {
        return 1;
    }
    return rust_fib(n - 2) + rust_fib(n - 1);
}
```

    $ cargo build --release

src/rust_fib.c:
```c
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
```

    $ gcc -L target/release -lrust_fib_lib -o c_rust_fib src/rust_fib.c

    $ ll c_rust_fib
    -rwxr-xr-x  1 uwe  staff  8528 May 16 12:06 c_rust_fib

Still needs the dynamic `rust_fib_lib` library:

    $ ll target/release/librust_fib_lib.dylib
    -rwxr-xr-x  1 uwe  staff  1758696 May 16 12:05 target/release/librust_fib_lib.dylib
