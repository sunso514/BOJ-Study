def long_size_calculate(A, B):
    return (A+B), (A-B), (A*B)

if __name__ == "__main__":
    A = int(input())
    B = int(input())
    
    for answer in long_size_calculate(A, B):
        print(answer)