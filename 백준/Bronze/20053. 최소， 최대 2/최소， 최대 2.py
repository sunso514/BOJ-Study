for i in range(int(input())):
    N = int(input())
    lst = sorted(map(int, input().split()))
    print(lst[0], lst[-1])