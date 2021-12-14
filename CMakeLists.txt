cmake_minimum_required(VERSION 3.17)
project(OSL C)

set(CMAKE_C_STANDARD 99)

add_executable(OSL main.c rough.c A3/A3_srtf_with_arrival_time.c A5/A5.c
        A8.c A2a/A2a_orphan.c A2a/A2a_zombie.c A2b/A2b_child.c A2b/A2b_parent.c
        A3/A3_sjf_without_arrival_time.c rough2.c rough3.c A3/A3_round_robin_.c rough4.c A4a/A4a_producer_consumer.c
        A4b/A4b_reader_writer.c A5/A5_bankers_algo.c A6/A6_fifo.c rough5.c A7a/A7a_fifo1.c A7a/A7a_fifo2.c A7b/A7b_reader.c
        A7b/A7b_writer.c rough6.c A2a/orphan.c A2a/zombie.c A6/A6_lru.c A1b/A1b_address_book.sh A3/A3_round_robin.cpp
        A3/A3_round_robin_using_queue.c)