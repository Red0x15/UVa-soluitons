if __name__ == "__main__":
    finish = False
    while not finish:
        try:
            l = int(input())
            arr = [int(i) for i in input().split()]
            flips = 0
            
            i = 1
            while i < l:
                j = 0
                while j < i:
                    if arr[i] < arr[j]:
                        flips += 1
                    j += 1
                i += 1
            print("Minimum exchange operations : " + str(flips))
        except:
            finish = True