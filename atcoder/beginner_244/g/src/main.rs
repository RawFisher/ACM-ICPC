use proconio::{fastout, input};

fn dfs(u: usize, g: &Vec<Vec<usize>>, ans: &mut Vec<usize>, s: &mut Vec<bool>, vis: &mut Vec<bool>) -> ()
{
    vis[u] = true;
    ans.push(u+1); s[u] ^= true;
    for &v in g[u].iter() {
        if vis[v] {
            continue;
        }
        dfs(v, g, ans, s, vis);
        ans.push(u+1); s[u] ^= true;
        if s[v] {
            ans.push(v+1); s[v] ^= true;
            ans.push(u+1); s[u] ^= true;
        }
    }
}

fn get_result(n: usize, edges: &Vec<(usize, usize)>, s: &String) -> (usize, Vec<usize>)
{
    let mut g: Vec<Vec<usize>> = vec![vec![]; n];
    for &x in edges.iter() {
        g[x.0 - 1].push(x.1 - 1);
        g[x.1 - 1].push(x.0 - 1);
    }
    let mut bool_s: Vec<bool> = Vec::new();
    for &c in s.as_bytes().iter() {
        let tmp = (c as usize) - 48;
        if tmp == 0 {
            bool_s.push(false);
        }
        else {
            bool_s.push(true);
        }
    }
    let mut ans: Vec<usize> = Vec::new();
    let mut vis: Vec<bool> = vec![false; n];
    dfs(0, &g, &mut ans, &mut bool_s, &mut vis);
    if bool_s[0] {
        ans.push(g[0][0] + 1);
        ans.push(1);
        ans.push(g[0][0] + 1);
    }
    (ans.len(), ans)
}

#[fastout]
fn main() {
    input! {
        (n, m): (usize, usize),
        edges: [(usize, usize); m],
        s: String
    }
    let result = get_result(n, &edges, &s);
    println!("{}", result.0);
    for &x in result.1.iter() {
        print!("{} ", x);
    }
    println!();
}


#[cfg(test)]
mod tests {
    use super::get_result;

    #[test]
    fn test1() {
        let edges: Vec<(usize, usize)> = vec![(6, 3), (2, 5), (4, 2), (1, 3), (6, 5), (3, 2)];
        let n = 6;
        let s = "110001".to_string();
        let result = get_result(n, &edges, &s);
        assert!(result.0 <= 4 * n);
    }

    #[test]
    fn test2() {
        let edges: Vec<(usize, usize)> = vec![(3, 1), (3, 2), (1, 2)];
        let n = 3;
        let s = "000".to_string();
        let result = get_result(n, &edges, &s);
        assert!(result.0 <= 4 * n);
    }
}
