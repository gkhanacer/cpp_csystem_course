// Funtion return type:
// a. auto return type olabilir
// b. trailing return type olabilir

// b. trailing return type: fonksiyonun gdd türünün okun sağ tarafında yazılan türü
template<typename T>
auto func(T x) -> decltype(x + 1.3);

// a. auto return type
template<typename T>
auto func(T x)
{
    return x + .5; // T int ise, return type: double
}

template<typename T>
T foo(T x)
{
    return x + .5; // T int ise, return type: int
}

