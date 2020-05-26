# Python 3
# Problema 11498 UVa Online Judge "Division of Nlogonia"

if __name__ == "__main__":
    cases = int(input())
    while cases:
        temp = (input()).split()
        dPoint = (int(temp[0]), int(temp[1]))
        while cases:
            temp = (input()).split()
            house = (int(temp[0]), int(temp[1]))
            if dPoint[0] == house[0] or dPoint[1] == house[1]:  # Coinciden con el punto de division
                print("divisa")
            else:
                ans = ['S', 'O']
                if house[1] > dPoint[1]:    # Esta arriba del eje
                    ans[0] = 'N'
                if house[0] > dPoint[0]:    # Esta a la derecha del eje
                    ans[1] = 'E'
                print(ans[0] + ans[1])
            cases -= 1
        cases = int(input())