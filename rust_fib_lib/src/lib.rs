//#![no_std]

#[no_mangle]
pub extern fn rust_fib(n: i32) -> i64 {
    if n <= 2 {
        return 1;
    }
    return rust_fib(n - 2) + rust_fib(n - 1);
}

//#[lang = "eh_personality"] extern fn eh_personality() {}
//#[lang = "panic_fmt"] fn panic_fmt() -> ! { loop {} }
