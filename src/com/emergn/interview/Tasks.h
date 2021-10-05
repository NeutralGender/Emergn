#pragma once

#include <string>

namespace com::emergn::interview {

/**
 * @brief Problem 1: Check if rotationString is a rotation of orinalString.
 *
 * @param orinalString Original string.
 * @param rotationString Test string.
 */
bool isRotationString(const std::string& orinalString, const std::string& rotationString);

/**
 * @brief Problem 2: Get Missing alphabet letters from test string.
 *
 * @param testString Test string
 */
std::string getMissingLetters(const std::string& testString);

}  // namespace com::emergn::interview
