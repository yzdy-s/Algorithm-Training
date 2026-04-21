import sys
MOD = 998244353

def f(k):
    mod = k % 4
    if mod == 0:
        return k
    elif mod == 1:
        return 1
    elif mod == 2:
        return k + 1
    else:
        return 0

def main():
    input = sys.stdin.read
    data = input().split()
    t = int(data[0])
    idx = 1
    res = []
    for _ in range(t):
        n = int(data[idx])
        x = int(data[idx+1])
        idx +=2
        val = f(x-1)
        cnt = 0
        if val == 0:
            cnt += (n - x)
        r = x
        while r <= n:
            bit = r & -r
            nr = r + bit
            c = min(nr - 1, n) - r + 1
            cnt += c
            r = nr
        res.append(str(cnt % MOD))
    print('\n'.join(res))

if __name__ == "__main__":
    main()