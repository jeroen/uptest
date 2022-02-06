Test exception behavior of R callbacks when compiling with `RCPP_USING_UNWIND_PROTECT` by commenting-out the first line in [src/Makevars](src/Makevars).

When we compile __without__ `-DRCPP_USE_UNWIND_PROTECT`:

```r
> out <- uptest::uptest()
[Appplication handling R exception] Evaluation error: Ouch from R.
> print(out)
[1] 42
```

When we compile __with__ `-DRCPP_USE_UNWIND_PROTECT`:

```r
> out <- uptest::uptest()
Error in (function ()  : Ouch from R
Calls: <Anonymous> -> call_r_from_rcpp -> <Anonymous>
Execution halted
```

So the difference is that with unwind-protect, R errors no longer turn into std C++ exceptions, but rather are directly printed to the console and a `Rcpp::LongjumpException` token is thrown that is more difficult to handle in C++. 
