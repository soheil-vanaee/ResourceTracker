#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mach/mach.h>
#include <sys/sysctl.h>
#include <sys/statvfs.h>
#include <ncurses.h>
#include "getinfo.h"

// Function to get memory information
void memory_info(WINDOW *win) {
    int64_t total_memory;
    size_t size = sizeof(total_memory);
    sysctlbyname("hw.memsize", &total_memory, &size, NULL, 0);

    mach_msg_type_number_t count = HOST_VM_INFO64_COUNT;
    vm_statistics64_data_t vm_stat;
    kern_return_t kr = host_statistics64(mach_host_self(), HOST_VM_INFO64, (host_info64_t)&vm_stat, &count);

    if (kr != KERN_SUCCESS) {
        mvwprintw(win, 1, 2, "Failed to fetch memory info");
        return;
    }

    int64_t page_size;
    sysctlbyname("hw.pagesize", &page_size, &size, NULL, 0);

    int64_t used_memory = (vm_stat.active_count + vm_stat.wire_count) * page_size;
    int64_t free_memory = vm_stat.free_count * page_size;

    mvwprintw(win, 1, 2, "Memory Usage:");
    mvwprintw(win, 2, 2, "  Total: %lld MB", total_memory / (1024 * 1024));
    mvwprintw(win, 3, 2, "  Used: %lld MB", used_memory / (1024 * 1024));
    mvwprintw(win, 4, 2, "  Free: %lld MB", free_memory / (1024 * 1024));
}

// Function to get CPU information
void cpu_info(WINDOW *win) {
    int num_cpu;
    size_t size = sizeof(num_cpu);
    sysctlbyname("hw.ncpu", &num_cpu, &size, NULL, 0);

    double load[3];
    getloadavg(load, 3);

    mvwprintw(win, 6, 2, "CPU Usage:");
    mvwprintw(win, 7, 2, "  Cores: %d", num_cpu);
    mvwprintw(win, 8, 2, "  Load (1m): %.2f%%", load[0] * 100 / num_cpu);
}

// Function to get disk information
void disk_info(WINDOW *win) {
    struct statvfs stat;

    if (statvfs("/", &stat) != 0) {
        mvwprintw(win, 10, 2, "Failed to fetch disk info");
        return;
    }

    unsigned long total_space = (stat.f_blocks * stat.f_frsize) / (1024 * 1024);
    unsigned long free_space = (stat.f_bfree * stat.f_frsize) / (1024 * 1024);
    unsigned long used_space = total_space - free_space;

    mvwprintw(win, 10, 2, "Disk Usage:");
    mvwprintw(win, 11, 2, "  Total: %lu MB", total_space);
    mvwprintw(win, 12, 2, "  Used: %lu MB", used_space);
    mvwprintw(win, 13, 2, "  Free: %lu MB", free_space);
}
