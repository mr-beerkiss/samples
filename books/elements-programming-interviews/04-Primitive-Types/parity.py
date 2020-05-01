# A = 60 = 0011 1100
# B = 13 = 0000 1101
A = 60
B = 13

def brute_force_parity(x):
    result = 0
    itrs = 0
    while x:
        result += x & 1
        x >>= 1
        itrs += 1
    print(f"brute_force_parity iterations = {itrs}")
    return result % 2

# brute force
def parity(x):
    result = 0
    itrs = 0
    while x:
        result ^= x & 1
        x >>= 1
        itrs += 1
    print(f"parity iterations = {itrs}")
    return result

# first improvement
def parity_imp_1(x):
    # use x&x-1 trick to erase the lowest bit set to 1
    # eg 2 = 10 so x = x & x - 1 will be zero since the lowest bi set to 1 is cleared,
    # and there is only one bit set to 1!
    result = 0
    itrs = 0
    while x:
        result ^= 1
        x &= x - 1
        itrs += 1
    print(f"parity_imp_1 iterations = {itrs}")
    return result


assert(brute_force_parity(2) == 1)
assert(brute_force_parity(3) == 0)
assert(brute_force_parity(A) == 0)
assert(brute_force_parity(B) == 1)

assert(parity(2) == 1)
assert(parity(3) == 0)
assert(parity(A) == 0)
assert(parity(B) == 1)

assert(parity_imp_1(2) == 1)
assert(parity_imp_1(3) == 0)
assert(parity_imp_1(A) == 0)
assert(parity_imp_1(B) == 1)