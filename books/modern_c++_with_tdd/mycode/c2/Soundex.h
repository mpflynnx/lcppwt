#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

class Soundex {
 public:
  std::string encode(const std::string &word) const { return zeroPad(word); }

 private:
  std::string head(const std::string &word) const { return word.substr(0,1); }

  std::string zeroPad(const std::string &word) const {
    auto ZerosRequired = 4 - word.size();
    return word + std::string(ZerosRequired, '0');
  }
};

#endif /* SOUNDEX_H */
