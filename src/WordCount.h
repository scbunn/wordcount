#ifndef _WORDCOUNT_H_
#define _WORDCOUNT_H_

#include <iostream>
#include <string>
#include <sstream>

using output = std::ostream;
using input = std::istream;

// Aggregate class to store counts
struct WordCount {
  using wcsize = std::string::size_type;
  wcsize charcnt = 0;
  wcsize linecnt = 0;
  wcsize wordcnt = 0;
};

output& print(output& os, const WordCount& wc) {
  os << "\t" << wc.linecnt << "\t" << wc.wordcnt << "\t" << wc.charcnt
     << std::endl;
  return os;
}

input& read(input& is, WordCount& wc) {
  std::string line;
  std::string word;

  while (std::getline(is, line)) {
    ++wc.linecnt;
    std::istringstream words(line);
    while (words >> word) {
      ++wc.wordcnt; 
      wc.charcnt += word.size();
    }
  }

  return is;
}

#endif  // _WORDCOUNT_H_
