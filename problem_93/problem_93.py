from typing import List
from itertools import combinations, permutations, product, chain


def max_streak(a: List[int]) -> int:
    best = 0
    streak = 0
    last = a[0]
    for n in a:
        if n - last == 1:
            streak += 1
            best = max(best, streak)
        else:
            streak = 0
        last = n
    return best


def add_brackets(exp: str) -> List[str]:
    return [
        exp,
        '(' + exp[0:3] + ')' + exp[3:],
        '(' + exp[0:5] + ')' + exp[5:],
        exp[0:2] + '(' + exp[2:5] + ')' + exp[5:],
        exp[0:2] + '(' + exp[2:] + ')',
        exp[0:4] + '(' + exp[4:] + ')',
        '(' + exp[0:3] + ')' + exp[3] + '(' + exp[4:] + ')',
    ]


def arithmetic_expressions(numbers: List[int]) -> List[int]:
    ans = []
    for p in permutations(numbers):
        for ops in product(['+', '-', '*', '/'], repeat=3):
            exp = "".join([str(x) for x in (chain(*list(zip(p, ops))))]) + str(p[3])
            for e in add_brackets(exp):
                try:
                    ans.append(eval(e))
                except Exception:
                    continue
    return list(set(ans))


def main():
    tol = 1.e-10
    best = 0
    ans = '0123'
    for c in combinations(list(range(0, 10)), 4):
        l = arithmetic_expressions(list(c))
        pos_int = sorted(list(set([int(n) for n in l if n > 0 and abs(int(n) - n) < tol])))
        streak = max_streak(pos_int)
        if streak > best:
            best = streak
            ans = "".join([str(d) for d in c])
    print(best, ans)
    return 0


if __name__ == "__main__":
    main()
