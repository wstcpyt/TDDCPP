//
// Created by yutong pang on 6/21/15.
//

#ifndef TDDCPP_SOUNDEX_H
#define TDDCPP_SOUNDEX_H

#include <string>
#include <unordered_map>
#include <map>

class Soundex
{
public:
    static const size_t MaxCodeLength = 4;
    std::string encode(const std::string &word) const
    {
        return zeroPad(upperFront(head(word)) + encodedDigits(tail(word)));
    }
    std::string encodedDigit(char letter) const {
        const std::unordered_map<char,std::string> encodings{
                {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
                {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
                {'s', "2"}, {'x', "2"}, {'z', "2"},
                {'d', "3"}, {'t', "3"},
                {'l', "4"},
                {'m', "5"}, {'n', "5"},
                {'r', "6"}
        };
        auto it = encodings.find(letter);
        return it == encodings.end() ? "": it-> second;
    }

private:
    std::string upperFront(const std::string& string) const {
        return std::string(1,
        std::toupper(static_cast<unsigned char>(string.front())));
    }

    std::string head(const std::string& word) const{
        return word.substr(0, 1);
    }

    std::string tail(const std::string& word) const {
        return word.substr(1);
    }

    std::string encodedDigits(const std::string& word) const {
        std::string encoding;
        for (auto letter: word)
        {
            if (isComplete(encoding)) break;
            if (encodedDigit(letter) != lastDigit(encoding))
            encoding += encodedDigit(letter);
        }
        return encoding;
    }

    std::string lastDigit(const std::string& encoding) const {
        if(encoding.empty()) return "";
        return std::string(1, encoding.back());
    }

    bool isComplete (const std::string& encoding) const {
        return encoding.length() == MaxCodeLength - 1;
    }

    std::string zeroPad(const std::string& word) const{
        auto zeroNeeded = MaxCodeLength - word.length();
        return word + std::string(zeroNeeded, '0');
    }
};

#endif //TDDCPP_SOUNDEX_H
