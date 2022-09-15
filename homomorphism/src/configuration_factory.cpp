#include "homomorphism/introduce_handler_compute.h"
#include "homomorphism/introduce_handler_least_precomputed.h"
#include "homomorphism/vector_allocator_default.h"
#include "homomorphism/vector_allocator_pooling.h"
#include "homomorphism/configuration_factory.h"

#include "homomorphism/calculation_remapper.h"
#include "homomorphism/forget_handler_combined.h"
#include "homomorphism/iterator_remapper.h"
#include "homomorphism/introduce_handler_precomputed.h"


HomomorphismSettings ConfigurationFactory::defaultSettings(std::size_t n, std::size_t maxWidth) {
    return {std::make_shared<CalculationRemapper>(), std::make_shared<ForgetHandlerLast>(n, maxWidth),
            std::make_shared<IntroduceHandlerCompute>(), std::make_shared<JoinHandler>(),
            std::make_shared<VectorAllocatorPooling>(BagSizes(n, maxWidth))};
}

HomomorphismSettings ConfigurationFactory::PrecomputedSettings(std::size_t n, std::size_t maxWidth,
                            std::shared_ptr<EdgeConsistencyPrecomputation> precomputation) {
    return {std::make_shared<CalculationRemapper>(), std::make_shared<ForgetHandlerLast>(n, maxWidth),
            std::make_shared<IntroduceHandlerLeastPrecomputed>(precomputation), std::make_shared<JoinHandler>(),
            std::make_shared<VectorAllocatorPooling>(BagSizes(n, maxWidth))};
}

HomomorphismSettings ConfigurationFactory::iteratorRemapper(std::size_t n, std::size_t maxWidth) {
    return {std::make_shared<IteratorRemapper>(), std::make_shared<ForgetHandlerLast>(n, maxWidth),
            std::make_shared<IntroduceHandlerCompute>(), std::make_shared<JoinHandler>(),
            std::make_shared<VectorAllocatorPooling>(BagSizes(n, maxWidth))};
}

PathdecompotisionSettings ConfigurationFactory::DefaultPathSettings(std::size_t n, std::size_t maxWidth) {
    return {std::make_shared<ForgetHandlerCombined>(n, maxWidth),
            std::make_shared<IntroduceHandlerCompute>(),
            std::make_shared<VectorAllocatorPooling>(BagSizes(n, maxWidth))};
}

PathdecompotisionSettings ConfigurationFactory::PrecomputedPathSettings(std::size_t n, std::size_t maxWidth,
                        std::shared_ptr<EdgeConsistencyPrecomputation> precomputation) {
    return {std::make_shared<ForgetHandlerCombined>(n, maxWidth),
            std::make_shared<IntroduceHandlerLeastPrecomputed>(precomputation),
            std::make_shared<VectorAllocatorPooling>(BagSizes(n, maxWidth))};
}

PathdecompotisionSettings ConfigurationFactory::PrecomputedPathSettingsNonpooled(std::size_t n, std::size_t maxWidth,
        std::shared_ptr<EdgeConsistencyPrecomputation> precomputation) {
    return {std::make_shared<ForgetHandlerCombined>(n, maxWidth),
            std::make_shared<IntroduceHandlerLeastPrecomputed>(precomputation),
            std::make_shared<VectorAllocatorDefault>(BagSizes(n, maxWidth))};
}

DynamicProgrammingSettings ConfigurationFactory::DefaultDynamicSettings(std::size_t n, std::size_t maxWidth,
        std::shared_ptr<EdgeConsistencyPrecomputation> precomputationLeast,
        std::shared_ptr<EdgeConsistencyPrecomputation> precomputationSecond) {
    return {std::make_shared<ForgetHandlerCombined>(n, maxWidth),
            std::make_shared<IntroduceHandlerPrecomputed>(n, maxWidth, precomputationLeast, precomputationSecond),
            std::make_shared<JoinHandler>(), std::make_shared<VectorAllocatorPooling>(BagSizes(n, maxWidth))};
}

DynamicProgrammingSettings ConfigurationFactory::DynamicSettingsNonpooled(std::size_t n, std::size_t maxWidth,
        std::shared_ptr<EdgeConsistencyPrecomputation> precomputationLeast,
        std::shared_ptr<EdgeConsistencyPrecomputation> precomputationSecond) {
    return {std::make_shared<ForgetHandlerCombined>(n, maxWidth),
            std::make_shared<IntroduceHandlerPrecomputed>(n, maxWidth, precomputationLeast, precomputationSecond),
            std::make_shared<JoinHandler>(), std::make_shared<VectorAllocatorDefault>(BagSizes(n, maxWidth))};
}

std::pair<DynamicProgrammingSettings, PathdecompotisionSettings> ConfigurationFactory::DefaultPrecomputedSettings(std::size_t n, std::size_t maxWidth,
        std::shared_ptr<EdgeConsistencyPrecomputation> precomputationLeast, std::shared_ptr<EdgeConsistencyPrecomputation> precomputationSecond) {
    auto forget = std::make_shared<ForgetHandlerCombined>(n, maxWidth);
    auto introduce = std::make_shared<IntroduceHandlerPrecomputed>(n, maxWidth, precomputationLeast, precomputationSecond);
    auto introduce2 = std::make_shared<IntroduceHandlerLeastPrecomputed>(precomputationLeast);
    auto join = std::make_shared<JoinHandler>();
    auto pool = std::make_shared<VectorAllocatorPooling>(BagSizes(n, maxWidth));
    return std::make_pair<DynamicProgrammingSettings, PathdecompotisionSettings>({forget, introduce, join, pool}, {forget, introduce2, pool});
}

std::pair<DynamicProgrammingSettings, PathdecompotisionSettings> ConfigurationFactory::NonpoolingPrecomputedSettings(std::size_t n, std::size_t maxWidth,
         std::shared_ptr<EdgeConsistencyPrecomputation> precomputationLeast, std::shared_ptr<EdgeConsistencyPrecomputation> precomputationSecond) {
    auto forget = std::make_shared<ForgetHandlerCombined>(n, maxWidth);
    auto introduce = std::make_shared<IntroduceHandlerPrecomputed>(n, maxWidth, precomputationLeast, precomputationSecond);
    auto introduce2 = std::make_shared<IntroduceHandlerLeastPrecomputed>(precomputationLeast);
    auto join = std::make_shared<JoinHandler>();
    auto pool = std::make_shared<VectorAllocatorDefault>(BagSizes(n, maxWidth));
    return std::make_pair<DynamicProgrammingSettings, PathdecompotisionSettings>({forget, introduce, join, pool}, {forget, introduce2, pool});
}
