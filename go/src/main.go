package main

import (
	"fmt"
)

func dump(label string, slice []string) {
	fmt.Printf("%v: lenth %v, capacity %v %v\n", label, len(slice), cap(slice), slice)
}

func main() {
	dwarfs1 := []string{"ceres", "pluto", "haumea", "makemake", "eris", "xiaozhi"}

	terrestrial := dwarfs1[0:5]
	terrestrial[1] = "xiaoxiaozhi"

	dump("dwarfs1", dwarfs1)

}
