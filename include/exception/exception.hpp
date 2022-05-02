#pragma once
#ifndef _EXCEPTION_HPP
#define _EXCEPTION_HPP
#include <exception>
#include <string>

class exception : public std::exception
{
public:
    enum class TYPE {
        ARGC_ERROR = 1
    };

private:
    std::string _Terror;
public:
    explicit exception(const std::string& err)
        : _Terror(err) { }

    explicit exception(TYPE _type) {

        switch (_type)
        {
        case TYPE::ARGC_ERROR:
            _Terror = "argumentation error";
            break;
        default:
            _Terror = "no case for this type of error";
        }
    }

    const char* what() const noexcept { return _Terror.c_str(); }
};

#endif /// _EXCEPTION_HPP