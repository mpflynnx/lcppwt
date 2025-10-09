#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>
#include <unordered_map>

class Soundex {
 public:
  static const size_t MaxCodeLength{4};

  std::string encode(const std::string &word) const {
    return zeroPad(upperFront(head(word)) + tail(encodedDigits(word)));
  }

 private:
  // https://en.cppreference.com/w/cpp/string/byte/toupper.html
  // https://en.cppreference.com/w/cpp/string/basic_string/front.html
  std::string upperFront(const std::string &string) const {
    return std::string(
        1, std::toupper(static_cast<unsigned char>(string.front())));
  }

  std::string head(const std::string &word) const { return word.substr(0, 1); }

  std::string tail(const std::string &word) const { return word.substr(1); }

  const std::string NotADigit{"*"};

  std::string encodedDigits(const std::string &word) const {
    std::string encoding;
    encoding += encodedDigit(word.front());

    for (auto letter : tail(word)) {
      if (isComplete(encoding)) break;
      auto digit = encodedDigit(letter);
      if (digit != NotADigit && digit != lastDigit(encoding)) {
        encoding += digit;
      }
    }
    return encoding;
  }

  bool isComplete(const std::string &encoding) const {
    return encoding.length() == MaxCodeLength;
  }

  std::string encodedDigit(char letter) const {
    const std::unordered_map<char, std::string> encodings{
        {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"}, {'c', "2"}, {'g', "2"},
        {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
        {'d', "3"}, {'t', "3"}, {'l', "4"}, {'m', "5"}, {'n', "5"}, {'r', "6"}};

    auto it = encodings.find(tolower(letter));
    if (it != encodings.end()) {
      return it->second;
    }

    return NotADigit;
  }

  std::string zeroPad(const std::string &word) const {
    auto ZerosRequired = MaxCodeLength - word.length();
    return word + std::string(ZerosRequired, '0');
  }

  // https://en.cppreference.com/w/cpp/string/basic_string/back.html
  // https://en.cppreference.com/w/cpp/string/basic_string/empty.html
  std::string lastDigit(const std::string &encoding) const {
    if (encoding.empty()) return NotADigit;
    return std::string(1, encoding.back());
  }

  // https://en.cppreference.com/w/cpp/string/byte/tolower.html
  char tolower(char ch) const {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
  }
};

#endif /* SOUNDEX_H */
