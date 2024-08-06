#ifndef FILE_SYSTEM_INODE_HPP
#define FILE_SYSTEM_INODE_HPP
#include "BDS.hpp"
#include <time.h>
#include <semaphore.h>
#include <semaphore>

namespace inode_namespace
{
    typedef struct inode_data
    {
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
    }inode_data;
    

    class Inode
    {
    public:
        inode_data data;
        Inode(inode_data data) : data(data)
        {
            
        }
        virtual int get_block_id_by_index(int index){}
        virtual ~Inode(){}
    };

    typedef struct name_blcok
    {
        char name[252];
        int inode_block_id;
    } name_block;
    int read_block(int block_id, char *data);
    int write_block(int block_id, char *data);
    namespace bitmap_namespace
    {
#define BLOCK_NUM_FS 1024
        char bitmap[BLOCK_NUM_FS];
        sem_t bitmap_sem[BLOCK_NUM_FS];
        int init_semaphore()
        {
            for (int i = 0; i < BLOCK_NUM_FS; i++)
            {
                sem_init(&bitmap_sem[i], 0, 1);
            }
            return 0;
        }
        int destroy_semaphore()
        {
            for (int i = 0; i < BLOCK_NUM_FS; i++)
            {
                sem_destroy(&bitmap_sem[i]);
            }
            return 0;
        }
        int load_bitmap();
        int store_bitmap();
        int judge_bitmap();
        int get_free_block();
    }

}


int inode_namespace::read_block(int block_id, char *data)
{
    return bds::read_data(0, block_id, data);
}
int inode_namespace::write_block(int block_id, char *data)
{
    return bds::write_data(0, block_id, data);
}
#endif
