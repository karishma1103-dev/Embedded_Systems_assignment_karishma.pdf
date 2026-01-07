#include <stdio.h>
#include "json_serializer.h"
int main() {
    char buffer[1024];
    input_data_t input = {
        .gatewayId = "gateway_1234",
        .date = "1970-01-01",
        .deviceType = "stromleser",
        .interval_minutes = 15,
        .total_readings = 1,
        .device = {
            .media = "water",
            .meter = "waterstarm",
            .deviceId = "stromleser_50898527",
            .unit = "m3",
            .data = {
                .timestamp = "1970-01-01 00:00",
                .meter_datetime = "1970-01-01 00:00",
                .total_m3 = 107.752,
                .status = "OK"
            }
        }
    };
    if (serialize_to_json(&input, buffer, sizeof(buffer)) == 0) {
        printf("%s\n", buffer);
    } else {
        printf("Serialization failed\n");
    }
    return 0;
}
