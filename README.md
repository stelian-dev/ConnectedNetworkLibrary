---
Version: 1.0.0
---

C++ library (header only) that provides connection based and connectionless sockets with both IP version 4 and IP version 6.
This library can be used on both Linux and Windows.

## Connection based sockets
Reliable sockets that ensures the data is not duplicated or lost. There are two kinds of connection based sockets: *acceptor* and *socket_stream*.
To use *acceptor* and *socket_stream* types, *cnl/protocol/tcp.hpp* header must be included.

Example:
```
    ///Create an endpoint with the current IP and port 42069.
    ipv4::tcp::endpoint endpoint(42069);
    ///Create an acceptor
    ipv4::tcp::acceptor acceptor(10);
    ///Bind the acceptor to the endpoint
    acceptor.bind(endpoint);
    ///Mark the socket as passive
    acceptor.listen();
    ///Start accepting new connetions
    acceptor.accept([](ipv4::tcp::socket& socket, error err){
        if(!err)
        {
            std::array<char, 256> buffer;
            std::size_t transferred_bytes = 0;
            ///Read operation
            error err2 = socket.read(buffer, transferred_bytes);
        }
        ///Close the socket
        socket.close();
    });
    ///Close the acceptor
    acceptor.close();
```
Note: the accept method must have as parameter a function with the following signature:
```
    void func(ipv4::tcp::socket&, error);
```
## Connectionless sockets
Unreliable sockets. There is only one kind of connectionless sockets: *socket_datagram*.
To use *socket_datagram* type, *cnl/protocol/udp.hpp* header must be included.

Example:
```
    ///Create an endpoint with the current IP and port 42069.
    ipv4::udp::endpoint endpoint(42069);
    ///Create a socket
    ipv4::udp::socket socket;
    ///Buffer to be sent
    std::array<char, 14> buffer {"Hello, world!"};
    std::size_t transferred_bytes = 0;
    ///Write operation
    socket.write(endpoint, buffer, transferred_bytes);
    ///Close the socket
    socket.close();
```
