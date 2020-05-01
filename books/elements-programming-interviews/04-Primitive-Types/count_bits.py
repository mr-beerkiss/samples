def count_bits(x):
    num_bits = 0;
    while x:
        num_bits += x & 1
        x >>= 1
    return num_bits


assert(count_bits(1) == 1);
assert(count_bits(7) == 3);
assert(count_bits(16) == 1);