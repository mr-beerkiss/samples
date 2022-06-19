import pytest
from hashtable import HashTable

@pytest.fixture
def hash_table():
  sample_data = HashTable(capacity=100)

  sample_data["hola"] = "hello"
  sample_data[98.6] = 37
  sample_data[False] = True

  return sample_data
