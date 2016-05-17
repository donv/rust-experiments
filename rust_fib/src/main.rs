use std::env;

fn main() {
    let args: Vec<_> = env::args().collect();
    if args.len() < 2 {
        println!("Usage: fib <n>");
        return;
    }
    let n = args[1].parse::<i32>().unwrap();
    println!("fib({}) = {}", n, fib(n));
}

fn fib(n: i32) -> i64 {
    if n <= 2 {
        return 1;
    }
    return fib(n - 2) + fib(n - 1);
}
