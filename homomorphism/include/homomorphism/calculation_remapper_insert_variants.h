#ifndef HOMOMORPHISM_CALCULATION_REMAPPER_INSERT_VARIANTS_H
#define HOMOMORPHISM_CALCULATION_REMAPPER_INSERT_VARIANTS_H

#include <vector>

class CalculationRemapperInsertVarients {
public:
    void SetSizes(std::size_t n, std::size_t b);
    void InsertXYZ(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos);
    void InsertXZY(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos);
    void InsertYXZ(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos);
    void InsertYZX(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos);
    void InsertZXY(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos);
    void InsertZYX(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos);
private:
    std::size_t n_, b_;
    std::vector<std::size_t> powers_;
};

#endif
