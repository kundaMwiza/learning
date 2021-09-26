#include <cstdlib>
#include <iostream>
#include "overview.hpp"
#include "dcgan.hpp"
#include "torch/torch.h"

using namespace torch;

template <typename DataLoaderType>
void train_model(
    DCGANGenerator &gen, nn::Sequential &disc, optim::Adam &gen_optim, optim::Adam &disc_optim, DataLoaderType &dataloader, const int64_t &n_epochs)
{

    for (int64_t epoch = 1; epoch != n_epochs; ++epoch)
    {
        int64_t batch_index = 0;
        for (data::Example<> &batch : *dataloader)
        {

            // forward pass discriminator with real images
            discriminator->zero_grad();
            Tensor real_images = batch.data;
            Tensor real_labels = torch::empty(batch.data.size(0)).uniform_(0.8, 1.0);
            Tensor real_output = disc->forward(real_images);
            Tensor d_loss_real = torch::binary_cross_entropy(real_output, real_labels);

            // accumulate gradients
            d_loss_real.backward();

            // forward pass discriminator with fake images
            Tensor noise = torch::randn({batch.data.size(0), 100, 1, 1});
            Tensor fake_images = gen->forward(noise);
            Tensor fake_labels = torch::zeros(batch.data.size(0));
            Tensor fake_output = disc->forward(fake_images.detach());
            Tensor d_loss_fake = binary_cross_entropy(fake_output, fake_labels);
            d_loss_fake.backward();

            Tensor d_loss = d_loss_real + d_loss_fake;
            disc_optim.step();

            // train generator
            gen->zero_grad();
            fake_labels.fill_(1);
            fake_output = disc->forward(fake_images);
            Tensor g_loss = binary_cross_entropy(fake_output, fake_labels);

            // accumulate gradients
            g_loss.backward();
            gen_optim.step();

            std::printf(
                "\r[%2ld/%2ld][%3ld/%3ld] D_loss: %.4f | G_loss: %.4f",
                epoch,
                100,
                ++batch_index,
                50,
                d_loss.item<float>(),
                g_loss.item<float>());
        }
    }
}
// good resource on how to compose custom transforms https://pytorch.org/tutorials/beginner/data_loading_tutorial.html
// good resource on an introduction to torch datasets and dataloaders https://stanford.edu/~shervine/blog/pytorch-how-to-generate-data-parallel
int main(int argc, const char *argv[])
{
    // torch::Tensor tensor = torch::rand({2, 3});
    // std::cout << tensor << std::endl;
    const unsigned int ft_size = 5;
    const unsigned int ot_size = 3;
    unsigned int n_examples = 4;

    // SimpleNetTwo test(ft_size, ot_size);

    // torch::Tensor out = test->forward(torch::rand({n_examples, ft_size}));

    // std::cout << "output from forward method" << std::endl;
    // std::cout << out << std::endl;

    // std::cout << "\n"
    //           << std::endl;

    // for (const auto &p : test->parameters())
    // {
    //     std::cout << p << std::endl;
    // }

    // for (const auto &pair : test->named_parameters())
    // {
    //     std::cout << pair.key() << ": " << pair.value() << std::endl;
    // }

    DCGANGenerator dcgan(100);

    auto dataset = data::datasets::MNIST("./mnist")
                       .map(data::transforms::Normalize<>(0.5, 0.5))
                       .map(data::transforms::Stack<>());

    // transfer ownership of torch dataset to the dataset member
    // inside the torch dataloader
    auto data_loader = data::make_data_loader(
        std::move(dataset),
        data::DataLoaderOptions().batch_size(64).workers(2));

    // use default template types with batch
    for (data::Example<> &batch : *data_loader)
    {
        std::cout << "Batch size: " << batch.data.size(0) << " | Labels: " << std::endl;
        for (int64_t i = 0; i < batch.data.size(0); ++i)
        {
            std::cout << batch.target[i].item<int64_t>() << " ";
            std::cout << batch.data.sizes() << std::endl;
        }
        std::cout << std::endl;
    }

    // implement two torch optimizers

    optim::Adam generator_opt(
        dcgan->parameters(), optim::AdamOptions(2e-4).betas(std::make_tuple(0.5, 0.99)));

    optim::Adam discriminator_opt(
        discriminator->parameters(), optim::AdamOptions(5e-4).betas(std::make_tuple(0.5, 0.99)));

    // train_model(
    //     dcgan,
    //     discriminator,
    //     generator_opt,
    //     discriminator_opt,
    //     data_loader,
    //     10);

    return EXIT_SUCCESS;
}