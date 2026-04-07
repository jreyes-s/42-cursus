#!/usr/bin/env python3

def ft_count_harvest_recursive():
    days = int(input("Days until harves: "))
    def helper(current, total):
        if current >= total:
            print("Harvest time!")
            return
        print("Day", current)
        helper(current + 1, total)
    helper(1, days + 1)
