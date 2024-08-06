#ifndef BDS_HPP
#define BDS_HPP
#include "disk.hpp"
namespace bds{
    int open_BDS();
    int read_data(int cylindernum, int blocknum, char *data);
    int write_data(int cylindernum, int blocknum, char *data);
    int data_operation(int operations_types, int cylinder_num, int sector_num, char *data);
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
int data_operation(int operations_types, int cylinder_num, int sector_num, char *data){
    if(operations_types == 0){
        return bds::read_data(cylinder_num, sector_num, data);
    }
    else if(operations_types == 1){
        return bds::write_data(cylinder_num, sector_num, data);
    }
}


#endif