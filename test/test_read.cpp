#include <iostream>
#include <idlmm.hpp>
#include <parser/idl_parser.hpp>

int main(int argc, char **argv)
{
    idlmm::TranslationUnit_ptr res = NULL;

    if (argc < 2)
        res = idl::parse(std::cin);
    else
        res = idl::parse(argv[1]);

    bool err = (res == NULL);

    if (err)
        std::cerr << "Error!" << std::endl;

    delete res;
    return err;
}
