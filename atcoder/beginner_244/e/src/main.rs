use proconio::{fastout, input, marker::*};

fn get_result(n:usize, m:usize, k:usize, s:usize, t:usize, x:usize, edges:Vec<(usize, usize)>) -> u32 {
    assert_eq!(edges.len(), m);
    const MOD: u32 = 998244353;
    let mut adj = vec![vec![]; n];

    for (u, v) in edges {
        adj[u].push(v);
        adj[v].push(u);
    }

    let mut dp = vec![vec![0u32; 2]; n];
    dp[s][0] = 1;
    for _ in 0..k {
        let mut tmp = vec![vec![0u32; 2]; n];
        for j in 0..n {
            for v in &adj[j] {
                for k in 0..2 {
                    if *v == x {
                        tmp[*v][1-k] = (tmp[*v][1-k] + dp[j][k]) % MOD;
                    }
                    else {
                        tmp[*v][k] = (tmp[*v][k] + dp[j][k]) % MOD;
                    }
                }
            }
        }
        dp = tmp;
    }
    dp[t][0]
}

#[fastout]
fn main() {
    input! {
        (n, m, k, s, t, x): (usize, usize, usize, Usize1, Usize1, Usize1),
        edges: [(Usize1, Usize1); m],
    }

    println!("{}", get_result(n, m, k, s, t, x, edges));
}

#[cfg(test)]
mod tests {
    use super::get_result;

    #[test]
    fn test1() {
        let edges: Vec<(usize, usize)> = vec![(0, 1), (1, 2), (2, 3), (0, 3)];
        let res = get_result(4, 4, 4, 0, 2, 1, edges);
        assert_eq!(res, 4)
    }

    #[test]
    fn test2() {
        let edges: Vec<(usize, usize)> = vec![(1, 2), (1, 3), (3, 5), (2, 5), (0, 4)];
        let res = get_result(6, 5, 10, 0, 1, 2, edges);
        assert_eq!(res, 0)
    }

    #[test]
    fn test3() {
        let edges: Vec<(usize, usize)> = vec![(1, 5), (1, 6), (4, 6), (3, 4), (1, 3),
        (2, 6), (0, 6), (0, 3), (1, 8), (4, 9), (0, 2), (6, 7), (6, 8), (0, 5), (0, 1)];
        let res = get_result(10, 15, 20, 3, 3, 5, edges);
        assert_eq!(res, 952504739)
    }
}
