def isPrime(x : int) -> bool:
    if x == 2:
        return True
    if x % 2 == 0:
        return False

    for i in range(3, int(x**.5) + 1):
        if x % i == 0:
            return False
    return True

if __name__ == "__main__":
    x: int = int(input())

    if x >= 2:
        prime = isPrime(x)
        if prime:
            print(f"Yes, {x} is a Prime number")
        elif not prime:
            print(f"No, {x} is not Prime")

    else:
        print("ERROR")




