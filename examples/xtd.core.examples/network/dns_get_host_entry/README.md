# dns_get_host_entry

Shows how to use [xtd::net::dns](../../../../src/xtd.core/include/xtd/net/dns.h) class.

## Sources

[src/dns_get_host_entry.cpp](src/dns_get_host_entry.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
ip host entry for : www.github.com
  - host_name : github.com
  - address list :
    * 140.82.121.3
  - aliases :
    * www.github.com
```
