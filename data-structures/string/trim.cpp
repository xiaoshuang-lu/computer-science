# include <cstdint>
# include <cctype>

# include <string>

std::string trim(std::string const & string)
{
    intmax_t begin = 0;

    while (begin < string.size())
    {
        if (! isspace(string[begin]))
        {
            break;
        }

        ++ begin;
    }

    intmax_t end = string.size();

    while (0 < end)
    {
        if (! isspace(string[end - 1]))
        {
            break;
        }

        -- end;
    }

    return std::string(string.begin() + begin, string.begin() + end);
}

# include <cstdio>

int main()
{
    std::string string("    abcd    ");

    printf("%s\n", trim(string).data());

    return 0;
}
