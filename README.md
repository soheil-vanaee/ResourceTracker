Sure! Here's a **README** for your project:

---

# System Monitor - C Program

This is a simple system monitoring tool written in C using `ncurses` library. It provides a real-time display of the system's **CPU usage**, **Memory usage**, and **Disk usage** in a tabular format. The data is updated every second to show live system information.

### Features:
- Displays **CPU**, **Memory**, and **Disk usage** in a clean table format.
- Uses `ncurses` for terminal-based GUI.
- Live updates every second.
- Information is displayed in three columns: **CPU**, **Memory**, and **Disk**.
- No borders are around the table for a cleaner look.

### Screenshots
The following is an example of what the output will look like:

```
CPU      | Memory      | Disk
-----------------------------------
CPU Usage   : 25.5%    | Memory Usage: 4096 MB | Disk Usage  : 500 GB
CPU Usage   : 20.3%    | Memory Usage: 2048 MB | Disk Usage  : 200 GB
```

---

### Prerequisites
To run the program, you need to have the following tools installed on your system:
- **gcc**: GNU Compiler Collection to compile the C code.
- **ncurses**: A library for creating terminal-based user interfaces.

On macOS, you can install **ncurses** via `brew`:

```bash
brew install ncurses
```

On Ubuntu/Debian-based systems, you can install **ncurses** via `apt`:

```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
```

### Installation

1. **Clone the repository** (or copy the code to a folder):
    ```bash
    git clone https://your-repository-url
    cd your-project-folder
    ```

2. **Compile the code**:
    You can compile the C files using `gcc`:

    ```bash
    gcc main.c getinfo.c -o system_monitor -lncurses
    ```

    - `main.c`: The main program that initializes and displays the system info in a tabular format.
    - `getinfo.c`: Contains functions to fetch system information (CPU, memory, disk).
    - `getinfo.h`: The header file for the `getinfo.c` functions.

3. **Run the program**:

    After compiling, you can run the program like this:

    ```bash
    ./system_monitor
    ```

    This will open a terminal window displaying the live system stats.

---

### How It Works
1. **Memory Info**: 
   - Retrieves the total memory, used memory, and free memory of the system using the `sysctl` and `host_statistics64` system calls.
   - Displays the information in megabytes.

2. **CPU Info**: 
   - Retrieves the number of CPU cores using `sysctlbyname`.
   - Uses `getloadavg` to get the CPU load for 1, 5, and 15 minutes and displays the CPU load percentage.

3. **Disk Info**:
   - Uses the `statvfs` system call to get disk statistics (total space, free space, and used space).
   - Displays the disk usage in gigabytes.

4. **ncurses**:
   - The `ncurses` library is used for creating a user-friendly text-based interface.
   - The program continuously updates the data every second to show live statistics.

---

### How to Contribute
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-xyz`).
3. Make changes or add features.
4. Commit your changes (`git commit -am 'Add new feature'`).
5. Push to your forked repository (`git push origin feature-xyz`).
6. Open a pull request to the main repository.

---

### License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

### Contact
For any inquiries or questions, feel free to contact the project owner at:

- **Email**: your-email@example.com

---

This **README** provides an overview of how to use, install, and contribute to the system monitor tool.
