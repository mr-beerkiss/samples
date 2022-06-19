import pytest

from hashtable import HashTable

def test_should_report_length_of_empty_hash_table():
  assert len(HashTable(capacity=100)) == 0

def test_should_not_create_hashtable_with_zero_capacity():
  with pytest.raises(ValueError):
    HashTable(capacity=0)

def test_should_note_create_hashtable_with_negative_capacity():
  with pytest.raises(ValueError):
    HashTable(capacity=-100)

def test_should_report_length(hash_table):
  assert len(hash_table) == 3

def test_should_report_capacity_of_empty_hash_table():
  assert HashTable(capacity=100).capacity == 100

def test_should_report_capacity(hash_table):
  assert hash_table.capacity == 100
