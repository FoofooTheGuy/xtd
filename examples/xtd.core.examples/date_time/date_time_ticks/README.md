# date_time_ticks

Shows how to use [xtd::date_time](../../../../src/xtd.core/include/xtd/date_time.h) class with ticks constructors.

# Sources

[src/date_time_ticks.cpp](src/date_time_ticks.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
1) The maximum date and time is 12/31/9999 23:59:59
2) The minimum date and time is 01/01/0001 00:00:00
3) The custom  date and time is 01/05/1971 21:10:30

The custom date and time is created from 621675546300000000 ticks.
```
