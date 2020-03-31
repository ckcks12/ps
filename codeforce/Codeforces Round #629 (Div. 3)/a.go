package main

import "fmt"

func main() {
	T := 0
	fmt.Scanf("%d\n", &T)
	for t := 0; t < T; t++ {
		a := 0
		b := 0
		fmt.Scanf("%d %d\n", &a, &b)
		if a % b  == 0{
			println(0)
		} else {
			println(b - (a % b))
		}
	}
}
