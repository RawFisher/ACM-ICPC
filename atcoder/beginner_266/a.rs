fn main()
{
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).expect("read line");
    let s = s.trim();
    println!("{}", s.chars().nth(s.len()/2).unwrap());
}