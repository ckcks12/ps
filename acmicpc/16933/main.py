N, M, K = map(int, input().split(' '))
arr = []
visit = []
for n in range(N):
    arr.append(input())
    X = []
    for x in range(M):
        X.append([False for k in range(K+1)])
    visit.append(X)

X, Y = M - 1, N - 1
# x, y, k, is_day, value
Q = [[0, 0, K, True, 1]]

while len(Q) != 0:
    x, y, k, is_day, v = Q.pop(0)
    # print(x, y, k, is_day, v)
    if not (0 <= x < M and 0 <= y < N):
        continue
    if x == X and y == Y:
        print(v)
        exit(0)

    if visit[y][x][k]:
        continue
    visit[y][x][k] = True

    if x < X:
        if arr[y][x + 1] == '1':
            if k > 0:
                if is_day:
                    Q.append([x + 1, y, k - 1, not is_day, v + 1])
                else:
                    Q.append([x + 1, y, k, is_day, v + 2])
        else:
            Q.append([x + 1, y, k, not is_day, v + 1])

    if 0 < x:
        if arr[y][x - 1] == '1':
            if k > 0:
                if is_day:
                    Q.append([x - 1, y, k - 1, not is_day, v + 1])
                else:
                    Q.append([x - 1, y, k, is_day, v + 2])
        else:
            Q.append([x - 1, y, k, not is_day, v + 1])

    if y < Y:
        if arr[y + 1][x] == '1':
            if k > 0:
                if is_day:
                    Q.append([x, y + 1, k - 1, not is_day, v + 1])
                else:
                    Q.append([x, y + 1, k, is_day, v + 2])
        else:
            Q.append([x, y + 1, k, not is_day, v + 1])

    # if 0 < y:
    #     if arr[y - 1][x] == '1':
    #         if k > 0:
    #             if is_day:
    #                 Q.append([x, y - 1, k - 1, not is_day, v + 1])
    #             else:
    #                 Q.append([x, y - 1, k, is_day, v + 2])
    #     else:
    #         Q.append([x, y - 1, k, not is_day, v + 1])

print(-1)
