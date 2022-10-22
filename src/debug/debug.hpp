/// @prefix cpDebug
/// @description Debug Print : デバッグプリント用スニペット
/// @isFileTemplate false
#if __has_include("../src/debug/print.hpp")
    #include "../src/debug/print.hpp"
    #define $(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
    #define $(...) 0
#endif
