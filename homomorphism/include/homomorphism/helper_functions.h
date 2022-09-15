#ifndef HOMOMORPHISM_HELPERFUNCTIONS_H_
#define HOMOMORPHISM_HELPERFUNCTIONS_H_

#include <string>

class HelperFunctions
{
public:
    static bool hasPrefix(const std::string& str, const std::string& prefix);
    static bool hasSuffix(const std::string& str, const std::string& suffix);
    static bool saveToFile(const std::string& str, const std::string& filename);
    static std::string trimDreadnautOutput(std::ifstream& output, std::size_t n);
    static std::size_t pow(std::size_t n, std::size_t k);
};

#endif
