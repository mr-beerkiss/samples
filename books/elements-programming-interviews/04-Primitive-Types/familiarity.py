print(f"6&4={6&4}")
print(f"1|2={1|2}")
print(f"8>>1={8>>1}")
print(f"-16>>2={-16>>2}")
print(f"1<<10={1<<10}")
print(f"~0={~0}")

A = 60
B = 13
# A = 60 = 0011 1100
# B = 13 = 0000 1101

# ~ Will 'flip' bits (Binary Ones operator)
# ~A = 1100 0011 = -61
print(f"~60={~60}")

# ^ is Binary XOR (exclusive OR; true if 1 and 0 but false if 1 and 1)
# A^B = 0011 0001
print(f"A^B={A^B}")