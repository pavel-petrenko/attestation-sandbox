#include <options.h>

#include <functional>
#include <iostream>

namespace mvj {
    static void tolower(std::string& in) {
        std::transform(in.begin(), in.end(), in.begin(), [](unsigned char c) { return std::tolower(c); });
    }
}

Options::Options(const std::vector<std::string>& args) {
    init();
    const size_t sz = args.size();
    if (sz < 2) {
        this->help_and_exit();
    }

    const std::unordered_map<std::string, OptionsMemFn> opt_setters({
        {"-v", &Options::set_verbose},
        {"--verbose", &Options::set_verbose},
        {"-h", &Options::help_and_exit},
        {"--help", &Options::help_and_exit}
        });
    const std::unordered_map<std::string, OptionsMemFn> arg_setters({
        {"-mrsigner", &Options::set_mrsigner},
        {"-mrenclave", &Options::set_mrenclave},
        {"-productid", &Options::set_productid},
        {"-svn", &Options::set_svn},
        {"-isdebuggable", &Options::set_debuggable},
        });

    for (size_t i = 1; i < sz; ++i) {
        std::string arg = args[i];
        mvj::tolower(arg);

        auto opt_it = opt_setters.find(arg);
        if (opt_it != opt_setters.end()) {
            std::invoke(opt_it->second, this, "");
            continue;
        }

        auto arg_it = arg_setters.find(arg);
        if (arg_it != arg_setters.end()) {
            if (i < (sz - 1)) {
                std::invoke(arg_it->second, this, args[1 + i++]);
                continue;
            }
            else {
                this->help_and_exit();
            }
        }

        if (this->jwt_filename.empty()) {
            this->jwt_filename = args[i];
            continue;
        }

        this->help_and_exit();
    }
}

void Options::maybe_dump() const {
    if (this->is_verbose) {
        std::cout << std::endl << "Arguments for this run:" << std::endl;
        std::cout << '\t' << "jwt_filename " << '\t' << ":" << '\t' << this->jwt_filename << std::endl;
        std::cout << '\t' << "mrsigner     " << '\t' << ":" << '\t' << this->mrsigner << std::endl;
        std::cout << '\t' << "productid    " << '\t' << ":" << '\t' << this->productid << std::endl;
        std::cout << '\t' << "mrenclave    " << '\t' << ":" << '\t' << this->mrenclave << std::endl;
        std::cout << '\t' << "svn          " << '\t' << ":" << '\t' << this->svn << std::endl;
        std::cout << '\t' << "debuggable   " << '\t' << ":" << '\t' << this->debuggable << std::endl;
    }
}

void Options::init() {
    this->is_verbose = false;
    this->jwt_filename = "";
    this->mrsigner = "";
    this->productid = "";
    this->mrenclave = "";
    this->svn = "";
    this->debuggable = false;
}

void Options::set_verbose(const std::string& v) { this->is_verbose = true; }
void Options::set_jwt_filename(const std::string& v) { this->jwt_filename = v; }
void Options::set_mrsigner(const std::string& v) { this->mrsigner = v; }
void Options::set_productid(const std::string& v) { this->productid = v; }
void Options::set_mrenclave(const std::string& v) { this->mrenclave = v; }
void Options::set_svn(const std::string& v) { this->svn = v; }
void Options::set_debuggable(const std::string& v) { 
    this->debuggable = !v.empty(); //TODO: fix me
}

void Options::help_and_exit(const std::string& v) {
    std::cout << std::endl;
    std::cout << "Usage: maavalidatejwt [options] file" << std::endl;
    std::cout << std::endl;
    std::cout << "Arguments:" << std::endl;
    std::cout << "    -mrsigner <value>        Verify MAA MRSIGNER value is <value>" << std::endl;
    std::cout << "    -mrenclave <value>       Verify MAA MRENCLAVE value is <value>" << std::endl;
    std::cout << "    -productid <value>       Verify MAA PRODUCTID value is <value>" << std::endl;
    std::cout << "    -svn <value>             Verify MAA SVN value is <value>" << std::endl;
    std::cout << "    -isdebuggable <value>    Verify MAA ISDEBUGGABLE value is <value>" << std::endl;
    std::cout << "    -v or --verbose          Include verbose messages during validation" << std::endl;
    std::cout << "    -h or --help             Print Help (this message) and exit" << std::endl;
    std::cout << std::endl;
    exit(EXIT_SUCCESS);
}
