package main

import (
	"fmt"
)

var (
	N     = 0
	M     = 0
	K     = 0
	arr   [1001][1001]int
	visit [1001][1001][11]bool
	dx    = [4]int{0, 1, 0, -1}
	dy    = [4]int{-1, 0, +1, 0}
)

func main() {
	fmt.Scanf("%d %d %d\n", &N, &M, &K)

	for n := 0; n < N; n++ {
		for m := 0; m < M; m++ {
			i := 0
			fmt.Scanf("%c", &i)
			if i == 48 {
				i = 0
			} else {
				i = 1
			}
			arr[n][m] = i
		}
		fmt.Scanf("\n")
	}

	X := M - 1
	Y := N - 1
	Q := make([][]int, 0)
	// x y k day value
	Q = append(Q, []int{0, 0, K, 1, 1})
	visit[0][0][K] = true

	for len(Q) != 0 {
		q := Q[0]
		Q = Q[1:]
		x := q[0]
		y := q[1]
		k := q[2]
		d := q[3]
		v := q[4]
		//println(x, y, k, d, v)

		if x == X && y == Y {
			fmt.Printf("%d\n", v)
			return
		}

		for i := 0; i < 4; i++ {
			nx := x + dx[i]
			ny := y + dy[i]
			nk := k - 1
			nv := v + 1
			nd := d ^ 1

			if !(0 <= nx && nx <= X && 0 <= ny && ny <= Y) {
				continue
			}
			if arr[ny][nx] == 1 && k > 0 && !visit[ny][nx][nk] {
				if d == 1 {
					visit[ny][nx][nk] = true
					Q = append(Q, []int{nx, ny, nk, nd, nv})
				} else {
					Q = append(Q, []int{x, y, k, nd, nv})
				}
			} else if arr[ny][nx] == 0 && !visit[ny][nx][k] {
				visit[ny][nx][k] = true
				Q = append(Q, []int{nx, ny, k, nd, nv})
			}
		}
	}

	fmt.Printf("-1\n")
}
