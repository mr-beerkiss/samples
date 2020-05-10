#include <fstream>
#include <string>
#include <iostream>

int main()
{

  std::ofstream writeToFile;
  std::ifstream readFromFile;
  std::string txtToWrite = "";
  std::string txtFromFile = "";

  // ios::app : append to the end of a file
  // ios::trunc : if file exists delete content first
  // ios::in : open file for reading
  // ios::out : open file for writing
  // ios::ate : open writing and move to end of the file

  writeToFile.open("test.txt", std::ios_base::out | std::ios_base::trunc);

  if (writeToFile.is_open())
  {
    writeToFile << "Beginning of file\n";
    std::cout << "Enter data to write to file: ";
    getline(std::cin, txtToWrite);
    writeToFile << txtToWrite << "\n";
    writeToFile.close();
  }

  std::cout << "\nReading form file..."
            << "\n";

  readFromFile.open("test.txt", std::ios_base::in);
  if (readFromFile.is_open())
  {
    while (readFromFile.good())
    {
      getline(readFromFile, txtFromFile);
      std::cout << txtFromFile << "\n";
    }
    readFromFile.close();
  }

  return 0;
}