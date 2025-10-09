package main

import "testing"

func TestFCFS(t *testing.T) {

	testCases := []struct {
		Processes []Process
		WaitTimes []int
	}{
		{
			Processes: []Process{
				Process{
					Index:  0,
					Length: 5,
				},
				Process{
					Index:  1,
					Length: 2,
				},
			},
			WaitTimes: []int{0, 5},
		},
	}

	for _, tc := range testCases {
		FCFS{}.Schedule(tc.Processes)
		for _, p := range tc.Processes {
			if p.ExeTime != tc.WaitTimes[p.Index] {
				t.Errorf("process %d must be executed at %d", p.Index, tc.WaitTimes[p.Index])
			}
		}
	}
}

func TestSJF(t *testing.T) {

	testCases := []struct {
		Processes []Process
		WaitTimes []int
	}{
		{
			Processes: []Process{
				Process{
					Index:  0,
					Length: 5,
				},
				Process{
					Index:  1,
					Length: 2,
				},
			},
			WaitTimes: []int{2, 0},
		},
	}

	for _, tc := range testCases {
		SJF{}.Schedule(tc.Processes)
		for _, p := range tc.Processes {
			if p.ExeTime != tc.WaitTimes[p.Index] {
				t.Errorf("process %d must be executed at %d", p.Index, tc.WaitTimes[p.Index])
			}
		}
	}
}

func TestRR(t *testing.T) {

	testCases := []struct {
		Processes []Process
		WaitTimes []int
	}{
		{
			Processes: []Process{
				Process{
					Index:  0,
					Length: 4,
				},
				Process{
					Index:  1,
					Length: 4,
				},
				Process{
					Index:  2,
					Length: 4,
				},
				Process{
					Index:  3,
					Length: 4,
				},
			},
			WaitTimes: []int{12, 13, 14, 15},
		},
	}

	for _, tc := range testCases {
		RR{3}.Schedule(tc.Processes)
		for _, p := range tc.Processes {
			if p.ExeTime != tc.WaitTimes[p.Index] {
				t.Errorf("process %d must be executed at %d", p.Index, tc.WaitTimes[p.Index])
			}
		}
	}
}
