package main

import (
	"fmt"
	"sort"
)

// Scheduler represents a scheduling algorithm
type Scheduler interface {
	Schedule(processes []Process)
}

// Process contains the process information
type Process struct {
	Index    int
	Length   int
	Priority int
	ExeTime  int
}

func main() {
	fmt.Printf("Number of Processes: ")
	var n int
	if _, err := fmt.Scanf("%d", &n); err != nil {
		return
	}
	processes := make([]Process, n)

	for i := 0; i < n; i++ {
		fmt.Printf("Please enter the process %d length: ", i)
		if _, err := fmt.Scanf("%d", &processes[i].Length); err != nil {
			return
		}
		processes[i].Index = i
	}

	fmt.Println("1) FCFS")
	fmt.Println("2) Shortest Job First")
	fmt.Println("3) Priority")
	fmt.Println("4) RR")

	var choice int
	if _, err := fmt.Scanf("%d", &choice); err != nil {
		return
	}

	switch choice {
	case 1:
		FCFS{}.Schedule(processes)
	case 2:
		SJF{}.Schedule(processes)
	case 3:
	case 4:
		fmt.Printf("RR Quantum: ")
		var q int
		if _, err := fmt.Scanf("%d", &q); err != nil {
			return
		}
		RR{q}.Schedule(processes)
	}
}

// FCFS is a first come first serve scheduler
type FCFS struct {
}

// Schedule schedules given processes and fills their execution time
func (FCFS) Schedule(processes []Process) {
	time := 0

	fmt.Println(">>>")
	fmt.Println("FCFS")
	for i, p := range processes {
		fmt.Printf("P%d in %d\n", p.Index, time)
		processes[i].ExeTime = time
		time += p.Length
	}
	fmt.Println(">>>")
}

// SJF is a shortest job first scheduler
type SJF struct {
}

// Schedule schedules given processes and fills their execution time
func (SJF) Schedule(processes []Process) {
	time := 0

	fmt.Println(">>>")
	fmt.Println("SJF")
	sort.Slice(processes, func(i, j int) bool {
		return processes[i].Length < processes[j].Length
	})
	for i, p := range processes {
		fmt.Printf("P%d in %d\n", p.Index, time)
		processes[i].ExeTime = time
		time += p.Length
	}
	fmt.Println(">>>")
}

// RR is a round robin scheduler
type RR struct {
	Quantum int
}

// Schedule schedules given processes and fills their execution time
func (rr RR) Schedule(processes []Process) {
	time := 0
	done := 0

	fmt.Println(">>>")
	fmt.Println("RR")
	for done < len(processes) {
		fmt.Println("Round")
		for i, p := range processes {
			if p.ExeTime < p.Length {
				fmt.Printf("P%d in %d (remain %d)\n", p.Index, time, p.Length-p.ExeTime)
				if p.ExeTime+rr.Quantum >= p.Length {
					processes[i].ExeTime, time = time, time+(p.Length-p.ExeTime)
					done++
				} else {
					processes[i].ExeTime += rr.Quantum
					time += rr.Quantum
				}
			}
		}
		fmt.Println("---")
	}
	fmt.Println(">>>")
}
