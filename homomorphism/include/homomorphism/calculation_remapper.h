#ifndef HOMOMORPHISM_CALCULATION_REMAPPER_H
#define HOMOMORPHISM_CALCULATION_REMAPPER_H

#include "homomorphism/remapper.h"

class CalculationRemapper : public Remapper {
public:
    void SetSizes(std::size_t n, std::size_t b) override;
    void Extract(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos) override;
    void Insert(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos) override;
private:
    std::size_t n_, b_;
    std::vector<std::size_t> powers_;
};

#endif
