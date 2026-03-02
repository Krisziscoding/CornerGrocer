# Corner Grocer: Inventory Item Tracker

A C++ data analysis tool designed for real-time inventory tracking. The application processes bulk grocery transaction data, calculates item frequencies, and provides multiple visualization formats including formatted tables and histograms.

## 🛠️ Technical Overview
This project demonstrates advanced C++ concepts, focusing on efficient data storage and retrieval. Key technical implementations include:

- **Optimized Data Retrieval:** Utilizes `std::map` to store item frequencies, ensuring $O(\log n)$ time complexity for insertions and lookups.
- **Data Normalization:** Implements a robust string preprocessing layer to convert all inputs to lowercase, ensuring "Apples" and "apples" are treated as the same entity.
- **Persistence & Redundancy:** Automatically generates a `frequency.dat` backup file upon initialization, ensuring data integrity and availability for downstream processes.
- **Encapsulated Design:** Built using an Object-Oriented (OOP) approach. The `GroceryTracker` class protects data members while exposing functionality through a clean public API.

## 📊 Features
1. **Individual Item Search:** Quickly retrieve the specific count for any item in the database.
2. **Frequency Report:** A complete list of all unique items and their total counts, sorted alphabetically by default via the map structure.
3. **Histogram Visualization:** A graphical representation of data using `std::setw` for alignment and custom character scaling (using `*`) to represent volume.
4. **Input Validation:** Integrated error handling to prevent infinite loops from invalid data types or out-of-bounds menu selections.

## 🚀 How to Run
1. **Prerequisites:** Ensure you have a C++ compiler (GCC, Clang, or MSVC) and the input file `CS210_Project_Three_Input_File.txt` in the root directory.
2. **Compile:**
   ```bash
   g++ main.cpp -o CornerGrocer
