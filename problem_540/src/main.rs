/*
use::std::f64::consts::PI;

//Generate all the (odd-even, even-odd) coprime pairs
fn dfs(m : u64, n : u64, ret : &mut u64, k : u64)
{
    if m * m + n * n > k
    {
        return;
    }
    
    *ret += 1;

    dfs(2 * m - n, m, ret, k);
    dfs(2 * m + n, m, ret, k);
    dfs(2 * n + m, n, ret, k);
}

// Generate all the (odd-even, even-odd) coprime pairs
fn test(k : u64)
{
    let mut m : u64 = 2;
    let mut n : u64 = 1;
    let mut i : u64 = 1;

    while m * m + n * n <= k
    {
        println!("{} -> ({}, {})", i, m ,n);
        //let aux : u64 = m;
        m = 2 * n + m;
        //n = aux;
        i += 1;
    }
}

fn main()
{
    let num : u64 = 3_141_592_653_589_793;

    let mut k : u64 = 1_000_000_000_000_000;
    let mut a : f64 = 1.;
    let m : u64 = 2;
    let n : u64 = 1;

    while k >= 1_000_000 
    {
        let mut s : u64 = 0;
        let p : u64 = num / k;
        dfs(m, n, &mut s, p);

        println!();
        println!("{}", s);
        println!("{}", p);
        println!("{}", (s as f64) / a - 0.5);
        println!("{}", PI - (p as f64) / a);
        k /= 10;
        a *= 10.;
    }
    a = 1_000_000_000_000_000.;
    println!("{}", PI - (num as f64) / a);


}
*/

fn pe540(n: i64) -> i64 {
	let sqrt2 : f64 = 2.0f64.sqrt();
	let i_to1 : i64 = (n as f64 * (1.0 - 1.0 / sqrt2)).sqrt() as i64;
	let i_to2 : i64 = (n as f64 * (1.0 - 1.0 / sqrt2) / 2.0).sqrt() as i64;

	let mut spf = vec!(0; 2 * i_to2 as usize + 1);
	smallest_prime_factor(&mut spf);

	let mut sum : i64 = 0;

	for i in 1..i_to1+1 {
		if i % 2 == 0 { continue }
		let j_from = (i as f64 / sqrt2) as i64 + 1;
		let j_to = ((((2 * n - i * i) as f64).sqrt() - i as f64) / 2.0) as i64;
		sum += rel_prime(j_from, j_to, i, &spf);
	}
	for i in 1..i_to2+1 {
		let j_from = (i as f64 * sqrt2) as i64 + 1;
		let j_to = (((n - i * i) as f64).sqrt() - i as f64) as i64;
		sum += rel_prime(j_from, j_to, 2 * i, &spf);
	}
	sum
}

// Count numbers in {n_from,...,n_to} which are relative prime to m
fn rel_prime(n_from: i64, n_to: i64, m: i64, spf : &Vec<usize>) -> i64 {
    rel_prime2(n_to, m, spf) - rel_prime2(n_from-1, m, spf)
}

// Count numbers in {1,...,n} which are relative prime to m
fn rel_prime2(n: i64, m: i64, spf : &Vec<usize>) -> i64 {
	if n == 0 || n == 1 || m == 1 { return n }
	let p = spf[m as usize] as i64;
	let mut mm = m;
	while mm % p == 0 { mm = mm / p };
	rel_prime2(n, mm, spf) - rel_prime2(n / p, mm, spf)
}


fn main() {
	for max_side in vec![1_000_000, 3_141_592_653_589_793] {
		println!("pe540({}) = {}", max_side, pe540(max_side));
	}
}


// Create array of smallest prime factors (extended sieve)
// A number n is prime exactly if spf[n] == n
fn smallest_prime_factor(spf : &mut Vec<usize>) {
    let n = spf.len();
    for i in 1..n { spf[i] = i };
    for i in 2..((n as f64).sqrt() as usize + 1) {
    	if spf[i] == i {
			let mut j = i * i;
    		while j < n {
    			if spf[j] > i { spf[j] = i };
    			j += i;
    		}
    	}
    }
}
