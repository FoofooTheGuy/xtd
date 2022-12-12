# date_time_add_seconds

Shows how to use [xtd::date_time::add_seconds](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1date__time.html#a413650dded2269db34a6ec15949a5d5f) method.

# Sources

[src/date_time_add_seconds.cpp](src/date_time_add_seconds.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Original date: 09/08/2014/16:00:00.0000000 (635457888000000000 ticks)

Second date:   09/08/2014/16:00:30.0000000 (635457888300000000 ticks)
Difference between dates: Mon Jan  1 00:00:30 0001 (300000000 ticks)

Third date:    09/09/2014/16:00:00.0000000 (635458752000000000 ticks)
Difference between dates: Tue Jan  2 00:00:00 0001 (864000000000 ticks)
```
