class Aver:
    def __init__(self):
        self.lists = []

    def ins(self, num):  # 입력 받기
        self.lists.append(num)

    def sort(self):  # 정렬
        self.lists.sort()

    def res(self, trimav, num):  # 결과
        lists = self.lists
        gans = 0
        for i in range(num, len(lists) - num, 1):
            gans += lists[i]
        if not trimav:
            gans += lists[num] * num
            gans += lists[len(lists) - num - 1] * num
            gans /= len(lists)
        else:
            gans /= len(lists)-num*2
        print('%.2f' % (gans + 0.00000001))


N, M = map(int, input().split())

ans = Aver()
for _ in range(N):
    ans.ins(float(input()))
ans.sort()

ans.res(True, M)
ans.res(False, M)
