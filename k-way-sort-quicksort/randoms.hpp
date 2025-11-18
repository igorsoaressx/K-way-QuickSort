#ifndef RANDOMS_HPP
#define RANDOMS_HPP

#include <cstring>
#include <string>
#include <random>
#include <chrono>
using namespace std;

string randomString(int sz = 10) {
    static mt19937 rng(random_device{}());
    static uniform_int_distribution<int> len_dist(1, sz);
    static const char charset[] =
        //"!\"#$%'()*+,-./:;<=>?@[\\]^_`{|}~"
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    static uniform_int_distribution<size_t> char_dist(0, sizeof(charset) - 2);

    int len = len_dist(rng);
    string s;
    s.resize(len);
    for (int i = 0; i < len; ++i) {
        s[i] = charset[char_dist(rng)];
    }
    return s;
}

template <typename T>
T randomValue() {
    static mt19937 rng(
        chrono::steady_clock::now().time_since_epoch().count());
    if constexpr (is_integral_v<T>) {
        uniform_int_distribution<T> dist(0, 10000);
        return dist(rng);
    }
    else if constexpr (is_floating_point_v<T>) {
        uniform_real_distribution<T> dist(0.0, 10000.0);
        return dist(rng);
    }
    else if constexpr (is_same_v<T, string>) {
        return randomString();
    }
    else if constexpr (is_same_v<T, char>) {
        return static_cast<char>('A' + rng() % 26);
    }
    else if constexpr (is_same_v<T, bool>) {
        return rng() % 2;
    }
    else {
        // para structs ou tipos personalizados
        T obj{};
        // preenche campo a campo, se quiser, via especialização posterior
        return obj.aleatorio();
    }
}

#endif // RANDOMS_HPP
