use std::collections::VecDeque;

use proconio::{fastout, input};

fn get_result(n: usize, m: usize, edges: &Vec<(usize, usize)>) -> usize
{
    assert_eq!(edges.len(), m);
    const INF: usize = 10000000007;
    let mut result = 0;
    let mut g: Vec<Vec<usize>> = vec![vec![]; n];
    for e in edges {
        g[e.0-1].push(e.1-1);
        g[e.1-1].push(e.0-1);
    }
    let mut dist = vec![vec![INF; n]; 1<<n];
    let mut q : VecDeque<(usize, usize)> = VecDeque::new();
    for u in 0..n {
        q.push_back((1<<u, u));
        dist[1<<u][u] = 1;
        dist[0][u] = 0;
    }
    while let Some(x) = q.pop_front() {
        for &v in g[x.1].iter() {
            let d = dist[x.0][x.1];
            let s: usize = x.0 ^ (1usize<<v);
            if d+1<dist[s][v] {
                dist[s][v] = d + 1;
                q.push_back((s, v));
            }
        }
    }
    for i in 0..(1usize<<n) {
        result += dist[i].iter().min().unwrap();
    }
    result
}

#[fastout]
fn main() {
    input! {
        (n, m): (usize, usize),
        edges: [(usize, usize); m]
    }
    println!("{}", get_result(n, m, &edges));
}

#[cfg(test)]
mod tests {
    use super::get_result;

    #[test]
    fn test1() {
        let edges: Vec<(usize, usize)> = vec![(1, 2), (2, 3)];
        let n = 3;
        let m = 2;
        let res = get_result(n, m, &edges);
        assert_eq!(res, 14);
    }

    #[test]
    fn test2() {
        let edges: Vec<(usize, usize)> = vec![(4, 2), (2, 3), (1, 3), (2, 1), (1, 5)];
        let n = 5;
        let m = 5;
        let res = get_result(n, m, &edges);
        assert_eq!(res, 108);
    }
}