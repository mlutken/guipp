#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include <unordered_map>
#include <variant>

// ------------------------
// --- data_object_base ---
// ------------------------

struct data_object_base
{
    using id_t = size_t;
    virtual ~data_object_base() = default;
    virtual id_t            id          () const = 0;
    virtual std::string     to_string   () const = 0;
};

using data_object_sp = std::shared_ptr<data_object_base>;

// ----------------
// --- my_point ---
// ----------------

struct my_point : public data_object_base
{
    my_point() = default;
    ~my_point() override = default;
    my_point(const my_point&) = default;
    my_point(my_point&&) = default;
    my_point& operator=(const my_point&) = default;
    my_point& operator=(my_point&&) = default;

    explicit my_point(uint32_t xval, uint32_t yval) : x(xval), y(yval) {}

    uint32_t x  {};
    uint32_t y  {};
    id_t            id          () const override;
    std::string     to_string   () const override;

};

// ------------------
// --- data_value ---
// ------------------

using data_value = std::variant<int32_t, int64_t, float, double, std::string, bool, data_object_sp>;
// using data_value = std::variant<int32_t, bool, std::string, data_object_sp>;

std::string     to_string   (const data_value& val);

// ------------------------
// --- data_source_base ---
// ------------------------

class data_source_base
{
public:
    virtual ~data_source_base() = default;

    void                set                 (const std::string& path, int32_t val);
    void                set                 (const std::string& path, int64_t val);
    void                set                 (const std::string& path, float val);
    void                set                 (const std::string& path, double val);
    void                set                 (const std::string& path, bool val);
    void                set                 (const std::string& path, std::string val);
    void                set                 (const std::string& path, data_value val);

    int32_t             as_int32            (const std::string& path) const;
    const std::string&  as_string           (const std::string& path)  const;
    const data_value&   as_data_value       (const std::string& path)  const;

    bool                is_read_only        () const;

    std::string         dbg_string          () const;
    void                dbg_print           () const;

protected:
    virtual const data_value&   do_as_data_value    (const std::string& path)  const = 0;
    virtual void                do_set              (const std::string& path, data_value val) = 0;
    virtual std::string         do_dbg_string       () const = 0;

    virtual bool                do_is_read_only     () const { return false; }
};


class data_source : public data_source_base
{
public:
    data_source() = default;


protected:
    const data_value&   do_as_data_value    (const std::string& path)  const override;
    void                do_set              (const std::string& path, data_value val) override;

    std::string         do_dbg_string       () const override;

private:
    using map_string_t = std::unordered_map<std::string, data_value>;

    map_string_t        string_data_;
};

// ----------------------------------------------
// --- data_source playground and adhoc tests ---
// ----------------------------------------------

void data_source_playground_1();
