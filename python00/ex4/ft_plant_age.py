#!/usr/bin/env python3

def ft_plant_age():
    plantAgeInDays = int(input("Enter plan age in days: "))
    if plantAgeInDays > 60:
        print("Plant is ready to harvest!")
    else:
        print("Plant needs more time to grow.")
