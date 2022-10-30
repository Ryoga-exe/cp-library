/// @prefix cpDebug
/// @description Debug Print : デバッグプリント用スニペット
/// @isFileTemplate false
#if __has_include("../src/debug/debug_print/debug_print.hpp")
    #include "../src/debug/debug_print/debug_print.hpp"
    #define $(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
    #define $(...) (static_cast<void>(0))
#endif
