# include <cstdint>
# include <cstdlib>

double random()
{
    return 1.0 * rand() / RAND_MAX;
}

double compute_pi(intmax_t n)
{
    intmax_t count = 0;

    for (intmax_t i = 0; i < n; ++ i)
    {
        double x = random();
        double y = random();

        if (x * x + y * y <= 1.0)
        {
            ++ count;
        }
    }

    return 4.0 * count / n;
}

# include <cinttypes>
# include <cstdio>
# include <ctime>

int main()
{
    double pi;

    srand(time(0));

    pi = compute_pi((1 << 24) - 1);

    printf("%f\n", pi);

    return 0;
}
