# Project — Bank and Currency Management System (OOP)

## Description

The **Bank and Currency Management System** is an extended C++ console application that evolves a basic object-oriented banking system into a broader management platform. In addition to user, client, and transaction workflows, the project introduces transfers and currency-management features.

The application is organized around reusable classes and specialized screens. It demonstrates how an existing system can grow through extensions while preserving a consistent object-oriented structure.

## Project Objectives

The main objectives of this project are to:

- Extend a banking application without discarding its existing domain model.
- Apply encapsulation, abstraction, inheritance, and polymorphism in a larger workflow.
- Implement transfer operations between client accounts.
- Add currency search, listing, calculation, and rate-update functionality.
- Record login and transfer activity using local text-file persistence.
- Practice permission-controlled management screens and reusable validation.

## System Overview

The system simulates a small banking platform with the following capabilities:

- User login and role-based permissions.
- Client creation, listing, search, update, and deletion.
- Deposits and withdrawals with balance validation.
- Account-to-account transfers with transfer logging.
- Currency listing and currency search.
- Currency-rate updates and currency conversion calculations.
- Total-balance reporting.
- Login-register and transfer-audit records.

All bundled records are **fictional demo data** created for this public repository. The demonstration login is `demo.admin` with password `demo123`.

## Architecture

```text
Bank and Currency System
├── Core Domain Classes
│   ├── clsPerson
│   ├── clsUser
│   ├── clsBankClient
│   └── clsCurrency
├── Presentation Layer
│   ├── Login and main screens
│   ├── User-management screens
│   ├── Client-management screens
│   ├── Transaction screens
│   └── Currency-management screens
├── Shared Utilities
│   ├── clsDate
│   ├── clsString
│   ├── clsInputValidate
│   └── clsUtil
└── File-Based Storage
    ├── Users.txt
    ├── Clients.txt
    ├── Currencies.txt
    ├── LoginRegister.txt
    └── TransferLog.txt
```

The design keeps domain objects, interactive screens, and file operations in separate responsibilities. Specialized screen classes build on shared behavior from base screen classes, while the data classes convert records between text lines and C++ objects.

## Technologies Used

- **C++** for the complete application implementation.
- **Object-oriented programming** with inheritance, encapsulation, abstraction, and polymorphism.
- **File-based persistence** using standard C++ file streams.
- **Console user interface** with menu-driven navigation.
- **Visual Studio solution and project files** for development and compilation.

## Extensions and Features Implemented

| Extension or feature | Description | Key concept |
| --- | --- | --- |
| Authentication | Login workflow with repeated attempts and audit records. | Encapsulation, persistence |
| Permission management | Control access to client, transaction, user, and audit screens. | Abstraction, bitwise flags |
| Client management | Add, list, find, update, and delete bank clients. | CRUD, class design |
| Transactions | Deposit and withdraw funds while validating balances. | Business rules |
| Transfers | Transfer funds between two client accounts and log the operation. | Modularization, persistence |
| Currency management | List, find, and update currency exchange rates. | Encapsulation |
| Currency calculator | Convert values using stored currency rates. | Composition, calculations |
| Balance reporting | Calculate and display total client balances. | Aggregation |

## Key Takeaways

This project shows how a system can expand through carefully separated extensions. New currency and transfer features are represented by dedicated classes and screens rather than being inserted into one large function.

The project also demonstrates the importance of persistence boundaries. Client, user, currency, login, and transfer data are handled through their respective files, while the rest of the application works with structured objects and business operations.

## How to Run

1. Open `Lesson #01 - Find Client.sln` in Visual Studio on Windows.
2. Build the solution with the available C++ configuration.
3. Run the application from the project directory so that the relative data files are available.
4. Use the demo credentials `demo.admin` and `demo123` to access the system.

## Final Notes

This repository is an educational project for practicing object-oriented design, console application architecture, file handling, permissions, banking transactions, and currency operations. It is not a production banking platform and contains no real financial records.
