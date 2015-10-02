price = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30]


def cut_rob(n):
    if n == 0:
        return 0
    else:
        q = price[n]

        # import ipdb; ipdb.set_trace()  # XXX BREAKPOINT
        for i in range(1, n):
            q = max(q, price[i] + cut_rob(n - i))

    return q


def cut_rob_memozied(n, r):
    print(r)
    if n in r:
        return r[n]
    elif n == 0:
        return 0
    else:
        q = price[n]
        for i in range(1, n):
            q = max(q, price[i] + cut_rob_memozied(n - i, r))
    r[n] = q
    return q


def cut_rob_bottom_up(n):
    r = {}
    for j in range(1, n + 1):
        q = price[j]
        for i in range(1, j + 1):  # cacualte r[i]
            q = max(q, price[i] + r[j - i])
        r[j] = q
    return r[n]


if __name__ == '__main__':
    # print(cut_rob(4))
    r = {}
    answer = cut_rob_memozied(4, r)
    print(answer)
