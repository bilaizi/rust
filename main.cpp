#include <array>
#include <iostream>
using namespace std;

auto main()->int{
    array<int, 3> values = { 11, 22, 33 };
    auto [x, y, z] = values;
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
