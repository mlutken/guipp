#pragma once

#include <string>
#include <unordered_map>


class data_source
{
public:
    data_source() = default;

    const std::string&  as_string       (const std::string& path)  const;
    void                set             (const std::string& path, std::string val);

private:
    using map_string_t = std::unordered_map<std::string, std::string>;

    map_string_t        string_data_;
};
