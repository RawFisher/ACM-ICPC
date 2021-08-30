import os
import random
import subprocess

def solve(n, k, a):
    import heapq
    a = [-x for x in a]
    heapq.heapify(a)
    res = 0
    for i in range(k):
        x = -heapq.heappop(a)
        if x == 0:
            break
        res += x
        x -= 1
        heapq.heappush(a, -x)
        # print(a)
    return res


def main():
    while True:
        n = random.randint(99999, 100000)
        k = random.randint(10000000, 20000000)
        a = [ random.randint(1000000000, 2000000000) for i in range(n)]
        with open("input", "w") as f:
            f.write("%d %d\n" % (n, k))
            for i in range(n):
                f.write("%d " % a[i])
        res = solve(n, k, a)
        # c++ result
        r = os.popen("./a < input")
        text = r.read()
        r.close()

        if (int(text) == res):
            print("pass!")
        else:
            print(int(text), res)
            print("fail!")
            break
        # pass
    # pass


if __name__ == "__main__":
    main()