/*
glvalue
xrvalue
prvalue
rvalue
lvalue
*/

# include <cstdint>
# include <cstdio>

# include <memory>
# include <utility>

intmax_t function(intmax_t & argument)
{
    printf("intmax_t function(intmax_t & argument)");
    printf("\n");

    return 0;
}

intmax_t function(intmax_t && argument)
{
    printf("intmax_t function(intmax_t && argument)");
    printf("\n");

    return 0;
}

intmax_t function(intmax_t const & argument)
{
    printf("intmax_t function(intmax_t && argument)");
    printf("\n");

    return 0;
}

template<typename T>
intmax_t wrapper(T && argument)
{
    // argument is always lvalue
    function(std::forward<T>(argument));

    return 0;
}

int main()
{
    {
        function(0);

        wrapper(0);
    }

    {
        intmax_t value = 0;

        function(value);

        wrapper(value);
    }

    {
        intmax_t value = 0;

        function(std::move(value));

        wrapper(std::move(value));
    }

    return 0;
}
