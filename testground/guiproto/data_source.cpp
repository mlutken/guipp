#include "data_source.h"

using namespace std;

const std::string& data_source::as_string(const std::string& path) const
{
    static const string default_value{""};
    const auto it = string_data_.find(path);
    return it != string_data_.end() ? it->second : default_value;
}

void data_source::set(const std::string& path, std::string val)
{
    string_data_[path] = val;
}

