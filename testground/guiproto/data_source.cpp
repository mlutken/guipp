#include "data_source.h"
#include <sstream>
#include <iostream>

using namespace std;
using namespace std::string_view_literals;

template<class... Ts>
struct visit_overload_t : Ts... {
    using Ts::operator()...;
};
template<class... Ts>
visit_overload_t(Ts...) -> visit_overload_t<Ts...>; // Deduction guide

// ----------------
// --- my_point ---
// ----------------

data_object_base::id_t my_point::id() const { return __COUNTER__; }

string my_point::to_string() const
{
    return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

// ------------------
// --- data_value ---
// ------------------

// using data_value = std::variant<int32_t, int64_t, float, double, std::string, bool, data_object_sp>;

/// @see https://www.cppstories.com/2018/09/visit-variants/
// struct data_value_to_string_visitor {
//     void operator()(int32_t val)       { std::cout << "int32_t\n"; }
//     void operator()(int64_t val )   { std::cout << "int64_t\n"; }
//     void operator()(float val)   { std::cout << "float\n"; }
//     void operator()(double val ) { std::cout << "double\n"; }
//     void operator()(bool val ) { std::cout << "bool\n"; }
//     void operator()(const std::string& val ) { std::cout << "string\n"; }
//     void operator()(const data_object_sp& val ) { std::cout << "data_object_sp\n"; }
// };

// struct data_value_to_string_visitor {
//     std::string operator()(int32_t val)       { return to_string(val); }
//     std::string operator()(int64_t val)       { return to_string(val); }
//     std::string operator()(float val)       { return to_string(val); }
//     std::string operator()(double val)       { return to_string(val); }
//     std::string operator()(bool val)       { return to_string(val); }
//     std::string operator()(const data_object_sp& val ) { return val->to_string(); }
// };

string to_string(const data_value& val)
{
    return std::visit(visit_overload_t {
        [](const std::string& b)        -> string { return b; },
        [](bool val)                    -> string { return val ? "true" : "false"; },
        [](const data_object_sp& val)   -> string { return val->to_string(); },
        [](auto val)                    -> string { return to_string(val); },
    }, val);
}



// ------------------------
// --- data_source_base ---
// ------------------------

// void data_source_base::set(const data_path& path, int32_t val)
// {
//     set(path, data_value{val});
// }

// void data_source_base::set(const data_path& path, int64_t val)
// {
//     set(path, data_value{val});
// }

// void data_source_base::set(const data_path& path, float val)
// {
//     set(path, data_value{val});
// }

// void data_source_base::set(const data_path& path, double val)
// {
//     set(path, data_value{val});
// }

// void data_source_base::set(const data_path& path, bool val)
// {
//     set(path, data_value{val});
// }

// void data_source_base::set(const data_path& path, std::string val)
// {
//     set(path, data_value{std::move(val)});
// }

void data_source_base::set(const data_path& path, data_value val)
{
    do_set(path, std::move(val));
}

int32_t data_source_base::as_int32(const data_path& path) const
{
    return std::get<int32_t>(as_data_value(path));
}


const string& data_source_base::as_string(const data_path& path) const
{
    return std::get<std::string>(as_data_value(path));
}

const data_value& data_source_base::as_data_value(const data_path& path) const
{
    return do_as_data_value(path);
}


bool data_source_base::is_read_only() const
{
    return do_is_read_only();
}

string data_source_base::dbg_string() const
{
    return do_dbg_string();
}

void data_source_base::dbg_print() const
{
    cerr << dbg_string() << "\n";
}

// -------------------
// --- data_source ---
// -------------------

const data_value& data_source::do_as_data_value(const data_path& path) const
{
    static const data_value default_value{};
    const auto it = string_data_.find(path);
    return it != string_data_.end() ? it->second : default_value;
}

void data_source::do_set(const data_path& path, data_value val)
{
    string_data_[path] = std::move(val);
}

string data_source::do_dbg_string() const
{
    string s;
    for (const auto& [path, val]: string_data_) {
        s += path + " : ";
        s += to_string(val) + "\n";
    }

    return s;
}

// ----------------------------------------------
// --- data_source playground and adhoc tests ---
// ----------------------------------------------

void data_source_playground_1()
{
    cerr << " --- data_source_playground_1() ---\n";

    data_source ds;
    ds.set("video_title", "The Trump Report - ep 345"s);
    ds.set("stars", 4);
    ds.set("ai_generated", false);
    ds.set("pos", make_shared<my_point>(2, 3));

    ds.dbg_print();



}

