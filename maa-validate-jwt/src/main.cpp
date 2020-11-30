#include <vector>
#include <cctype>
#include <options.h>

int main(int argc, char* argv[], char* envp[]) {
    std::vector<std::string> argvec(argc, "");
    for (int count = 0; count < argc; count++) argvec[count] = argv[count];
    Options opts(argvec);
    opts.maybe_dump();
    // TODO: WRITE ME
    return EXIT_SUCCESS;
}
