#include <iostream>
#include <cstring>
#include <cstdint>
#include <zlib.h>

int main() {
    const char* prefix = "cnsl";
    const uint32_t crc = 4146026254;

    // Tính giá trị suffix để giá trị kiểm tra dư của payload bằng với giá trị crc đã cho
    char suffix[60] = {0};
    uint32_t checksum = crc32(0L, Z_NULL, 0);
    checksum = crc32(checksum, (const Bytef*)prefix, strlen(prefix));
    while (checksum != crc) {
        // Điều chỉnh byte cuối cùng của suffix và các byte trước đó lên 1 để giá trị kiểm tra dư bằng với giá trị crc đã cho
        int i = 59;
        while (suffix[i] == 255) {
            suffix[i] = 0;
            i--;
        }
        suffix[i]++;
        checksum = crc32(checksum, (const Bytef*)suffix, sizeof(suffix));
    }

    // Tạo payload hợp lệ
    uint8_t payload[64] = {0};
    memcpy(payload, prefix, strlen(prefix));
    memcpy(payload + strlen(prefix), suffix, sizeof(suffix));
    memcpy(payload + strlen(prefix) + sizeof(suffix), &crc, sizeof(crc));

    // Kiểm tra giá trị kiểm tra dư CRC32 của payload
    if (crc32(0L, Z_NULL, 0) != crc32(0L, (const Bytef*)payload, sizeof(payload))) {
        std::cout << "Invalid CRC32" << std::endl;
        return 1;
    }

    // In ra payload
    for (int i = 0; i < sizeof(payload); i++) {
        printf("%02x ", payload[i]);
    }
    std::cout << std::endl;

    return 0;
}