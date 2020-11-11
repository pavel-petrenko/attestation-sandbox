#include <iostream>
#include <vector>

bool is_verbose(const std::vector<std::string>& argvec);
std::string get_value(int idx, const std::vector<std::string> & argvec, bool verbose, const std::string & argname, const std::string & default_value);

int main(int argc, char* argv[], char* envp[]) {
    //std::cout << std::endl << "I'm alive..." << std::endl;

    std::vector<std::string> argvec(argc, "");
    for (int count = 0; count < argc; count++)
        argvec[count] = argv[count];
    
    bool verbose = is_verbose(argvec);
    if (argvec.size() < 2 || argvec[1] == "--help" || argvec[1] == "-h" || (argvec.size() < 3 && verbose)) {
        std::cout << std::endl;
        std::cout << "Usage: maavalidatejwt [options] file" << std::endl;
        std::cout << std::endl;
        std::cout << "Arguments:" << std::endl;
        std::cout << "    -mrsigner <value>        Verify MAA MRSIGNER value is <value>" << std::endl;
        std::cout << "    -mrenclave <value>       Verify MAA MRENCLAVE value is <value>" << std::endl;
        std::cout << "    -productid <value>       Verify MAA PRODUCTID value is <value>" << std::endl;
        std::cout << "    -svn <value>             Verify MAA SVN value is <value>" << std::endl;
        std::cout << "    -isdebuggable <value>    Verify MAA ISDEBUGGAble value is <value>" << std::endl;
        std::cout << "    -v or --verbose          Include verbose messages during validation" << std::endl;
        std::cout << "    -h or --help             Print Help (this message) and exit" << std::endl;
        std::cout << std::endl;
/*         std::cout << "Usage: validatejwt[.exe]    [file..]" << '\t' << "Validate jwt token and return 0 (SUCCESS) or 1 (FAILURE)" << std::endl;
        std::cout << "   or: validatejwt[.exe] -v [file..]" << '\t' << "Enable verbose mode. Validate jwt token and return 0 (SUCCESS) or 1 (FAILURE)" << std::endl;
        std::cout << "   or: validatejwt[.exe]    [file..] [certificate]" << std::endl;
        std::cout << "   or: validatejwt[.exe]    [file..] [certificate] [mrsigner] [productid] [mrenclave] [securityversion]" << std::endl;
        std::cout << std::endl;
        std::cout << "Arguments:" << std::endl;
        std::cout << '\t' << "-v or --verbose" << '\t' << "Enable verbose mode" << std::endl;
        std::cout << '\t' << "-h or --help" << '\t' << "Print Help (this message) and exit" << std::endl;
 */
        exit(EXIT_SUCCESS);
    }

    if (verbose) {
        std::cout << std::endl << "Arguments for this run:" << std::endl;
    }

    std::string jwt_file_name = get_value(1, argvec, verbose, "Validating filename", "default_filename");
    std::string cert = get_value(2, argvec, verbose, "Certificate", "");
    std::string mrsigner = get_value(3, argvec, verbose, "Expected MrSigner", "");
    std::string prodid = get_value(4, argvec, verbose, "Expected ProductId", "");
    std::string mrenclave = get_value(5, argvec, verbose, "Expected MrEnclave", "");
    std::string securityver = get_value(6, argvec, verbose, "Expected SecurityVersion", "");

    // WRITE ME

    return EXIT_SUCCESS;
}

bool is_verbose(const std::vector<std::string>& argvec) {
    return (argvec.size() > 1) && (argvec[1].compare("-v") == 0 || argvec[1].compare("--verbose") == 0);
}

std::string get_value(int idx, const std::vector<std::string>& argvec, bool verbose, const std::string& argname, const std::string& default_value) {
    std::string result = argvec.size() > (idx + (size_t)verbose) ? argvec[idx + (size_t)verbose] : default_value;
    if (verbose && !result.empty()) {
        std::cout << '\t' << argname << '\t' << ":" << '\t' << result << std::endl;
    }
    return result;
}
