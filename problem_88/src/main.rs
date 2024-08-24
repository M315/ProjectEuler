use std::collections::HashSet;

fn next_num(v: &mut Vec<i64>, s: &mut i64) -> Result<i64, bool> {
    let p: i64 = v.iter().take(20).fold(1i64, |acc, &n| acc * n);

    // Found
    if p == *s {
        v[0] += 1;
        *s += 1;
        //println!("---> {:?}: {}", v, p);
        return Ok(p);
    }

    if p < *s {
        // Keep increasing the first term
        v[0] += 1;
        *s += 1;
    } else {
        // Find the first term s.t. v[i] < v[i - 1] and reset the vector to its value + 1
        // i.e. [4,4,2,2,1,1,1,1] => [3,3,3,2,1,1,1,1]
        if let Some((idx, _)) = v.windows(2).enumerate().find(|(_, w)| w[1] < w[0]) {
            for i in 0..=idx + 1 {
                v[i] = v[idx + 1] + 1;
            }
        } else {
            for i in 0..v.len() {
                v[i] = v[v.len() - 1] + 1;
            }
        }
        *s = v.iter().fold(0, |acc, n| acc + *n);
    }
    
    //Err(v.iter().fold(1i64, |acc, &n| acc * n))
    let m = 14.min(v.len() - 1);
    if v[m] >= 2 {
        Err(true)
    } else {
        Err(false)
    }
}

fn sum_prod_num(k: usize) -> i64 {
    let mut v: Vec<i64> = vec![1; k.min(21)];
    v[0] = 2;
    v[1] = 2;
    
    if k > 20 { v[20] = k as i64 - 20; }

    let mut s: i64 = k as i64 + 2;
    let mut best: i64 = i64::MAX;

    loop {
        match next_num(&mut v, &mut s) {
            Ok(n)       => best = best.min(n),
            Err(true)   => { break; },
            Err(false)  => {},
        }
        //println!("{:?}, {}", v, s);
    }

    //println!("---> {:?} {} | {} - {}\n", v, best, s, p);
    best
}

fn main()
{
    let mut ans: HashSet<i64> = HashSet::new();
    for k in 2..=12000 {
        if k % 1000 == 0 {
            println!("\n--- # {} ---", k);
        }
        ans.insert(sum_prod_num(k));
    }
    println!("{}", ans.into_iter().sum::<i64>());
}
