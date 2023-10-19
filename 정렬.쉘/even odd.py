import random
import numpy as np  

def swap(a, i, j): 
    a[i], a[j] = a[j], a[i]
    return a


def insertion_sort(a, start, end, interval):
    for i in range(start + interval, end + 1, interval):
        temp = a[i]
        j = i - interval
        while j >= start and temp < a[j]:
            a[j + interval] = a[j]
            j -= interval
        a[j + interval] = temp
    return a



def shell_sort(a):
    n = len(a)
    comparisons_even = 0  # 짝수 interval의 연산 횟수
    comparisons_odd = 0  # 홀수 interval의 연산 횟수
    
    odd = n // 2 if n%2!=0 else n // 2 + 1
    even = n // 2 if n%2==0 else n // 2 + 1

    while (odd > 0 or even > 0):
        # 짝수 interval에 대한 정렬
        for i in range(even, n):
            j = i - even    # 삽입할 위치
            tmp = a[i]      # 삽입할 원소

            while j >= 0 and a[j] > tmp:
                a[j + even] = a[j]  # i에다가 j를 삽입 = 앞쪽에 큰애를 뒤로
                j -= even           # j는 even만큼 빼줌
                comparisons_even += 1

            # 만약 교환이 없다면 i에 그대로 삽입
            a[j + even] = tmp
        
        # 홀수 interval에 대한 정렬
        
        for i in range(odd, n):
            j = i - odd
            tmp = a[i]

            while j >= 0 and a[j] > tmp:
                a[j + odd] = a[j]
                j -= odd
                comparisons_odd += 1
            a[j + odd] = tmp
        
        even = even // 2 if even % 2 == 0 else even // 2 + 1
        odd = odd // 2 if odd % 2 == 1 else odd // 2 + 1
    
    return comparisons_even, comparisons_odd


# 테스트를 위한 임의의 리스트 생성
data = np.random.rand(100)

print("Before sorting:", data)
comparisons_even, comparisons_odd = shell_sort(data)
print("After sorting:", data)
print("Comparisons (Even Interval):", comparisons_even)
print("Comparisons (Odd Interval):", comparisons_odd)
