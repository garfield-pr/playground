package main

import (
	"fmt"
	"time"
)

func hello(c chan int) {
	for i := 0; i <= 1000000; i++ {
		fmt.Println("Hello", i)
		c <- i % 30
	}
}
func world(c chan int) {
	for i := 0; i <= 1000000; i++ {
		if <-c == 29 {
			fmt.Println("World", i)
		}
	}
}

func main() {
	var c chan int = make(chan int)
	go world(c)
	go hello(c)

	time.Sleep(time.Minute)
}
