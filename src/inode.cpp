#include "../include/inode.hpp"
using namespace inode_namespace;

int bitmap_namespace::store_bitmap()
{
    for (int i = 0; i < BLOCK_NUM_FS; i += 256)
    {
        char data[256];
        memcpy(data, bitmap_namespace::bitmap + i, 256);
        write_block(i / 256, data);
    }
    return 0;
}
int bitmap_namespace::load_bitmap()
{
    for (int i = 0; i < BLOCK_NUM_FS; i += 256)
    {
        char data[256];
        read_block(i / 256, data);
        memcpy(bitmap_namespace::bitmap + i, data, 256);
    }
    return 0;
}
int bitmap_namespace::judge_bitmap()
{
    for (int i = 0; i < BLOCK_NUM_FS; i++)
    {
        if (bitmap[i] != '0' && bitmap[i] != '1')
        {
            return -1;
        }
    }
    return 0;
}