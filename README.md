---
title: "🏦 Banking System (C++ CLI)"
description: "A secure, terminal-based banking system written in modern C++ with SHA-256 PIN hashing, CSV-based persistence, and OOP design."
author: "shyamdotexe"
license: "MIT"
language: "C++20"
---

# 🏦 Banking System (C++ CLI)

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)  
[![C++20](https://img.shields.io/badge/C%2B%2B-20-00599C?style=flat&logo=c%2B%2B&logoColor=white)](https://en.cppreference.com/w/cpp/20)  
[![OpenSSL](https://img.shields.io/badge/OpenSSL-SHA256-orange.svg)](https://www.openssl.org/)  
[![Build](https://img.shields.io/badge/Build-Passing-brightgreen.svg)]()  

A **simple, secure, and terminal-based banking application** built with modern C++.  
This project simulates basic banking operations while emphasizing **data security** and **safe file handling**.

---

## ✨ Features
- **Account Creation**
  - Auto-generates unique account numbers
  - Stores data in a CSV file for persistence
- **Secure PIN Handling**
  - PINs are hashed with **SHA-256** (OpenSSL)
  - No plain-text storage
- **Transactions**
  - Deposit and withdrawal with input validation
- **Safe Data Updates**
  - Uses a temporary file for atomic updates
- **User Experience**
  - PIN input masking in the console
  - Currency formatting with precision

---

## 📋 Requirements
- **C++11** or later compiler  
- [OpenSSL](https://www.openssl.org/) installed  
- Windows terminal (for `_getch()`) — can be adapted for Linux/Mac

---

## 🧠 C++ Concepts Used

**OOP Principles**
- Classes, objects, and encapsulation
- Inheritance & virtual function overriding

**File Handling**
- Reading/writing CSV files
- Atomic updates via temporary files

**Security**
- SHA-256 PIN hashing
- Masked input with _getch()

**Formatting**
- iomanip (setprecision, fixed) for currency display

**Memory Management**
- Smart pointers (std::unique_ptr)


## ⚙️ Build & Run
```bash
# Clone the repository
git clone https://github.com/shyamdotexe/BANKING-SYSTEM-CPP-CLI.git
cd BANKING-SYSTEM-CPP-CLI

# Compile (requires OpenSSL)
g++ banking.cpp -o banking -lssl -lcrypto

# Run
./banking
