#include <iostream>
#include  <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

int128_t boost_product(long long A, long long B) {
    int128_t ans = (int128_t)A*B;
    return ans;
}
int main() {
    long long first= 523854635;
    long long second= 3985968374;

    std::cout << " product of " << first << " and " << second << " is " <<boost_product(first,second) << "\n";

    return 0;
}
