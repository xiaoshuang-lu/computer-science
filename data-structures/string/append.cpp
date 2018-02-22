# include <cinttypes>
# include <cstdint>
# include <cstdio>

# include <string>

int main()
{
    {
        char array[] = "all men must die.";

        std::string string;

        for (intmax_t i = 0; i < sizeof(array); ++ i)
        {
            string.push_back(array[i]);
        }

        printf("%" PRIdMAX "\n", * (string.end() - 1));
        printf("%" PRIdMAX "\n", * (string.end() - 0));

        printf("%s\n", string.c_str());
    }

    {
        std::string string;

        string.append(std::string("all men must die."));

        printf("%" PRIdMAX "\n", * string.end());

        printf("%s\n", string.c_str());
    }

    return 0;
}
