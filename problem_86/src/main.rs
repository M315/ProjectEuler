struct Triplet(u64, u64, u64);

// Generate pitagorean triplets 
fn pythagorean_triplets(k : u64) -> Vec<Triplet>
{
    let mut ret : Vec<Triplet> = Vec::new();

    let mut n : u64 = 1;
    let mut m : u64 = 2;

    while m * m + n * n < 2 * k
    {
        if fast_gcd(n, m) == 1 && n % 2 != m % 2
        {
            let t : Triplet = Triplet(m * m - n * n, 2 * m * n, m * m + n * n);
            ret.push(t);
        }

        n += 1;
        if n == m
        {
            n = 1;
            m += 1;
        }
    }

    return ret;
}

// Fast iterative version of Euclid's GCD algorithm
fn fast_gcd(mut a: u64, mut b: u64) -> u64 {
    while b != 0 {
        a %= b;
        std::mem::swap(&mut a, &mut b);
    }
    return a;
}

// Given a and b+c retruns how many rutes there are smaller than m
fn count_rutes(a : u64, x : u64, m : u64) -> u64
{
    if a > m
    {
        return 0;
    }

    if x <= a
    {
        return x / 2;
    }
    else
    {
        if 2 * a >= x
        {
            return a - (x + 1) / 2 + 1;
        }
        else
        {
            return 0;
        }
    }
}

fn solve(m : u64, triplets : &Vec<Triplet>) -> u64
{
    let mut count : u64 = 0;
    for Triplet(x, y, _) in triplets
    {
        let mut k = 1;
        while x * k <= m || y * k <= m
        {
            count += count_rutes(x * k, y * k, m);
            count += count_rutes(y * k, x * k, m);
            k += 1;
        }
    }

    return count;
}

fn main()
{
    let m : u64 = 1_000_000;
    let k : u64 = (m as f64).log(10.) as u64;
    let triplets : Vec<Triplet> = pythagorean_triplets(k * m);
    println!("{}", solve(m, &triplets));
    /*
    let mut m : u64 = 1800;
    let k : u64 = (m as f64).log(10.) as u64;
    let triplets : Vec<Triplet> = pythagorean_triplets(k * m);

    while solve(m, &triplets) < 1_000_000
    {
        m += 1;
    }

    println!("{}", m);
    */
}
