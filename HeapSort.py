# encoding:utf-8

def HeapAdjust(a, size, index):
    lchild = 2 * index + 1
    rchild = 2 * index + 2
    max = index
    if (index <= (size - 1) / 2):
        if (lchild <= (size - 1) and a[max] < a[lchild]):
            max = lchild
        if (rchild <= (size - 1) and a[max] < a[rchild]):
            max = rchild
        if (max != index):
            tmp = a[max]
            a[max] = a[index]
            a[index] = tmp
            HeapAdjust(a, size, max)


def BuildHeap(a, size):
    for i in xrange((size - 1) / 2, -1, -1):
        HeapAdjust(a, size, i)


def HeapSort(a, size):
    BuildHeap(a, size)
    for i in xrange(size - 1, -1, -1):
        tmp = a[0]
        a[0] = a[i]
        a[i] = tmp
        HeapAdjust(a, i, 0)


if __name__ == '__main__':
    a = [12, 3, 5, 8, 10, 16, 3, 5, 2]
    HeapSort(a, 9)
    for i in xrange(0, len(a)):
        print(a[i])
