# -- coding: utf-8 --

def judge_power2(x):
    y = x - 1
    if (x & y == 0):
        return True
    else:
        return False


if __name__ == '__main__':
    # x=0
    x = input("Please input your name:\n")
    flag = judge_power2(x)
    if (flag == True):
        print("Yes")
    else:
        print("No")
