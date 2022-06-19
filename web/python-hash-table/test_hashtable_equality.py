# import pytest
from pytest_unordered import unordered 

from hashtable import HashTable

def test_should_compare_equal_to_itself(hash_table):
  assert hash_table == hash_table

def test_should_compare_equal_to_copy(hash_table):
  assert hash_table is not hash_table.copy()
  assert hash_table == hash_table.copy()

def test_should_compare_equal_different_key_value_order():
  h1 = HashTable.from_dict({"a": 1, "b": 2, "c": 3})
  h2 = HashTable.from_dict({"b": 2, "a": 1, "c": 3})

  assert h1 == h2

def test_should_compare_unequal(hash_table):
  other = HashTable.from_dict({"different": "value"})
  assert hash_table != other

def test_should_compare_unequal_another_data_type(hash_table):
  assert hash_table != 42

def test_should_copy_keys_values_pairs_capacity(hash_table):
  copy = hash_table.copy()
  assert copy is not hash_table
  assert set(hash_table.keys) == set(copy.keys)
  assert unordered(hash_table.values) == copy.values
  assert set(hash_table.pairs) == set(copy.pairs)
  assert hash_table.capacity == copy.capacity

def test_should_compare_equal_different_capacity():
  data = {"a": 1, "b": 2, "c": 3}
  h1 = HashTable.from_dict(data, capacity=50)
  h2 = HashTable.from_dict(data, capacity=100)

  assert h1 == h2

