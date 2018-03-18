
#include <algorithm> 
#include <array>
#include <initializer_list>
#include <memory>
#include <numeric>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <utility>

using namespace std;

auto main()->int{

    cout  << __func__ << " " << "Hello, Wandbox!" << endl;
    return 0;
}


// Solution 1: simply use accumulate to sum, and determine the count using std::distance() 
// (the latter is more general than using iterator arithmetic, end - begin, which only works for random-access iterators)
template <typename T, typename IterType>
std::optional<T> average(IterType begin, IterType end){
	const auto count = std::distance(begin, end);
	const auto sum = std::accumulate(begin, end, T{});
	return count ? std::optional<T>(sum / count) : std::nullopt;
}

/* Solution 2: accumulate a pair<> that counts both the number of elements and the sum
template <typename T, typename IterType>
std::optional<T> average(IterType begin, IterType end){
    auto accumulated = std::accumulate(
        begin, 
        end, 
        std::make_pair(0u, T{}), [](const auto& accumulated, const auto& element){
            return std::make_pair(accumulated.first + 1, accumulated.second + element); 
        }
    );
    return accumulated.first? std::optional<T>(accumulated.second / accumulated.first) : std::nullopt;
}
*/

/*
auto main()->int{
    return 0;
}
int main(){
    return 0;
}
auto main(int argc,char** argv)->int{
    return 0;
}
int main(int argc,char** argv){
    return 0;
}
*/
