# Software-Test-Automation-QA
Software Testing and Automation 
# Mobile Application Services (CS 320)

![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=java&logoColor=white)
![JUnit 5](https://img.shields.io/badge/JUnit5-25A162?style=for-the-badge&logo=junit5&logoColor=white)
![Coverage](https://img.shields.io/badge/Coverage-80%25%2B-brightgreen?style=for-the-badge)

## Project Overview
This repository contains the backend service components for a mobile application, developed as part of the **CS 320: Software Test, Automation QA** curriculum. The project focuses on creating robust, secure, and testable code for three core services:
* **Contact Service:** Manages contact profiles.
* **Task Service:** Manages user tasks.
* **Appointment Service:** Manages scheduling.

The primary objective of this project was to implement rigorous **Unit Testing** to achieve over 80% code coverage and ensure compliance with strict business requirements.

## Project Structure
The project is organized into three main packages, each containing an object class (Model) and a service class (Logic).

```text
src/
├── main/
│   └── java/
│       └── services/
│           ├── Appointment.java
│           ├── AppointmentService.java
│           ├── Contact.java
│           ├── ContactService.java
│           ├── Task.java
│           └── TaskService.java
└── test/
    └── java/
        └── services/
            ├── AppointmentTest.java
            ├── AppointmentServiceTest.java
            ├── ContactTest.java
            ├── ContactServiceTest.java
            ├── TaskTest.java
            └── TaskServiceTest.java
```
---
>**How can I ensure that my code, program, or software is functional and secure?**

To ensure functionality, I employed comprehensive Unit Testing using JUnit 5. By writing tests that covered both valid inputs (happy paths) and invalid inputs (edge cases), I verified that the software behaved exactly as expected under various conditions. I achieved a code coverage of over 80%, ensuring that logic branches and exception handling were rigorously tested.

To ensure security, I implemented defensive programming techniques within the object classes:

Input Validation: Every constructor and setter immediately validates inputs (checking for nulls or length violations) to prevent invalid data from ever entering the system.

Encapsulation: I used private variables and restricted access methods (no setters for final fields like IDs) to protect the data integrity of the objects.

Exception Handling: By throwing specific exceptions (e.g., IllegalArgumentException), the program fails safely and predictably rather than producing undefined behavior.

---
>**How do I interpret user needs and incorporate them into a program?**

Interpreting user needs involves translating vague or high-level requirements into concrete technical specifications. For this project, I analyzed the client requirements (e.g., "Contacts must have a unique ID that cannot be updated") and mapped them directly to Java implementation details.

Requirement Analysis: I broke down the requirements into a checklist of constraints for each object field (e.g., maxLength=10, nullable=false).

Implementation: I incorporated these needs by writing logic that strictly enforced these constraints. For example, if a user need was to prevent past appointment dates, I implemented a check date.before(new Date()) inside the Appointment class.

Feedback Loop: I used the unit tests as a feedback mechanism. If a test representing a user requirement failed, I knew the code did not yet fully meet the user's needs.

---
>**How do I approach designing software?**

My approach to software design is modular and incremental.

Separation of Concerns: I separated the project into distinct components: the Object (data model) and the Service (business logic). This ensures that the code is organized, maintainable, and easier to debug.

Iterative Development: I built the application one piece at a time—starting with the Contact object, then the ContactService, and finally the tests. This allowed me to isolate issues quickly before moving to the next module.

Test-Driven Mindset: Although I wrote the code first, I designed the classes with testing in mind. I ensured methods were small, focused, and testable, avoiding complex dependencies that would make verification difficult.
