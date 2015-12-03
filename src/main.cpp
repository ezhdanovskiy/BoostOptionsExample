#include <iostream>
#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;

int main(int argc, char **argv) {
    std::string fileNameIn;
    std::string fileNameOut;
    size_t blockSize;
    po::options_description desc("Allowed options");
    try {
        desc.add_options()
                ("input-file,i", po::value<std::string>(&fileNameIn)->required(), "Input file name")
                ("output-file,o", po::value<std::string>(&fileNameOut)->required(), "Output file name")
                ("block-size,b", po::value<size_t>(&blockSize)->default_value(1024 * 1024), "Block size")
                ("help", "Produce help message");
        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        if (vm.count("help")) {
            std::cout << desc << "\n";
            return 1;
        }
        po::notify(vm);
        return 0;
    }
    catch (const po::error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cout << desc << "\n";
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Exception caught." << std::endl;
    }
    return 1;
}
