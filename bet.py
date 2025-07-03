def can_vadim_win(test_cases):
    results = []
    for n, days in test_cases:
        unique_days = set(days)
        if len(unique_days) >= 3:
            results.append("Yes")
        else:
            results.append("No")
    return results

# Input reading
t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    days = list(map(int, input().split()))
    test_cases.append((n, days))

# Get results
results = can_vadim_win(test_cases)

# Output results
for result in results:
    print(result)
