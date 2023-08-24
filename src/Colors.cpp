#include "Colors.h"


std::ostream& blue(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE
        | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return s;
}

std::ostream& red(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_RED | FOREGROUND_INTENSITY);
    return s;
}

std::ostream& green(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return s;
}

std::ostream& yellow(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    return s;
}

std::ostream& white(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return s;
}

std::unordered_map<std::string, std::ostream& (*)(std::ostream& s)> Colors =
{ std::pair<std::string, std::ostream& (*)(std::ostream& s)>("blue", blue),
std::pair<std::string, std::ostream& (*)(std::ostream& s)>("red", red),
std::pair<std::string, std::ostream& (*)(std::ostream& s)>("green", green),
std::pair<std::string, std::ostream& (*)(std::ostream& s)>("yellow", yellow),
std::pair<std::string, std::ostream& (*)(std::ostream& s)>("white", white) };

// Cop