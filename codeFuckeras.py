import sys

# For faster input
input = sys.stdin.readline

# Represents the counts of factors 2 and 5
class Pair:
    def __init__(self, a=0, b=0):
        self.a = a  # Count of factor 2s
        self.b = b  # Count of factor 5s

    # Adds two Pair objects element-wise, returning a new Pair
    def add(self, other):
        return Pair(self.a + other.a, self.b + other.b)

    # For debugging/printing Pair objects
    def __repr__(self):
        return f"({self.a}, {self.b})"

# Extracts counts of factors 2 and 5 from a number
def extract_power(n_val):
    if n_val == 0:
        # Special handling for 0: it effectively contributes one 2 and one 5
        # This is for the DP calculation. The special zero_path logic handles the actual path.
        return Pair(1, 1)
    if n_val == 1:
        return Pair(0, 0) # 1 contributes no factors of 2 or 5

    c2 = 0
    temp_n = n_val
    while temp_n > 0 and temp_n % 2 == 0:
        c2 += 1
        temp_n //= 2

    c5 = 0
    temp_n = n_val
    while temp_n > 0 and temp_n % 5 == 0:
        c5 += 1
        temp_n //= 5

    return Pair(c2, c5)

def solve():
    n = int(input())
    a = []
    for _ in range(n):
        a.append(list(map(int, input().split())))

    # --- Variables for handling '0' in the input grid ---
    has_zero = False
    zero_r, zero_c = -1, -1
    for r in range(n):
        for c in range(n):
            if a[r][c] == 0:
                has_zero = True
                zero_r, zero_c = r, c
                # Only need to store the first zero found
                # (any path through a zero makes product 0, leading to 1 trailing zero)
                break
        if has_zero:
            break

    # --- Dynamic Programming Tables ---
    # dp_twos[i][j] stores the minimum count of factor 2s to reach (i,j)
    dp_twos = [[0] * n for _ in range(n)]
    # dp_fives[i][j] stores the minimum count of factor 5s to reach (i,j)
    dp_fives = [[0] * n for _ in range(n)]

    # Path tracking tables: 'D' for Down, 'R' for Right
    path_twos_dir = [[''] * n for _ in range(n)]
    path_fives_dir = [[''] * n for _ in range(n)]

    # --- Fill DP Tables ---
    for r in range(n):
        for c in range(n):
            current_factors = extract_power(a[r][c])

            # Adjust current_factors for '0' in actual calculation if `has_zero` is True
            # We already adjust in extract_power, so this ensures DP operates as if 0 is 10 (1 factor of 2, 1 of 5)
            # The special zero_path will override later if needed.

            # Base case: (0,0)
            if r == 0 and c == 0:
                dp_twos[r][c] = current_factors.a
                dp_fives[r][c] = current_factors.b
            elif r == 0: # First row: can only come from left
                dp_twos[r][c] = dp_twos[r][c-1] + current_factors.a
                dp_fives[r][c] = dp_fives[r][c-1] + current_factors.b
                path_twos_dir[r][c] = 'R'
                path_fives_dir[r][c] = 'R'
            elif c == 0: # First column: can only come from up
                dp_twos[r][c] = dp_twos[r-1][c] + current_factors.a
                dp_fives[r][c] = dp_fives[r-1][c] + current_factors.b
                path_twos_dir[r][c] = 'D'
                path_fives_dir[r][c] = 'D'
            else: # General case: compare paths from up and left
                # For dp_twos:
                if dp_twos[r-1][c] < dp_twos[r][c-1]:
                    dp_twos[r][c] = dp_twos[r-1][c] + current_factors.a
                    path_twos_dir[r][c] = 'D'
                else:
                    dp_twos[r][c] = dp_twos[r][c-1] + current_factors.a
                    path_twos_dir[r][c] = 'R'
                
                # For dp_fives:
                if dp_fives[r-1][c] < dp_fives[r][c-1]:
                    dp_fives[r][c] = dp_fives[r-1][c] + current_factors.b
                    path_fives_dir[r][c] = 'D'
                else:
                    dp_fives[r][c] = dp_fives[r][c-1] + current_factors.b
                    path_fives_dir[r][c] = 'R'

    # --- Determine the final minimum zeros and corresponding path ---
    final_min_zeros_2 = dp_twos[n-1][n-1]
    final_min_zeros_5 = dp_fives[n-1][n-1]

    # Decide which path (minimizing 2s or 5s) to choose
    if final_min_zeros_2 < final_min_zeros_5:
        chosen_min_zeros = final_min_zeros_2
        chosen_path_dir = path_twos_dir
    else:
        chosen_min_zeros = final_min_zeros_5
        chosen_path_dir = path_fives_dir
    
    # --- Special handling for '0' in the input grid ---
    # If a zero was found and the DP-calculated min_zeros is greater than 1,
    # then the true minimum is 1 (because any path through 0 makes the product 0).
    if has_zero and chosen_min_zeros > 1:
        print(1)
        path = []
        # Path: Go down to zero_r, then right to zero_c
        path.extend(['D'] * zero_r)
        path.extend(['R'] * zero_c)
        # Then from zero_r, zero_c to n-1, n-1
        path.extend(['D'] * (n - 1 - zero_r))
        path.extend(['R'] * (n - 1 - zero_c))
        print("".join(path))
    else:
        # --- Reconstruct the path for the chosen minimum ---
        print(chosen_min_zeros)
        path = []
        r, c = n - 1, n - 1
        while r > 0 or c > 0:
            if chosen_path_dir[r][c] == 'R':
                path.append('R')
                c -= 1
            else: # Must be 'D'
                path.append('D')
                r -= 1
        print("".join(reversed(path)))

# Call the solve function
solve()