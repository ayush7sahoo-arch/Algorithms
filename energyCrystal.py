def func(x):
    num_bits = x.bit_length()
    return 2 * num_bits + 1

# Read number of test cases
t = int(input())
results = []

for _ in range(t):
    x = int(input())
    results.append(func(x))

# Output results
for result in results:
    print(result)
