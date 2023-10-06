#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

float c_sqrt(float);

int main()
{
    float n, res;
    int i;

    while (true) {
        cout << "Number: ";
        cin >> n;

        auto start = high_resolution_clock::now();
            for(i = 0; i < 0x989680; ++i) // 10 million iterations
                res = c_sqrt(n);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << "SQRT is " << res << endl;
        cout << "Calculation took " << (duration.count() / 1000.0f) << " ms for 10 million iterations" << endl << endl;
    }
}

float c_sqrt(float n) // Changed Quake 3 algorithm, see more here https://www.youtube.com/watch?v=p8u_k2LIZyo
{
    long i;
    float y;

    y = n;
    i = *(long*)&y;
    i = 0x1fc2c083 + (i >> 1); // Made it sqrt(x), not 1/sqrt(x)
    y = *(float*)&i;
    y = 0.5f * (y + n / y); // Newton method 1st iteration
    //y = 0.5f * (y + n / y); // Newton method 2nd iteration (more accurate, but slower)

    return y;
}