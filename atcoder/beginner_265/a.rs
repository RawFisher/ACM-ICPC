fn main()
{
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let s: Vec<u32> = s.split_whitespace().map(|x| x.parse().unwrap()).collect();
    let mut ans: u32 = std::u32::MAX;
    for i in 0..101 {
        for j in 0..34 {
            if i+3*j == s[2] {
                ans = std::cmp::min(ans, s[0]*i+s[1]*j);
            }
        }
    }
    println!("{}", ans);
}