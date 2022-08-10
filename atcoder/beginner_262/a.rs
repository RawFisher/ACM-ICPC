use std::io;

fn main() {
    let mut y = String::new();
    io::stdin().read_line(&mut y).expect("Failed to read line");
    let mut y:i32 = y.trim().parse().expect("not a number");
    while y%4 != 2 {
        y += 1;
    }
    println!("{}", y);
}