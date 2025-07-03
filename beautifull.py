import math

def solve():

    n = int(input())
    a = list(map(int, input().split()))

    for i in range(n - 1):
        if abs(a[i] - a[i+1]) <= 1:
            print(0)
            return

    min_ops = float('inf')

    for i in range(n - 1):
        # Precompute min/max for all possible right segments starting at i+1
        right_mins = {}
        right_maxs = {}
        current_min = a[i+1]
        current_max = a[i+1]
        for k in range(i + 1, n):
            current_min = min(current_min, a[k])
            current_max = max(current_max, a[k])
            right_mins[k] = current_min
            right_maxs[k] = current_max

        left_min = a[i]
        left_max = a[i]
        
        # k_ptr is the right endpoint of the right segment
        k_ptr = n - 1
        
        # j is the left endpoint of the left segment
        for j in range(i, -1, -1):
            left_min = min(left_min, a[j])
            left_max = max(left_max, a[j])

            # Use the two-pointer approach to find the smallest valid k_ptr
            while k_ptr > i:
                r_min_prev = right_mins[k_ptr-1]
                r_max_prev = right_maxs[k_ptr-1]
                if max(left_min, r_min_prev) <= min(left_max, r_max_prev) + 1:
                    k_ptr -= 1
                else:
                    break
            
            # Check if the current k_ptr forms a valid beautiful pair
            if k_ptr < n:
                r_min = right_mins[k_ptr]
                r_max = right_maxs[k_ptr]
                if max(left_min, r_min) <= min(left_max, r_max) + 1:
                    ops = (i - j) + (k_ptr - (i + 1))
                    min_ops = min(min_ops, ops)

    if min_ops == float('inf'):
        print(-1)
    else:
        print(min_ops)


def main():
    """
    Main function to handle multiple test cases.
    """
    try:
        t = int(input())
        for _ in range(t):
            solve()
    except (IOError, ValueError):
        # Handles potential empty lines or formatting errors in input
        pass

if __name__ == "__main__":
    main()
