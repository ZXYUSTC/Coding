# encoding:utf-8

a = [12, 3, 5, 8, 10]


def Partition(a, left, right):
    key = a[left]
    while (left < right):
        while (left < right and a[right] >= key):
            right -= 1
        a[left] = a[right]
        while (left < right and a[left] <= key):
            left += 1
        a[right] = a[left]
    a[left] = key
    return left


def qsort(a, left, right):
    if (left < right):
        # mid=(left+right)/2
        mid = Partition(a, left, right)
        qsort(a, left, mid - 1)
        qsort(a, mid + 1, right)


if __name__ == '__main__':
    a = [12, 3, 5, 8, 10]
    qsort(a, 0, 4)
    for i in xrange(0, len(a)):
        print(a[i])
