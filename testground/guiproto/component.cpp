#include "component.h"

component::component(data_source_base& data_source)
    : data_source_ref_ptr_{&data_source}
{
}

component::component(data_source_base_sp data_source)
    : data_source_sp_{std::move(data_source)}
{
}

data_source_base& component::data_source()
{
    if (data_source_ref_ptr_) { return *data_source_ref_ptr_; }
    return *data_source_sp_;
}

const data_source_base& component::data_source() const
{
    if (data_source_ref_ptr_) { return *data_source_ref_ptr_; }
    return *data_source_sp_;
}
