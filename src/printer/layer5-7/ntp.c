#include "../../../headers/printer/layer5-7/ntp.h"

double ntp_fixed_to_seconds(uint32_t value)
{
       return (double)value / 65536.0;
}

void print_ntp(Ntp ntp)
{
       uint8_t li = (ntp.li_version_mode >> 6) & 0x03;
       uint8_t version = (ntp.li_version_mode >> 3) & 0x07;
       uint8_t mode = ntp.li_version_mode & 0x07;

       print_protocol_name("NTP");
       print_uint_field("Leap Indicator", li);
       print_uint_field("Version", version);
       print_uint_field("Mode", mode);
       print_uint_field("Stratum", ntp.stratum);
       print_uint_field("Poll", ntp.poll);
       print_hex_field("Precision", ntp.precision, 2);

       printf("%-*s: %.6f seconds\n",
              PRINT_LABEL_WIDTH,
              "Root Delay",
              ntp_fixed_to_seconds(ntp.root_delay));

       printf("%-*s: %.6f seconds\n",
              PRINT_LABEL_WIDTH,
              "Root Dispersion",
              ntp_fixed_to_seconds(ntp.root_dispersion));

       print_ip_field("Reference ID", ntp.reference_id);
       print_timestamp_field("Reference Timestamp", ntp.reference_timestamp);
       print_timestamp_field("Origin Timestamp", ntp.originate_timestamp);
       print_timestamp_field("Receive Timestamp", ntp.receive_timestamp);
       print_timestamp_field("Transmit Timestamp", ntp.transmit_timestamp);
}