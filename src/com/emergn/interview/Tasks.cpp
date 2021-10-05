#include <com/emergn/interview/Tasks.h>

#include <cctype>
#include <string>

namespace com::emergn::interview {

namespace {
const std::string ENGLISH_ALPHABET{"abcdefghijklmnopqrstuvwxyz"};
const std::string ENGLISH_ALPHABET_UPPER_CASE{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
}  // namespace

bool isRotationString(const std::string& originalString, const std::string& rotationString)
{
    bool isRotation{false};

    if (originalString.size() != rotationString.size()) {
        return isRotation;
    }

    const std::string doubleOriginalString{originalString + originalString};

    if (doubleOriginalString.find(rotationString) != std::string::npos) {
        isRotation = true;
    }

    return isRotation;
}

std::string getMissingLetters(const std::string& testString)
{
    if (testString.empty()) {
        return std::string(ENGLISH_ALPHABET_UPPER_CASE);
    }

    std::string missingLetters;

    for (const auto& letter : ENGLISH_ALPHABET) {
        if (testString.find_first_of(letter) == std::string::npos) {
            const char letterUpperCase = std::toupper(letter);
            if (testString.find_first_of(letterUpperCase) == std::string::npos) {
                missingLetters += letterUpperCase;
            }
        }
    }

    return missingLetters;
}

}  // namespace com::emergn::interview
