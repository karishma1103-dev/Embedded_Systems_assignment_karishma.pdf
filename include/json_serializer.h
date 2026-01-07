#ifndef JSON_SERIALIZER_H
#define JSON_SERIALIZER_H
#include <stddef.h>
typedef struct {
    const char *timestamp;
    const char *meter_datetime;
    float total_m3;
    const char *status;
} data_point_t;
typedef struct {
    const char *media;
    const char *meter;
    const char *deviceId;
    const char *unit;
    data_point_t data;
} device_reading_t;
typedef struct {
    const char *gatewayId;
    const char *date;
    const char *deviceType;
    int interval_minutes;
    int total_readings;
    device_reading_t device;
} input_data_t;
int serialize_to_json(const input_data_t *input,
                      char *output_buffer,
                      size_t buffer_size);

#endif
