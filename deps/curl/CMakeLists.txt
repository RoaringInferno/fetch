# curl
message(STATUS "Fetching curl ...")
# Security: libpsl validates domain names to prevent spoofing attacks
# RECOMMEND: ON (even for single API calls, as it provides basic security)
set(CURL_USE_LIBPSL ON)

# Concurrency: libuv enables async I/O operations
# RECOMMEND: OFF (you only make one request at a time)
set(CURL_USE_LIBUV OFF)

# Security: GSASL provides authentication mechanisms
# RECOMMEND: OFF (unless you need specific auth protocols)
set(CURL_USE_GSASL OFF)

# Security: GSSAPI enables Kerberos authentication
# RECOMMEND: OFF (unless you're in an enterprise environment)
set(CURL_USE_GSSAPI OFF)

# Internalization: GNUTLS provides internationalization features
# RECOMMEND: OFF (unless you need specific locale support)
set(CURL_USE_GNUTLS OFF)

# SSH: libssh enables SFTP/SCP protocol support
# RECOMMEND: OFF (unless you need SSH functionality)
set(CURL_USE_LIBSSH OFF)

# Security: RUSTLS provides modern TLS implementation
# RECOMMEND: OFF (OpenSSL is sufficient)
set(CURL_USE_RUSTLS OFF)

# Security: MBEDTLS provides embedded TLS implementation
# RECOMMEND: OFF (unless size is critical)
set(CURL_USE_MBEDTLS OFF)

# SSH: libssh2 provides alternative SSH implementation
# RECOMMEND: OFF (unless you need SSH and libssh fails)
set(CURL_USE_LIBSSH2 OFF)

# Security: WOLFSSL provides lightweight TLS implementation
# RECOMMEND: OFF (unless size is critical)
set(CURL_USE_WOLFSSL OFF)

# Security: OpenSSL provides standard TLS implementation
# RECOMMEND: ON (required for HTTPS support)
set(CURL_USE_OPENSSL ON)

# SSH: WOLFSSH provides another SSH implementation
# RECOMMEND: OFF (unless you need SSH and other options fail)
set(CURL_USE_WOLFSSH OFF)

# Windows Security: SCHANNEL provides Windows native SSL/TLS
# RECOMMEND: ON (if building on Windows)
set(CURL_USE_SCHANNEL ON)
FetchContent_Declare(
    curl
    GIT_REPOSITORY https://github.com/curl/curl.git
    GIT_TAG        curl-8_16_0
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    EXECLUDE_FROM_ALL
)
FetchContent_MakeAvailable(curl)

target_link_libraries(${EXEC_NAME} PRIVATE libcurl)
