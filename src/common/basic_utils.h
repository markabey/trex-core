#ifndef _BASIC_UTILS_H
#define _BASIC_UTILS_H

/*
Copyright (c) 2015-2015 Cisco Systems, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "c_common.h"
#include <stdio.h>
#include <string>

/**
 * the round must be power 2 e.g 2,4,8...
 * 
 * @param num
 * @param round
 * @return 
 */
inline uint utl_align_up(uint num,uint round){
    if ((num & ((round-1)) )==0) {
        //the number align
        return(num);
    }
    return( (num+round) & (~(round-1)) );
}

inline uint utl_align_down(uint num,uint round){
    return( (num) & (~(round-1)) );
}

void utl_k12_pkt_format(FILE* fp,void  * src,  unsigned int size) ;

void utl_DumpBuffer(FILE* fp,void  * src,  unsigned int size,int offset=0);



#define SHOW_BUFFER_ADDR_EN     1
#define SHOW_BUFFER_ADDR        2
#define SHOW_BUFFER_CHAR        4

#define SHOW_BUFFER_ALL (SHOW_BUFFER_ADDR_EN|SHOW_BUFFER_ADDR|SHOW_BUFFER_CHAR)

void utl_DumpBuffer2(FILE* fd,
                     void  * src,  
                     unsigned int size, //buffer size
                     unsigned int width ,
                     unsigned int width_line ,
                     unsigned int mask);



#undef min
#undef max

template <class T>
inline const T& utl_min(const T& a, const T& b) {
  return b < a ? b : a;
}

template <class T>
inline const T& utl_max(const T& a, const T& b) {
  return  a < b ? b : a;
}

template <class T>
inline void utl_swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}


bool utl_is_file_exists (const std::string& name) ;

void utl_macaddr_to_str(const uint8_t *macaddr, std::string &output);
std::string utl_macaddr_to_str(const uint8_t *macaddr);

bool utl_str_to_macaddr(const std::string &s, uint8_t *mac);

std::string utl_generate_random_str(unsigned int &seed, int len);

/**
 * define the coredump size 
 * allowed when crashing 
 * 
 * @param size - -1 means unlimited
 * @param map_huge_pages - should the core map the huge TLB 
 *                       pages
 */
void utl_set_coredump_size(long size, bool map_huge_pages = false);

uint32_t       utl_ipv4_to_uint32(const char *ipv4_str, uint32_t &ipv4_num);
std::string    utl_uint32_to_ipv4(uint32_t ipv4_addr);
   
#endif


