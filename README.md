# Disaster Relief Resource Distribution System

A C++ system designed to help disaster management agencies efficiently allocate critical relief items (food, medicine, and shelter). This program uses a priority queue to ensure resources are always distributed to the areas with the highest severity of need first.

## 👥 Team & Roles

This project was built collaboratively by our team. Responsibilities were divided as follows:

* **[Heritier](https://github.com/HERITIERS_GITHUB_USERNAME_HERE)** (Person A - Inventory Manager): Implemented the array-based tracking system for available supplies and the logic to safely deduct inventory as requests are fulfilled.
* **[Yvonne](https://github.com/YVONNES_GITHUB_USERNAME_HERE)** (Person B - Queue Master): Implemented the `ReliefRequest` data structure and the C++ `std::priority_queue` to automatically sort incoming requests by severity level (1-10).
* **[Mustafa](https://github.com/buster_call_Root)** (Person C - System Integrator): Designed the main execution loop, integrated the inventory and queue modules, and built the final reporting mechanism.

## ⚙️ Core Features

* **Priority-Based Sorting:** Requests are handled strictly based on urgency using a priority queue.
* **Inventory Tracking:** Real-time updates to food, medicine, and shelter stock using arrays.
* **Automated Fulfillment:** The system checks available stock against the highest-priority request and distributes items if possible.
* **Distribution Reporting:** Generates a final summary of what was distributed and the remaining inventory levels.

## 🗂️ Project Structure
* `ReliefRequest.h`: The shared data contract defining a disaster relief request.
* `InventoryManager.h` / `.cpp`: Logic for tracking and updating supply arrays.
* `RequestQueue.h` / `.cpp`: Logic for managing the priority queue of requests.
* `main.cpp`: The core execution loop integrating all components.

## 🚀 How to Compile and Run

1. Clone the repository to your local machine:
   ```bash
   git clone [https://github.com/buster_call_Root/disaster-relief-system.git](https://github.com/buster_call_Root/disaster-relief-system.git)

2. Navigate to the project directory.

3. Compile all the source files together using g++:
    ```bash
    g++ main.cpp InventoryManager.cpp RequestQueue.cpp -o relief_system

4. Run the compiled executable:
    ```bash
    ./relief_system