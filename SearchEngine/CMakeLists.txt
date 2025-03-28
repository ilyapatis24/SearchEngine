cmake_minimum_required(VERSION 3.20)
project(SearchEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=0)
set(PostgreSQL_ADDITIONAL_VERSIONS "14")

# Пути к исходным файлам
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(OPENSSL_DIR "C:/Program Files/OpenSSL-Win64")
set(BOOST_INCLUDE_DIR "C:/boost/include/boost-1_86")
set(BOOST_LIBS "C:/boost/lib")
# Исходные файлы основного проекта
set(SOURCES
    ${SRC_DIR}/main.cpp

    ${SRC_DIR}/Database/Database.cpp

    ${SRC_DIR}/Indexer/Indexer.cpp

    ${SRC_DIR}/Utils/Config.cpp
    ${SRC_DIR}/Utils/URLParser.cpp
    ${SRC_DIR}/Utils/HTTPUtils.cpp
    ${SRC_DIR}/Utils/Logger.cpp

    ${SRC_DIR}/Spider/Spider.cpp

    ${SRC_DIR}/SearchEngine/SearchEngine.cpp

    ${SRC_DIR}/Application/Application.cpp
)

# Заголовочные файлы
set(HEADERS
    ${SRC_DIR}/Database/Database.h

    ${SRC_DIR}/Indexer/Indexer.h

    ${SRC_DIR}/Utils/Config.h
    ${SRC_DIR}/Utils/URLParser.h
    ${SRC_DIR}/Utils/HTTPUtils.h
    ${SRC_DIR}/Utils/Logger.h

    ${SRC_DIR}/Spider/Spider.h

    ${SRC_DIR}/SearchEngine/SearchEngine.h

    ${SRC_DIR}/Application/Application.h
)

add_subdirectory("C:/libpqxx-7.10.0/libpqxx-7.10.0" libpqxx-build)
add_executable(SearchEngine ${SOURCES} ${HEADERS})

set(OPENSSL_INCLUDE_DIR "${OPENSSL_DIR}/include")
set(OPENSSL_CRYPTO_LIBRARY "${OPENSSL_DIR}/lib/VC/x64/MDd/libcrypto.lib")
set(OPENSSL_SSL_LIBRARY "${OPENSSL_DIR}/lib/VC/x64/MDd/libssl.lib")
target_include_directories(SearchEngine PRIVATE ${OPENSSL_INCLUDE_DIR})
target_include_directories(SearchEngine PRIVATE ${BOOST_INCLUDE_DIR})
target_link_directories(SearchEngine PRIVATE ${BOOST_INCLUDE_DIR})
target_link_libraries(SearchEngine PRIVATE ${OPENSSL_CRYPTO_LIBRARY} ${OPENSSL_SSL_LIBRARY} pqxx)

