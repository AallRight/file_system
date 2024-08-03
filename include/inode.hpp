#ifndef FILE_SYSTEM_INODE_HPP
#define FILE_SYSTEM_INODE_HPP
#include "BDS.hpp"

namespace inode_namespace{
    typedef struct inode{
        // 256 bytes = 64 int
        int16_t file_type; // 0: file, 1: directory
        int16_t user_id;
        int16_t group_id;
        int16_t permission;
        int file_size;
        int inode_block_id;
        int parent_inode_block_id;
        int block_num_allocated;
        int name_block_id;
        int access_time;
    } inode;
    typedef struct name_blcok{
        char name[252];
        int inode_block_id;
    } name_block;
    int read_inode(int inode_number, inode *inode);
    int write_inode(int inode_number, inode *inode);
    int get_inode_number();
    int set_inode_number(int inode_number);
    int get_inode_block(int inode_number, int block_number, char *data);
    int set_inode_block(int inode_number, int block_number, char *data);
    int get_inode_block_size(int inode_number);
    int set_inode_block_size(int inode_number, int block_size);
    int get_inode_file_size(int inode_number);
    int set_inode_file_size(int inode_number, int file_size);
    int get_inode_block_number(int inode_number);
    int set_inode_block_number(int inode_number, int block_number);
    int get_inode_block(int inode_number, int block_number, char *data);
    int set_inode_block(int inode_number, int block_number, char *data);
    int get_inode_block_size(int inode_number);
    int set_inode_block_size(int inode_number, int block_size);
    int get_inode_file_size(int inode_number);
    int set_inode_file_size(int inode_number, int file_size);
    int get_inode_block_number(int inode_number);
    int set_inode_block_number(int inode_number, int block_number);
}

#endif
