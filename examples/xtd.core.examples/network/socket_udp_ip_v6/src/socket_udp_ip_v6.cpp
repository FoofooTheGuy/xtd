#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

auto main()->int {
  auto terminate_app = false;
  
  thread server([&] {
    socket server_socket(address_family::inter_network_v6, socket_type::dgram, protocol_type::udp);
    server_socket.bind(ip_end_point(ip_address::ip_v6_any, 9400));
    
    while (!terminate_app) {
      vector<unsigned char> buffer(256);
      ip_end_point incoming_end_point;
      size_t number_of_byte_received = server_socket.receive_from(buffer, incoming_end_point);
      if (!(number_of_byte_received == 1 && buffer[0] == 0xFF))
        console::write_line(ustring(buffer.begin(), buffer.begin() + number_of_byte_received));
    }
  });
  
  thread client([&] {
    socket client_socket(address_family::inter_network_v6, socket_type::dgram, protocol_type::udp);
    
    auto counter = 1;
    while (!terminate_app) {
      auto str = ustring::format("counter={}", counter++);
      client_socket.send_to(vector<unsigned char>(str.begin(), str.end()), ip_end_point(ip_address::ip_v6_loopback, 9400));
      this_thread::sleep_for(50_ms);
    }
    
    client_socket.send_to(vector<unsigned char> {0xFF}, ip_end_point(ip_address::ip_v6_loopback, 9400));
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
