#include <iostream>
#include <cstdint>
#include <string>

enum class ErrorCode : uint8_t
{
    BAD_REQUEST,
    NOT_FOUND,
    SERVER_ERROR,
    GATEWAY_TIMEOUT
};

void printError(ErrorCode error_code)
{
    switch (error_code)
    {
    case ErrorCode::BAD_REQUEST:
        std::cout << "400 Bad Request" << std::endl;
        break;
    case ErrorCode::NOT_FOUND:
        std::cout << "404 Not Found" << std::endl;
        break;
    case ErrorCode::SERVER_ERROR:
        std::cout << "500 Server Error" << std::endl;
        break;
    case ErrorCode::GATEWAY_TIMEOUT:
        std::cout << "504 Gateway Timeout" << std::endl;
        break;
    default:
        std::cout << "Not a valid error code" << std::endl;
        break;
    }
}

int main(void)
{
    ErrorCode errCode = ErrorCode::SERVER_ERROR;

    printError(errCode);

    return 0;
}
