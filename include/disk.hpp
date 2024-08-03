#ifndef DISK_HPP
#define DISK_HPP
#include <string>
#include <vector>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h> // Add this line to include the header file for mmap
#include <cstring> // Add this line to include the header file for memcpy
// cylinder num, block num in cylinder, block size are defined
#define BLOCK_SIZE 256
#define BLOCKS_PER_cylinder 100
#define CYLINDERS 100
#define DISKSIZE 256*100*100;
char *diskfile;
char *diskfile_name = "/home/workspace/zxn/file_system/include/disk";
namespace disk{
    int map_diskfile();
    int umap_diskfile();
    int write_block(int cylindernum, int blocknum, char *data);// 256
    int read_block(int cylindernum, int blocknum, char *data);// 256
}
int disk::map_diskfile(){
    int fd = open(diskfile_name, O_RDWR | O_CREAT, 0);
    if(fd == -1){
        std::cerr << "Error: open disk file" << std::endl;
        exit(-1);
        return -1;
    }
    long disksize = DISKSIZE;
    if(ftruncate (fd, disksize) == -1){
        std::cerr << "Error: truncate disk file" << std::endl;
        exit(-1);
        return -1;
    }
    diskfile = (char *)mmap(NULL, disksize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(diskfile == MAP_FAILED){
        std::cerr << "Error: mmap disk file" << std::endl;
        close(fd);
        exit(-1);
        return -1;
    }
    return 0;
}

int disk::write_block(int cylindernum, int blocknum, char *data){
    if(cylindernum < 0 || cylindernum >= CYLINDERS){
        std::cerr << "Error: cylinder number out of range" << std::endl;
        return -1;
    }
    if(blocknum < 0 || blocknum >= BLOCKS_PER_cylinder){
        std::cerr << "Error: block number out of range" << std::endl;
        return -1;
    }
    if(data == NULL){
        std::cerr << "Error: data is NULL" << std::endl;
        return -1;
    }
    char *block = diskfile + cylindernum * BLOCKS_PER_cylinder * BLOCK_SIZE + blocknum * BLOCK_SIZE;
    memcpy(block, data, BLOCK_SIZE);
    return 0;
}
int disk::read_block(int cylindernum, int blocknum, char *data){
    if(cylindernum < 0 || cylindernum >= CYLINDERS){
        std::cerr << "Error: cylinder number out of range" << std::endl;
        return -1;
    }
    if(blocknum < 0 || blocknum >= BLOCKS_PER_cylinder){
        std::cerr << "Error: block number out of range" << std::endl;
        return -1;
    }
    if(data == NULL){
        std::cerr << "Error: data is NULL" << std::endl;
        return -1;
    }
    char *block = diskfile + cylindernum * BLOCKS_PER_cylinder * BLOCK_SIZE + blocknum * BLOCK_SIZE;
    memcpy(data, block, BLOCK_SIZE);
    return 0;
}

int disk::umap_diskfile(){
    long disksize = DISKSIZE;
    if(munmap(diskfile, disksize) == -1){
        std::cerr << "Error: munmap disk file" << std::endl;
        exit(-1);
        return -1;
    }
    return 0;
}

#endif