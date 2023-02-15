#include "global_wrapper.hpp"

int main()
{
        globalWrapper::program_name("hhGPT");
        globalWrapper::version_stamp("beta");
        globalWrapper::version_number(1);
        globalWrapper::tests_run(10);
        globalWrapper::tests_passed(9);

        std::cout << "== Information ==" << std::endl;
        std::cout << "program_name >> " << globalWrapper::program_name() << std::endl;
        std::cout << "version_stamp >> " << globalWrapper::version_stamp() << std::endl;
        std::cout << "version_number >> " << globalWrapper::version_number() << std::endl;
        std::cout << "tests_run >> " << globalWrapper::tests_run() << std::endl;
        std::cout << "tests_passed >> " << globalWrapper::tests_passed() << std::endl;

        return 0;
}
