import sys

# Using sys.stdin.readline for faster input, common in competitive programming
# For simple cases, input() works fine too.
# input = sys.stdin.readline

def solve():
    """
    Solves a single test case based on the provided C++ logic.
    """
    MOD = 998244353
    # The maximum value for exponents in the C++ code's pow array was 100005.
    # We need to precompute powers of 2 up to this maximum possible exponent.
    MAX_EXPONENT_VALUE = 100005

    # Precompute powers of 2 modulo MOD
    # pow_list[k] will store (2^k) % MOD
    pow_list = [0] * (MAX_EXPONENT_VALUE + 1)
    pow_list[0] = 1  # 2^0 = 1
    for i in range(1, MAX_EXPONENT_VALUE + 1):
        pow_list[i] = (pow_list[i - 1] * 2) % MOD

    t = int(input())  # Read the number of test cases

    for _ in range(t):
        n = int(input())  # Read the size of arrays a and b
        a = list(map(int, input().split()))  # Read array a
        b = list(map(int, input().split()))  # Read array b

        x_idx = 0  # Index of the current maximum element in array 'a'
        y_idx = 0  # Index of the current maximum element in array 'b'

        results_for_case = []  # List to store results for the current test case

        for j in range(n):
            # Update the index of the maximum element in 'a' found so far
            if a[j] > a[x_idx]:
                x_idx = j
            # Update the index of the maximum element in 'b' found so far
            if b[j] > b[y_idx]:
                y_idx = j

            # --- CRITICAL LOGIC POINT (Carried over from C++ code) ---
            # The C++ code uses 'a[x]' and 'b[j-x]' as exponents for 'pow'.
            # This implies:
            # 1. 'a[x]' and 'b[y]' (the values of the maximums) are used directly as exponents.
            # 2. 'j-x_idx' and 'j-y_idx' are used as *indices* into arrays 'b' and 'a' respectively,
            #    and then the *values* at those indices (b[j-x_idx] and a[j-y_idx]) are used as exponents.
            # This means 'j-x_idx' and 'j-y_idx' must be valid array indices (0 <= index < n),
            # AND the values obtained (e.g., b[j-x_idx]) must be valid exponents
            # (0 <= exponent_value <= MAX_EXPONENT_VALUE).
            # If these conditions are not met, the original C++ code would have undefined behavior
            # (e.g., out-of-bounds array access, or out-of-bounds access for 'pow' array).
            # The Python code will raise IndexError or use a default value if checks fail.

            current_val = 0 # Initialize current result for this 'j' iteration

            if a[x_idx] >= b[y_idx]:
                # First term: pow_list[a[x_idx]]
                term1_exponent = a[x_idx]
                if 0 <= term1_exponent <= MAX_EXPONENT_VALUE:
                    term1_value = pow_list[term1_exponent]
                else:
                    # Handle case where a[x_idx] is an invalid exponent
                    # This might indicate a problem with input constraints or logic.
                    # For now, we'll treat it as 0 to avoid errors, but this might
                    # not be the desired behavior for the problem.
                    term1_value = 0
                    # print(f"Warning: a[x_idx] ({term1_exponent}) out of valid exponent range for pow_list.")

                # Second term: pow_list[b[j - x_idx]]
                idx_for_b = j - x_idx
                if 0 <= idx_for_b < n:
                    term2_exponent = b[idx_for_b]
                    if 0 <= term2_exponent <= MAX_EXPONENT_VALUE:
                        term2_value = pow_list[term2_exponent]
                    else:
                        term2_value = 0
                        # print(f"Warning: b[{idx_for_b}] ({term2_exponent}) out of valid exponent range for pow_list.")
                else:
                    # Handle case where j - x_idx is an invalid index for array b
                    term2_value = 0
                    # print(f"Warning: Index j - x_idx ({idx_for_b}) out of bounds for array b.")

                current_val = (term1_value + term2_value) % MOD
            else:
                # First term: pow_list[b[y_idx]]
                term1_exponent = b[y_idx]
                if 0 <= term1_exponent <= MAX_EXPONENT_VALUE:
                    term1_value = pow_list[term1_exponent]
                else:
                    term1_value = 0
                    # print(f"Warning: b[y_idx] ({term1_exponent}) out of valid exponent range for pow_list.")

                # Second term: pow_list[a[j - y_idx]]
                idx_for_a = j - y_idx
                if 0 <= idx_for_a < n:
                    term2_exponent = a[idx_for_a]
                    if 0 <= term2_exponent <= MAX_EXPONENT_VALUE:
                        term2_value = pow_list[term2_exponent]
                    else:
                        term2_value = 0
                        # print(f"Warning: a[{idx_for_a}] ({term2_exponent}) out of valid exponent range for pow_list.")
                else:
                    # Handle case where j - y_idx is an invalid index for array a
                    term2_value = 0
                    # print(f"Warning: Index j - y_idx ({idx_for_a}) out of bounds for array a.")

                current_val = (term1_value + term2_value) % MOD

            results_for_case.append(current_val)

        # Print all results for the current test case, separated by spaces
        print(*results_for_case)

# Call the solve function to run the program
if __name__ == '__main__':
    solve()
