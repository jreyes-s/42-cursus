#!/usr/bin/env python3

def ft_water_reminder():
    lastWateringDays = int(input("Days since last watering: "))
    if lastWateringDays > 2:
        print("Water the plants!")
    else:
        print("Plants are fine")
