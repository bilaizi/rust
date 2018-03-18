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
    array<int, 3> values = { 11, 22, 33 };
    auto [x, y, z] = values;
    struct Point { double x, y, z; };
    Point point={1.0, 2.0, 3.0};
    auto [x, y, z] = point;
    int* a = nullptr;
    a= new int; 
    if(!a){
    }
    delete a;
    a = nullptr;
    auto b= make_unique<int>();
    unique_ptr<int> c{new int};
    auto d= make_unique<int[]>(10);
    unique_ptr<int[]> e{new int[10]};
    auto f= make_shared<int>();
    shared_ptr<int[]> g{new int[10]};
    const int versionNumberMajor = 2;
    const int versionNumberMinor = 1;
    const std::string productName = "Super Hyper Net Modulator";
	
    vector<double> numbers{ 1, 2, 4, 8, 16, 32, 64, 128, 256 };
    cout << *average<double>(begin(numbers), end(numbers)) << std::endl;
	
    const size_t n{20};
    vector<int> numbers(n);
    iota(begin(numbers), end(numbers), 1);
    auto first_to_erase = remove_if(begin(numbers), end(numbers), [](auto num) { return num % 2 == 0; });
    numbers.erase(first_to_erase, end(numbers));
    
    cout  << __func__ << " " << "Hello, Wandbox!" << endl;
    return 0;
}
struct bad_date : std::exception {
   char const * what() const noexcept override { 
       return "bad_date"; 
   }
};

struct month {
    constexpr month(int m) noexcept : value{m} {}
    int value;
};
static constexpr month jan{1};
static constexpr month feb{2};
static constexpr month mar{3};
static constexpr month apr{4};
static constexpr month may{5};
static constexpr month jun{6};
static constexpr month jul{7};
static constexpr month aug{8};
static constexpr month sep{9};
static constexpr month oct{10};
static constexpr month nov{11};
static constexpr month dec{12};

struct year {
    constexpr year(int y) noexcept : value{y} {}
    int value;
};

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
