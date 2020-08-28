cmake_minimum_required(VERSION 3.8)

set(LibraryRoot "${PROJECT_SOURCE_DIR}")

add_library(${LibraryName} INTERFACE)

target_sources(${LibraryName} INTERFACE 
    "${LibraryRoot}/cnl/endpoint/endpoint_base.hpp"
    "${LibraryRoot}/cnl/endpoint/resolver_base.hpp"
    "${LibraryRoot}/cnl/error/error.hpp"
    "${LibraryRoot}/cnl/exception/exception.hpp"
    "${LibraryRoot}/cnl/misc/config.hpp"
    "${LibraryRoot}/cnl/misc/constants.hpp"
    "${LibraryRoot}/cnl/misc/types.hpp"
    "${LibraryRoot}/cnl/misc/winsock_init.hpp"
    "${LibraryRoot}/cnl/protocol/internet_protocol.hpp"
    "${LibraryRoot}/cnl/protocol/tcp.hpp"
    "${LibraryRoot}/cnl/protocol/udp.hpp"
    "${LibraryRoot}/cnl/socket/acceptor_base.hpp"
    "${LibraryRoot}/cnl/socket/socket_base.hpp"
    "${LibraryRoot}/cnl/socket/socket_datagram.hpp"
    "${LibraryRoot}/cnl/socket/socket_stream.hpp"
)

target_include_directories(${LibraryName}
    INTERFACE 
    ${LibraryRoot}
)