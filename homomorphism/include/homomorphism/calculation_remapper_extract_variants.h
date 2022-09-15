#ifndef HOMOMORPHISM_CALCULATION_REMAPPER_EXTRACT_VARIANTS_H
#define HOMOMORPHISM_CALCULATION_REMAPPER_EXTRACT_VARIANTS_H

#include <vector>

class CalculationRemapperExtractVarients {
public:
    void SetSizes(std::size_t n, std::size_t b);
    void ExtractXYZ(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos);
    void ExtractXZY(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos);
    void ExtractYXZ(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos);
    void ExtractYZX(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos);
    void ExtractZXY(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos);
    void ExtractZYX(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos);
private:
    std::size_t n_, b_;
    std::vector<std::size_t> powers_;
};

#endif
