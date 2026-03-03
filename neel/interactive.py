import sys
input = sys.stdin.readline

# ---------------- CONFIG ----------------
DEBUG = False   # set True for local testing
QUERY_LIMIT = 10**6   # change per problem if needed

queries = 0

# ---------------- QUERY ----------------
def ask(*args):
    """
    Generic query function
    Usage:
        ask(x)
        ask(x, y)
        ask(x, y, z)
    """
    global queries
    queries += 1

    if queries > QUERY_LIMIT:
        sys.exit()   # safety guard

    print("?", *args)
    sys.stdout.flush()

    res = input().strip()

    if res == "-1":   # judge error
        sys.exit()

    return res   # convert outside if needed


# ---------------- ANSWER ----------------
def answer(*args):
    """
    Generic answer function
    Usage:
        answer(x)
        answer(x, y)
    """
    print("!", *args)
    sys.stdout.flush()


# ---------------- SOLVE ----------------
def solve():
    # Example skeleton:
    # n = int(input())

    # Example usage:
    # res = ask(1, 2)
    # val = int(res)

    # answer(val)

    pass


# ---------------- DRIVER ----------------
def main():
    t = 1
    # Uncomment if multiple test cases:
    # t = int(input())
    
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()