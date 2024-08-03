#ifndef BDS_HPP
#define BDS_HPP
#include "disk.hpp"

namespace bds{
    int open_BDS();
    int read_data(int cylindernum, int blocknum, char *data);
    int write_data(int cylindernum, int blocknum, char *data);
    int close_BDS();
}
int bds::open_BDS(){
    return disk::map_diskfile();
}
int bds::read_data(int cylindernum, int blocknum, char *data){
    return disk::read_block(cylindernum, blocknum, data);
}
int bds::write_data(int cylindernum, int blocknum, char *data){
    // if there is error
    return disk::write_block(cylindernum, blocknum, data);
}
int bds::close_BDS(){
    return disk::umap_diskfile();
}


#endif