#include <iostream>
#include <fstream>
#include <idlmm.hpp>
#include <ecorecpp.hpp> // EMF4CPP utils

#include "idl_parser.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "You must specify an IDL file" << std::endl;
        return 1;
    }

    idlmm::TranslationUnit_ptr res = idl::parse(argv[1]);
    bool err = (res == NULL);

    if (err)
        std::cerr << "Error!" << std::endl;
    else
    {
        std::ofstream ofs("model.xmi");
        ecorecpp::serializer::serializer ser(ofs); 
        ser.serialize(res);
    }

    delete res;
    return err;
}
