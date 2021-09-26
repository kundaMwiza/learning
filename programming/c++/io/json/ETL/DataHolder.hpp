#ifndef DATAHOLDER
#define DATAHOLDER

#include <utility>
#include "ETL.hpp"

// helper data structure to house returned maps from
// SmartETL
template <typename QuestionType, typename CategoryType, typename ResourceType>
struct DataHolder
{
    // begin constructors ---

    // transfer resources
    DataHolder(QuestionType &&qmap, CategoryType &&cmap, ResourceType &&rmap)
        : q_map(std::forward<QuestionType &&>(qmap)),
          c_map(std::forward<CategoryType &&>(cmap)),
          r_map(std::forward<ResourceType &&>(rmap)) {}

    // copy constructor
    DataHolder(const DataHolder &dc)
        : q_map(dc.q_map), c_map(dc.c_map), r_map(dc.r_map) {}

    // move constructor
    DataHolder(DataHolder &&dc) noexcept
        : q_map(std::move(dc.q_map)), c_map(std::move(dc.c_map)), r_map(std::move(dc.r_map)) {}

    // end constructors ---

    // begin assignment operators

    // copy assignment operator
    DataHolder &operator=(const DataHolder &rhs)
    {
        // self assignment
        if (rhs == *this)
        {
            return *this;
        }
        else
        {
            q_map = rhs.q_map;
            c_map = rhs.c_map;
            r_map = rhs.r_map;
            return *this;
        }
    }

    // move assignment
    DataHolder &operator=(DataHolder &&rhs)
    {
        // self move
        if (rhs == *this)
        {
            return *this;
        }
        else
        {
            q_map = std::move(rhs.q_map);
            c_map = std::move(rhs.c_map);
            r_map = std::move(rhs.r_map);
            return *this;
        }
    }

    // end assignment operators

    // begin destructors ---
    ~DataHolder() = default;

    // end destructors

    // begin data members ---
    QuestionType q_map;
    CategoryType c_map;
    ResourceType r_map;
    // end data members
};

#endif