fn main()
{
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).expect("read line");
    let s: i64 = s.trim().parse().expect("not a i64 num");
    if s <= 0 {
        println!("{}", (s % 998244353 + 998244353) % 998244353);
    }
    else {
        println!("{}", s % 998244353);
    }
}