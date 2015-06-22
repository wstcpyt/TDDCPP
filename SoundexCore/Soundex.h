//
// Created by yutong pang on 6/21/15.
//

#ifndef TDDCPP_SOUNDEX_H
#define TDDCPP_SOUNDEX_H

#include <string>
#include <unordered_map>

class Soundex
{
public:
    static const size_t MaxCodeLength = 4;
    std::string encode(const std::string &word) const
    {
        return zeroPad(head(word) + encodedDigits(word));
    }

private:

    std::string head(const std::string& word) const{
        return word.substr(0, 1);
    }
    std::string encodedDigits(const std::string& word) const {
        if (word.length() > 1) return encodedDigit(word[1]);
        return "";
    }

    std::string encodedDigit(char letter) const {
        const std::unordered_map<char,std::string> encodings {
                {'b', "1"},
                {'c', "2"},
                {'d', "3"}
        };
        return encodings.find(letter) -> second;
    }
    std::string zeroPad(const std::string& word) const{
        auto zeroNeeded = MaxCodeLength - word.length();
        return word + std::string(zeroNeeded, '0');
    }
};

#endif //TDDCPP_SOUNDEX_H
