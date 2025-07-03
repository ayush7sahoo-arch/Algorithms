MAX_M = 500001
dp = [-1] * MAX_M
dp[1] = 1

for i in range(1, MAX_M):
    if dp[i] == -1:
        continue

    # Path extension
    m_new = i + 2
    if m_new < MAX_M:
        v_new = dp[i] + 1
        if dp[m_new] == -1 or v_new < dp[m_new]:
            dp[m_new] = v_new

    # Star composition
    f1 = i + 2
    for j in range(i, MAX_M):
        if dp[j] == -1:
            continue

        f2 = j + 2
        m_new = f1 * f2  # Python ints are arbitrary precision
        if m_new >= MAX_M:
            break

        v_new = 1 + dp[i] + dp[j]
        if dp[m_new] == -1 or v_new < dp[m_new]:
            dp[m_new] = v_new

# After precomputation, answer queries for m by looking up dp[m].

print(dp[21])