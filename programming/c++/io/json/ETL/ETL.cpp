#include "ETL.hpp"
#include <iterator>
#include <fstream>
#include "boost/tokenizer.hpp"
#include "stemming/english_stem.h"

// begin private member functions ---
// returns 1 if no entry is added to the data map
// otherwise returns 0 for a succesfull addition
unsigned int SmartETL::_process_question(question_map &data, unsigned int id, std::string &line_str, const delimiter_type &d)
{
    tokenizer_type que_tok(line_str, d);

    // temporary vector to house the processed question
    std::vector<std::string> que_vec;

    auto b = que_tok.begin(), e = que_tok.end();

    // advance past question part of string
    ++b;

    // make sure we are not out of bounds
    // if we are at the end already (empty question), return 1 for a failure
    if (b == e)
    {
        return 1;
    }

    auto lower_str = [](std::string str)
    {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);

        return str;
    };

    // make each word lowercase & apply stemming
    std::string temp_str;

    for (; b != e; ++b)
    {
        temp_str = lower_str(*b);
        // stemming here?
        que_vec.push_back(temp_str);
    }

    // add an entry for the new id
    data[id] = que_vec;

    return 0;
}

unsigned int SmartETL::_process_category(category_map &data, unsigned int id, std::string &line_str, const delimiter_type &d)
{
    tokenizer_type cat_tok(line_str, d);

    // check if no tokens have been output
    auto b(cat_tok.begin());
    auto e(cat_tok.end());

    if (b == e)
    {
        return 1;
    }

    // advance tokenzier to get actual category
    ++b;

    // check again to see if no tokens have been output
    if (b == e)
    {
        return 1;
    }
    else
    {
        data[id] = *b;
        return 0;
    }
}

unsigned int SmartETL::_process_resources(resource_map &data, unsigned int id, std::istream &input_file, const delimiter_type &d)
{
    std::string line_str;
    unsigned int resource_number(0);

    // check if there is atleast one resource
    std::getline(input_file, line_str);
    tokenizer_type res_tok(line_str, d);
    auto b = res_tok.begin(), e = res_tok.end();

    // if either the first token is equal to eof
    // return status code 1
    if (b == e)
    {
        return 1;
    }
    else
    {
        // we have a valid token here..
        data[id].push_back(*b);
    }

    while (std::getline(input_file, line_str))
    {
        tokenizer_type res_tok(line_str, d);

        // if no token exit, as there are no more resources..
        if (res_tok.begin() == res_tok.end())
        {
            return 0;
        }
        else
        {
            data[id].push_back(*res_tok.begin());
        }
    }

    return 0;
}

// end private member functions ---

// begin public member functions ---
DataHolder<SmartETL::question_map, SmartETL::category_map, SmartETL::resource_map>
SmartETL::load_dataset()
{

    // output data maps
    question_map q_map;
    category_map c_map;
    resource_map r_map;

    // delimiters for processing each line
    delimiter_type line_delim(" \"");
    delimiter_type id_delim(":,");
    delimiter_type question_delim(delimiter);
    delimiter_type category_delim(" \":,");
    delimiter_type resource_delim(" \",[]");

    // load input file
    std::ifstream input_file(filename);

    // temporary string to load the line into
    std::string line_str;

    // unsigned object to hold the status message
    unsigned int status_code;

    while (std::getline(input_file, line_str))
    {
        tokenizer_type line_tok(line_str, line_delim);

        auto b(line_tok.begin());
        auto e(line_tok.end());

        if ((b != e) && (*b == "id"))
        {
            // process id
            // advance tokenizer to the id part
            tokenizer_type id_tok(*++b, id_delim);
            unsigned int temp_id(std::stoi(*id_tok.begin()));

            std::getline(input_file, line_str);
            status_code = _process_question(q_map, temp_id, line_str, question_delim);

            // if status code is 1, there is not question, so move on..
            if (status_code == 1)
            {
                continue;
            }

            std::getline(input_file, line_str);
            status_code = _process_category(c_map, temp_id, line_str, category_delim);

            // there is no category, so remove id from question and move on
            if (status_code == 1)
            {
                auto found_it = q_map.find(temp_id);
                q_map.erase(temp_id);
                continue;
            }

            // next line is a resource type
            std::getline(input_file, line_str);

            status_code = _process_resources(r_map, temp_id, input_file, resource_delim);

            // if there is no resource, remove id from question and category may and move on
            if (status_code == 1)
            {
                auto q_it = q_map.find(temp_id);
                q_map.erase(q_it);
                auto c_it = c_map.find(temp_id);
                c_map.erase(c_it);
            }
        }
    }

    return DataHolder<question_map, category_map, resource_map>(std::move(q_map), std::move(c_map), std::move(r_map));
}

// end public member functions ---