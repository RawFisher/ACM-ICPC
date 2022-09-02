fn main()
{
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let s: Vec<i64> = s.split_whitespace().map(|x| x.parse().unwrap()).collect();
    let n = s[0];
    let m = s[1];
    let t = s[2];
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let a: Vec<i64> = s.split_whitespace().map(|x| x.parse().unwrap()).collect();
    let mut imp = vec![0i64; 100010];
    for _i in 0..m {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        let s: Vec<i64> = s.split_whitespace().map(|x| x.parse().unwrap()).collect();
        let x = s[0] as usize;
        let y = s[1];
        imp[x-1] = y;
    }
    let mut tot: i64 = t;
    for i in 0..n-1 {
        let ind = i as usize;
        tot -= a[ind];
        if tot <= 0 {
            break;
        }
        tot += imp[ind+1];
    }
    if tot > 0 {
        println!("Yes");
    }
    else {
        println!("No");
    }
}