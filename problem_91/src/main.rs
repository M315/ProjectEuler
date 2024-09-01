struct OriginTriangle {
    p: (i32, i32),
    q: (i32, i32),
}

impl OriginTriangle {
    fn is_right_triangle(self) -> bool {
        let a2 = self.p.0 * self.p.0 + self.p.1 * self.p.1;
        let b2 = self.q.0 * self.q.0 + self.q.1 * self.q.1;
        let c2 = (self.p.0 - self.q.0) * (self.p.0 - self.q.0) + (self.p.1 - self.q.1) * (self.p.1 - self.q.1);
        if a2 == 0 || b2 == 0 || c2 == 0 { return false; }
        if a2 + b2 == c2 || a2 + c2 == b2 || b2 + c2 == a2 {
            true
        } else {
            false
        }
    }
}

fn solve(n: usize) -> usize
{
    let mut seen: Vec<Vec<Vec<Vec<bool>>>> = vec![vec![vec![vec![false; n + 1]; n + 1]; n + 1]; n + 1];
    let mut ans: usize = 0;
    for i in 0..=n {
        for j in 0..=n {
            for r in 0..=n {
                for s in 0..=n {
                    if seen[i][j][r][s] || seen[r][s][i][j] {
                        continue;
                    }
                    seen[i][j][r][s] = true;
                    seen[r][s][i][j] = true;

                    let triangle = OriginTriangle{ p: (i as i32, j as i32), q: (r as i32, s as i32) };
                    if triangle.is_right_triangle() {
                        ans += 1;
                    }
                }
            }
        }
    }
    
    ans
}

fn main() {
    println!("{}", solve(50));
}
