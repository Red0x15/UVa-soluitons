def isPalindromic(wordNum):
    ans = False
    if (wordNum[::-1] == wordNum):
        ans = True
    return ans
    

if __name__ == "__main__":
    cases = int(input())
    while(cases):
        num = input()

        count = 0
        if (isPalindromic(num)):
            count = 1
            num = str(int(num) + int(num[::-1]))    

        while (not isPalindromic(num)):
            num = str(int(num) + int(num[::-1]))
            count += 1

        print(str(count) + " " + num)
        
        cases -= 1