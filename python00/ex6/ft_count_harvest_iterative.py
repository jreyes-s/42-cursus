#!/usr/bin/env python3

def ft_count_harvest_iterative():
    daysUntilHarvest = int(input("Days until harvest: "))
    for day in range(1, daysUntilHarvest + 1):
        print(f"Day {day}")
    print("Harvest time!")
