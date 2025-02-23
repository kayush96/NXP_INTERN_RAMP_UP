// 2) write a C program to create a 32 bit number with following user inputs:
//     a) Bits 1-4: Message Id
//     b) Bits 5-10: Source Address
//     c) Bits 11-15: Destination Address
//     d) Bits 20-30: Data/Message
//     All reserved bits must be populated with 1.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t createNumber(uint32_t msg_id, uint32_t src_addr, uint32_t des_addr, uint32_t data)
{
    // 0b 1_2_3_4 . 5_6_7_8_9_10 . 11_12_13_14_15 . r_r_r_r . 20_21_22_23_24_25_26_27_28_29_30 . r_r
    uint32_t final_number = 0;
    final_number = (msg_id << 28);
    final_number = (src_addr << 22) | final_number;
    final_number = (des_addr << 17) | final_number;
    final_number = (((1 << 4) - 1) << 13) | final_number;
    final_number = (data << 2) | final_number;
    final_number = final_number | 3;

    return final_number;
}

void printNumber(uint32_t msgID, uint32_t src, uint32_t des, uint32_t data)
{
    printf("Message ID: %u\nSource Address: %u\nDestination Address: %u\nData: %u\n", msgID, src, des, data);
}

int main()
{
    uint32_t msg_id;
    uint32_t src_addr;
    uint32_t des_addr;
    uint32_t data;
    uint32_t final_number = 0;
    // taking input from user
    scanf("%u%u%u%u", &msg_id, &src_addr, &des_addr, &data);
    msg_id %= 16;
    src_addr %= 64;
    des_addr %= 32;
    data %= (1 << 11);

    final_number = createNumber(msg_id, src_addr, des_addr, data);

    printf("Final Number : %u\n", final_number);

    printNumber(msg_id, src_addr, des_addr, data);

    return 0;
}