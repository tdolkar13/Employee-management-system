# 📊 Employee Management System (EMS)
**Final Project | C Programming 

## 📝 Project Overview
This Employee Management System is a Console based system designed to streamline the handling of staff records. Developed as a final project, it focuses on efficient data management using C, utilizing file handling for persistence and structures for organized data storage.

## 🎓 Presentation Details
- **Project Name:** Employee Management System
- **Developer:** Thupten Dolkar lama
- **Core Technology:** C Language, GCC Compiler, Makefile
- **Project Documentation:**[📄 View Final Presentation (PDF)](./Final_Presentation.pdf)**


## 🛠️ Key Technical Features
- **CRUD Operations:** Full capability to Create, Read, Update, and Delete records.
- **File Persistence:** Uses `file_handler.c` to read/write to `.txt` or `.dat` files, ensuring data isn't lost.
- **Header Files:** Custom `employee.h` for robust structure definitions.
- **Memory Management:** Efficient use of memory and buffers for string handling.

## 📁 Repository Structure
| File | Description |
| :--- | :--- |
| `main.c` | Program entry point and menu-driven interface. |
| `employment.c` | Core logic for adding and listing employee data. |
| `file_handler.c` | Manages data storage and retrieval from disk. |
| `utils.c` | Reusable helper functions for input validation. |
| `Makefile` | Automates the compilation process. |
| `EMS_Final_Presentation.pptx` | The official project presentation slide deck. |

## 🚀 Execution Guide
To run this project locally, ensure you have `gcc` and `make` installed.

1. **Compile:**
   ```bash
   make
