#include "homomorphism/calculation_remapper.h"

void CalculationRemapper::Extract(std::vector <std::size_t>& in, std::vector <std::size_t>& out, std::size_t pos) {
    std::size_t xMax = powers_[pos];
    std::size_t yMax = powers_[b_ - pos - 1];
    std::size_t zMax = n_;

    std::size_t xOff = n_;
    std::size_t yOff = powers_[pos + 1];
    std::size_t zOff = powers_[pos];

    //TODO: Try different orderings
    for (std::size_t y = 0; y < yMax; ++y) {
        for (std::size_t z = 0; z < zMax; ++z) {
            for (std::size_t x = 0; x < xMax; ++x) {
                // TODO: Store partial offsets?
                out[xOff * x + yOff * y + z] = in[x + yOff * y + zOff * z];
            }
        }
    }
}

void CalculationRemapper::Insert(std::vector<std::size_t>& in, std::vector <std::size_t>& out, std::size_t pos) {
    std::size_t xMax = powers_[pos];
    std::size_t yMax = powers_[b_ - pos - 1];
    std::size_t zMax = n_;

    std::size_t xOff = n_;
    std::size_t yOff = powers_[pos + 1];
    std::size_t zOff = powers_[pos];

    //TODO: Try different orderings
    for (std::size_t y = 0; y < yMax; ++y) {
        for (std::size_t z = 0; z < zMax; ++z) {
            for (std::size_t x = 0; x < xMax; ++x) {
                // TODO: Store partial offsets?
                out[x + yOff * y + zOff * z] = in[xOff * x + yOff * y + z];
            }
        }
    }
}

void CalculationRemapper::SetSizes(std::size_t n, std::size_t b) {
    n_ = n;
    b_ = b;
    powers_.resize(b_ + 1);

    powers_[0] = 1;
    for (std::size_t i = 1; i < powers_.size(); ++i) {
        powers_[i] = powers_[i - 1] * n_;
    }
}
