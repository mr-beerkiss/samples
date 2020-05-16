#include <regex>
#include <iostream>

void PrintMatches_bad(std::string str, std::regex reg)
{
  std::smatch matches;
  std::cout << std::boolalpha;

  while (std::regex_search(str, matches, reg))
  {
    // std::cout << "Is there a match: " << matches.ready() << "\n";
    // std::cout << "Are there no matches: " << matches.empty() << "\n";

    // std::cout << "Number of matches: " << matches.size() << "\n";

    std::cout << matches.str(1) << "\n";

    str = matches.suffix().str();
    std::cout << std::endl;
  }
}

void PrintMatches(std::string str, std::regex reg)
{
  std::sregex_iterator currentMatch(str.begin(), str.end(), reg);
  std::sregex_iterator lastMatch;

  while (currentMatch != lastMatch)
  {
    std::smatch match = *currentMatch;
    std::cout << match.str() << "\n";
    currentMatch++;
  }
  std::cout << std::endl;
}

int main()
{
  std::string str = "The ape was at the apex";

  std::regex reg("(ape[^ ]?)");

  PrintMatches(str, reg);

  std::string str2 = "I picked the pickle";
  std::regex reg2("(pick([^ ]+)?)");

  PrintMatches(str2, reg2);

  std::string str3 = "Cat rat mat fat pat";
  std::regex reg3("[crmfp]at");

  PrintMatches(str3, reg3);

  std::regex reg4("[C-Fc-f]at");
  PrintMatches(str3, reg4);

  std::regex reg5("[^Cr]at");
  PrintMatches(str3, reg5);

  std::regex reg6("[Cr]at");
  std::string owlFood = std::regex_replace(str3, reg6, "Owl");

  std::cout << owlFood << "\n";

  std::string str4 = "F.B.I. I.R.S. CIA";
  std::regex reg7("([^ ]\\..\\..\\.)");

  PrintMatches(str4, reg7);

  std::string str8 = "This is a\nmultiline string\n"
                     "that has many lines";
  std::regex reg8("\n");

  std::string noLBStr = std::regex_replace(str8, reg8, "");
  std::cout << noLBStr << "\n";

  std::string str9 = "12345";
  std::regex reg9("\\d");
  PrintMatches(str9, reg9);

  std::string str10 = "123 12345 123456 123467";
  std::regex reg10("\\d{5,7}");
  PrintMatches(str10, reg10);

  std::string str11 = "412-867-5309";
  std::regex reg11("\\w{3}-\\w{3}-\\w{4}");
  PrintMatches(str11, reg11);

  std::string str12 = "Toshio Muramatsu";
  std::regex reg12("\\w{2,20}\\s\\w{2,20}");
  PrintMatches(str12, reg12);

  std::string str13 = "a as ape bug";
  std::regex reg13("a[a-z]+");
  PrintMatches(str13, reg13);

  // email regex
  // 1. 1 to 20 lowercase, uppercase, numbers, ._%+-
  // 2. @ symbol
  // 3. 2 to 20 lowercase, uppercase, numbers, .-
  // 4. a period
  // 5. 2 to 3 lowercase, uppercase
  std::string str14 = "db@aol.com m@.com @apple.com db@.com";
  std::regex reg14("[\\w._%+-]{1,20}@[\\w.-]{2,20}.[A-z]{2,3}");
  PrintMatches(str14, reg14);

  return 0;
}