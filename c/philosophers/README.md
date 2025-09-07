# philosophers

> The Dining Philosophers problem — solved with threads and mutexes.

A C program that simulates the classic **Dining Philosophers** concurrency problem using **pthreads** and **mutexes**. The goal is to prevent deadlock and starvation while ensuring all philosophers can eat, think, and sleep safely.

---

### 🛠️ Features (Mandatory)

- **Multithreaded Simulation**: Each philosopher runs as a separate thread.
- **Fork Management**: Each fork is protected by a **mutex** to prevent race conditions.
- **State Logging**: Logs philosopher states with timestamps:
  - `X has taken a fork`
  - `X is eating`
  - `X is sleeping`
  - `X is thinking`
  - `X died`
- **Death Detection**: If a philosopher doesn’t eat within `time_to_die`, the simulation stops.
- **Optional End Condition**: If `number_of_times_each_philosopher_must_eat` is provided, the simulation ends when all philosophers reach that count.
- **No Global Variables**: Only allowed functions used, and no globals (except for shared data passed via structs).

---

### 🧰 Tech Stack
- **Language**: C
- **Concurrency**: `pthreads` (POSIX threads)
- **Synchronization**: `pthread_mutex_t` for fork protection
- **Tools**: `make`, `gcc` with `-Wall -Wextra -Werror -pthread`
- **Standard**: C89
- **Key Functions**: `pthread_create`, `pthread_join`, `pthread_mutex_init`, `gettimeofday`, `usleep`
