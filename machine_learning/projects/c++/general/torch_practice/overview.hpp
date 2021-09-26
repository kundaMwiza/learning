#ifndef OVERVIEW
#define OVERVIEW

#include <iostream>
#include "torch/torch.h"
#include "dcgan.hpp"

// note that we can use functions such as register_parameter
// below because we have inherited from the Module class
// so do not need to use the namespace operator
class SimpleNetOne : public torch::nn::Module
{
public:
    SimpleNetOne(int64_t N, int64_t M)
    {
        W = register_parameter("W", torch::randn({N, M}));
        b = register_parameter("b", torch::randn(M));
    }

    torch::Tensor forward(torch::Tensor input)
    {
        return torch::addmm(b, input, W);
    }

    torch::Tensor W, b;
};

// the value semantics approach to using torch in c++
// through the TORCH_MODULE macro allows you to use
// reference semantics without having to use
// std::make_shared<> or std::shared_ptr<> in many places

class SimpleNetTwoImpl : public torch::nn::Module
{
public:
    // using value semantics, we have to construct
    // linear in the initializer section, since
    // a linear submodule is not default constructible
    // whereas tensor objects are default constructible
    // also note that torch::nn::Linear is actually
    // std::shared_ptr<LinearImpl>, which is why calling
    // forward results in us using the arrow operator

    SimpleNetTwoImpl(int64_t N, int64_t M)
        : linear(register_module("linear", torch::nn::Linear(N, M)))
    {
        b = register_parameter("b", torch::randn(M));
    }

    torch::Tensor forward(torch::Tensor input)
    {
        return linear->forward(input) + b;
    }

    torch::nn::Linear linear;
    torch::Tensor b;
};

TORCH_MODULE(SimpleNetTwo);

#endif