#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;
using namespace xtd::io;
using namespace xtd::net;
using namespace xtd::net::sockets;

auto main()->int {
  auto terminate_app = false;
  
  thread server([&] {
    auto listener = tcp_listener::create(9400);
    listener.start();
    auto stream = listener.accept_tcp_client().get_stream();
    stream_reader reader(stream);
    
    while (!terminate_app)
      if (stream.data_available()) console::write_line(reader.read_line());
  });
  
  thread client([&] {
    tcp_client client;
    client.connect(ip_address::loopback, 9400);
    auto stream = client.get_stream();
    stream_writer writer(stream);
    
    auto counter = 1;
    while (!terminate_app) {
      writer.write_line(ustring::format("counter={}", counter++));
      this_thread::sleep_for(50ms);
    }
  });
  
  console::read_key();
  terminate_app = true;
  server.join();
  client.join();
}

// This code produces the following output:
//
// counter=1
// counter=2
// counter=3
// counter=4
// counter=5
// ...
