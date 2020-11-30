#pragma once

#include <unordered_map>
#include <algorithm>
#include <string>

class Options
{
private:
    typedef void (Options::* OptionsMemFn)(const std::string&);

    bool is_verbose;
    std::string jwt_filename;
    std::string mrsigner;
    std::string productid;
    std::string mrenclave;
    std::string svn;
    bool debuggable;

    Options();

public:

    explicit Options(const std::vector<std::string>& args);
    void maybe_dump() const;

private:
    void init();
    void set_verbose(const std::string& v);
    void set_jwt_filename(const std::string& v);
    void set_mrsigner(const std::string& v);
    void set_productid(const std::string& v);
    void set_mrenclave(const std::string& v);
    void set_svn(const std::string& v);
    void set_debuggable(const std::string& v);
    void help_and_exit(const std::string& v = "");
};


