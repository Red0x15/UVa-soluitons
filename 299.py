if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        l = int(input())
        if l:
            arr = list(map(int, input().split()))
            
            swaps = 0
            for i in range(l):
                for j in range(i+1, l):
                    if arr[i] > arr[j]:
                        arr[i], arr[j] = arr[j], arr[i]
                        swaps += 1
            print("Optimal train swapping takes " + str(swaps) + " swaps.")
        else: print("Optimal train swapping takes 0 swaps.")