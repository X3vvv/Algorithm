from cgitb import small
from typing import List
import math


def insertionSort(array) -> List:
    print('original:', array)
    for j in range(1, len(array)):
        kw = array[j]
        i = j-1
        while i >= 0 and kw < array[i]:
            array[i+1] = array[i]
            i -= 1
        array[i+1] = kw
        print(f'round{j}:', array)


def startMergeSort(array) -> None:
    ''' Start merge sort with human-friendly information. '''
    print("{:<20}{:<15}{:<15}{:<20}".format(
        "array", "left", "right", "merged"))

    def mergeSort(array) -> List:
        def mergeArray(left: List, right: List):
            INFINITE = 999999
            merged = []
            cnt = 0
            i = j = 0
            while cnt < len(left) + len(right):
                l = left[i] if i < len(left) else INFINITE
                r = right[j] if j < len(right) else INFINITE
                # l, r = left[i], right[j]
                if l <= r:
                    merged.append(l)
                    i += 1
                else:
                    merged.append(r)
                    j += 1
                cnt += 1
            print("{:<20}".format(str(merged)))
            return merged

        if len(array) <= 1:
            return array
        # index of 'array': 0, ..., array.length-1
        # array     array.length      middel           left     right
        # [1,2,3]        3          ceil((0+2)/2)=1     [1]     [2,3]
        # [1,2,3,4]      4          ceil((0+3)/2)=2    [1,2]    [3,4]
        middle = math.ceil(0 + (len(array)-1) / 2)
        left = mergeSort(array[:middle])
        right = mergeSort(array[middle:])
        print("{:<20}{:<15}{:<15}".format(
            str(array), str(left), str(right)), end='')
        return mergeArray(left, right)
    mergeSort(array)


def selectionSort(array) -> List:
    if len(array) <= 0:
        raise RuntimeError("Array must not be empty.")

    for i in range(len(array)):
        # initialize
        smallest_idx = i
        smallest = array[smallest_idx]
        # start
        for j in range(i, len(array)):
            if array[j] < smallest:
                smallest_idx, smallest = j, array[j]
        array[i], array[smallest_idx] = array[smallest_idx], array[i]
        print(array)


data = [5, 3, 4, 1, 2]

# startMergeSort(data)
selectionSort(data)
