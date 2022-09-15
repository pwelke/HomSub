#ifndef HOMOMORPHISM_CONFIGURATION_FACTORY_H
#define HOMOMORPHISM_CONFIGURATION_FACTORY_H

#include "homomorphism/dynamic_programming_counter.h"
#include "homomorphism/homomorphism_counter.h"
#include "homomorphism/pathdecomposition_counter.h"
#include "homomorphism/edge_consistency_precomputation.h"

class ConfigurationFactory {
public:
    static HomomorphismSettings defaultSettings(std::size_t n, std::size_t maxWidth);
    static HomomorphismSettings PrecomputedSettings(std::size_t n, std::size_t maxWidth,
                                                    std::shared_ptr<EdgeConsistencyPrecomputation> precomputation);
    static HomomorphismSettings iteratorRemapper(std::size_t n, std::size_t maxWidth);
    static PathdecompotisionSettings DefaultPathSettings(std::size_t n, std::size_t maxWidth);
    static PathdecompotisionSettings PrecomputedPathSettings(std::size_t n, std::size_t maxWidth,
                                                        std::shared_ptr<EdgeConsistencyPrecomputation> precomputation);
    static PathdecompotisionSettings PrecomputedPathSettingsNonpooled(std::size_t n, std::size_t maxWidth,
                                                             std::shared_ptr<EdgeConsistencyPrecomputation> precomputation);
    static DynamicProgrammingSettings DefaultDynamicSettings(std::size_t n, std::size_t maxWidth,
                                             std::shared_ptr<EdgeConsistencyPrecomputation> precomputationLeast,
                                             std::shared_ptr<EdgeConsistencyPrecomputation> precomputationSecond);
    static DynamicProgrammingSettings DynamicSettingsNonpooled(std::size_t n, std::size_t maxWidth,
                                                             std::shared_ptr<EdgeConsistencyPrecomputation> precomputationLeast,
                                                             std::shared_ptr<EdgeConsistencyPrecomputation> precomputationSecond);
    static std::pair<DynamicProgrammingSettings, PathdecompotisionSettings>
                                DefaultPrecomputedSettings(std::size_t n, std::size_t maxWidth,
                                                             std::shared_ptr<EdgeConsistencyPrecomputation> precomputationLeast,
                                                             std::shared_ptr<EdgeConsistencyPrecomputation> precomputationSecond);
    static std::pair<DynamicProgrammingSettings, PathdecompotisionSettings>
                                NonpoolingPrecomputedSettings(std::size_t n, std::size_t maxWidth,
                                                           std::shared_ptr<EdgeConsistencyPrecomputation> precomputationLeast,
                                                           std::shared_ptr<EdgeConsistencyPrecomputation> precomputationSecond);
};

#endif
