#include <iostream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char **argv) {
    std::string fileNameIn;
    std::string fileNameOut;
    size_t blockSize;
    po::options_description desc("Allowed options");
    try {
        desc.add_options()
//                ("input-file,i", po::value<std::string>(&fileNameIn)->required(), "Input file name")
//                ("block-size,b", po::value<size_t>(&blockSize)->default_value(1024 * 1024), "Block size")
//                ("analyzeUniqueUsers", "Count unique users")
//                ("makeUsersFlow", "Creates users flow and NAMED_DUMP it")
                ("opt", po::value<std::vector<std::string> >()->multitoken(), "description")
                ("help", "Produce help message");
        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);

        if (vm.count("help")) {
            std::cout << desc;
            return 0;
        }

        po::notify(vm);

        if (vm.count("analyzeUniqueUsers")) {
            std::cout << "do analyzeUniqueUsers" << std::endl;
        }
        if (vm.count("makeUsersFlow")) {
            std::cout << "do makeUsersFlow" << std::endl;
        }

        std::vector<std::string> opts;
        if (!vm["opt"].empty()) {
            opts = vm["opt"].as<std::vector<std::string>>();
            for (auto &opt : opts) {
                std::cout << "opt = " << opt << std::endl;
            }
        }

        return 0;
    }
    catch (const po::error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cout << desc << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Exception caught." << std::endl;
    }
    return 1;
}
