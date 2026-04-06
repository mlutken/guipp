#pragma once


#include "data_source.h"

class component
{
public:
    explicit component          (data_source_base& data_source);
    explicit component          (data_source_base_sp data_source);


    bool                        is_root             () const { return parent_ptr_ != nullptr; }
private:
    data_source_base&           data_source         ();
    const data_source_base&     data_source         () const;

    component*                  parent_ptr_             {nullptr};
    data_source_base*           data_source_ref_ptr_    {nullptr};
    data_source_base_sp         data_source_sp_         {nullptr};
};
