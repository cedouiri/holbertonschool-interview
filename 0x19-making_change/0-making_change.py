#!/usr/bin/python3
"""
makeChange function.
"""


def makeChange(coins, total):
    """
        Returns the fewest number of coins needed to meet a given total.
    """
    if total <= 0:
        return 0

    changes = [total + 1] * (total + 1)
    changes[0] = 0

    for i in range(1, total + 1):
        for j in range(0, len(coins)):
            if coins[j] <= i:
                changes[i] = min(changes[i], changes[i - coins[j]] + 1)

    return -1 if changes[total] > total else changes[total]
