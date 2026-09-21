class Solution:
    def canPlaceFlowers(self, f: list[int], n: int) -> bool:

        for i in range(len(f)):

            if n == 0:
                return True

            if f[i] == 0 and \
               (i == 0 or f[i - 1] == 0) and \
               (i == len(f) - 1 or f[i + 1] == 0):

                f[i] = 1
                n -= 1

        return n == 0