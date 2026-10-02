# 🏥 Hospital Token System

A simple, menu-driven **C++ console application** that manages patient registration and the waiting queue in a hospital OPD. Patients get a unique token number on registration and are served in **first-come, first-served (FIFO)** order.

---

## ✨ Features

- **Add Patient**: Register a patient with name, age, phone number and department. A unique token number is generated automatically.
- **Phone Validation**: Phone number must be exactly 10 digits (numbers only); invalid input is rejected and re-asked.
- **Display Waiting Patients**: Shows all waiting patients in a neat, aligned table.
- **Call Next Patient**: Serves the patient at the front of the queue and removes them from the waiting list.
- **Search Patient**: Look up a waiting patient by token number.

---

## 🛠️ Tech Stack

| Item | Details |
|------|---------|
| Language | C++ |
| Concepts | Structs, `std::vector` (as a queue), string handling, input validation, formatted output (`<iomanip>`) |
| Libraries | `<iostream>`, `<vector>`, `<string>`, `<iomanip>`, `<cctype>` |

---

## 🚀 Getting Started

### Prerequisites
A C++ compiler such as **g++** (MinGW on Windows, or GCC on Linux/macOS).

### Compile and Run

```bash
# Clone the repository
git clone https://github.com/vighneshgaikwad59-web/<your-repo-name>.git
cd <your-repo-name>

# Compile
g++ mini.cpp -o mini

# Run (Linux/macOS)
./mini

# Run (Windows)
mini.exe
```

---

## 📋 Usage

When the program starts, you will see this menu:

```
----------- MAIN MENU -----------
1. Add Patient
2. Display Waiting Patients
3. Call Next Patient
4. Search Patient
5. Exit
---------------------------------
```

### Sample Output

```
========== WAITING PATIENTS ==========
Token     Name                Age       Phone          Department
------------------------------------------------------------------------
1         Rahul Sharma        34        9876543210     Cardiology
2         Priya Patil         28        9123456780     Orthopedics
```

```
====================================
       NOW SERVING PATIENT
====================================
Token      : 1
Name       : Rahul Sharma
Age        : 34
Phone      : 9876543210
Department : Cardiology
====================================
```

---

## 🧠 How It Works

- Each patient is stored in a `Patient` struct (`token`, `name`, `age`, `phone`, `department`).
- All patients are kept in a global `vector<Patient>`, which acts as the waiting queue.
- `nextToken` is incremented on every registration, so tokens are never repeated during a run.
- **Call Next Patient** reads the first element of the vector and then erases it, which gives FIFO behaviour.

---

## ⚠️ Known Limitations

- Data is stored in memory only, so it is lost when the program exits.
- Age and menu choice are not validated; entering non-numeric input can cause unexpected behaviour.
- Search works only on patients who are still waiting (served patients are removed).
- There is no priority handling for emergency cases.

## 🔮 Future Improvements

- Save and load patient records from a file (CSV/JSON) or a database
- Input validation for age and menu choices
- Emergency / priority queue
- Separate queues per department
- Use `std::queue` or `std::deque` for more efficient removal from the front

---

## 👤 Author

**Vighnesh Anand Gaikwad**
GitHub: [@vighneshgaikwad59-web](https://github.com/vighneshgaikwad59-web)

---

## 📄 License

This project is open source and available for learning purposes.
