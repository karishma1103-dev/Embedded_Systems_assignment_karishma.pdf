#include "json_serializer.h"
#include <stdio.h>
int serialize_to_json(const input_data_t *input,
                      char *output_buffer,
                      size_t buffer_size)
{
    if (!input || !output_buffer) {
        return -1;
    }
    int written = snprintf(output_buffer, buffer_size,
        "[{"
        "\"gatewayId\":\"%s\","
        "\"date\":\"%s\","
        "\"deviceType\":\"%s\","
        "\"interval_minutes\":%d,"
        "\"total_readings\":%d,"
        "\"values\":{"
            "\"device_count\":1,"
            "\"readings\":[{"
                "\"media\":\"%s\","
                "\"meter\":\"%s\","
                "\"deviceId\":\"%s\","
                "\"unit\":\"%s\","
                "\"data\":[{"
                    "\"timestamp\":\"%s\","
                    "\"meter_datetime\":\"%s\","
                    "\"total_m3\":%.3f,"
                    "\"status\":\"%s\""
                "}]"
            "}]"
        "}"
        "}]",
        input->gatewayId,
        input->date,
        input->deviceType,
        input->interval_minutes,
        input->total_readings,
        input->device.media,
        input->device.meter,
        input->device.deviceId,
        input->device.unit,
        input->device.data.timestamp,
        input->device.data.meter_datetime,
        input->device.data.total_m3,
        input->device.data.status
    );
    if (written < 0 || (size_t)written >= buffer_size) {
        return -2; // buffer too small
    }
    return 0;
}
