# Analysis-and-Design
Data Structures and Algorithms
ABCU Course Advising Program

This project is a C++ command-line application designed to support academic advisors at ABCU. It loads a full course catalog from a CSV file into a Binary Search Tree, providing advisors with a fast and efficient tool to list all courses in alphanumeric order and look up specific course details, including prerequisites.

This repository contains the final C++ source code (Project Two) and the preceding design and analysis documentation (Project One).

Reflection

This document answers key questions about the project's design process, challenges, and learning outcomes.

What was the problem you were solving in the projects for this course?

The project aimed to solve a problem for academic advisors at ABCU. They required a software tool that could load a university's course catalog from a CSV file. The tool needed to perform two primary functions: (1) display an alphanumerically sorted list of all available courses, and (2) allow an advisor to search for a specific course by its number and display its title and all prerequisites. The core challenge was to build a program that was not only functional but also efficient in its data handling, searching, and sorting capabilities.

How did you approach the problem? Consider why data structures are important to understand.

The problem was approached with a "design-first" methodology. Instead of immediately coding, the initial phase involved a comprehensive analysis of the core requirements: data storage, fast searching, and sorted-list retrieval.

This is where understanding data structures became critical. The choice of data structure directly impacts the program's efficiency (its Big O runtime). To find the best solution, I designed and analyzed three potential implementations: a Vector, a Hash Table, and a Binary Search Tree.

This analysis showed a clear set of trade-offs:

Vector: Simple to implement, but slow search ($O(n)$) and slow sorting ($O(n \log n)$).

Hash Table: Fastest search ($O(1)$), but slow sorting ($O(n \log n)$) as it has no inherent order.

Binary Search Tree: A strong balance with fast search ($O(\log n)$) and uniquely fast sorted-list printing ($O(n)$) due to its natural in-order traversal.

Based on this analysis, the Binary Search Tree was selected as the optimal data structure before any C++ code was written, as it best balanced the project's requirements for both searching and sorting.

How did you overcome any roadblocks you encountered while going through the activities or project?

During development, several technical roadblocks emerged, particularly in the C++ implementation within Visual Studio.

File Loading in Visual Studio: The most significant challenge was getting the program to correctly load the CSV file. Initially, the standard "Copy to Output Directory" property was not available for my project type. I overcame this by learning to implement a Post-Build Event in the project settings, which manually copies the CSV file into the output directory (e.g., x64/Debug) at compile time.

Filenames with Spaces: The file still failed to load because the filename (CS 300 ABCU_Advising_Program_Input.csv) contained spaces. The cin command was only reading the first word. I resolved this by replacing cin >> csvPath with getline(cin, csvPath) and using cin.ignore() to clear the input buffer, allowing the program to read the entire filename.

Version Control Setup: When setting up the GitHub repository, I encountered an "Author identity unknown" error. I learned to configure my local Git identity using git config --global user.name "My Name" and git config --global user.email "my-email@example.com" to resolve the issue.

How has your work on this project expanded your approach to designing software and developing programs?

This project has fundamentally expanded my approach to software design. I've learned the critical value of a "design-first" process. Instead of just starting to code, the initial analysis and pseudocode phase proved to be the most important part of the project.

By analyzing the Big O runtime of three different data structures, I learned that the choice of data structure is not an arbitrary detail—it is the foundational decision that dictates the performance and efficiency of the entire application. This project has solidified the idea that how you store your data is just as important as what you do with it.

How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

This project was a major step forward in writing code that is truly maintainable, readable, and adaptable.

Readable: I moved from writing simple comments to using industry-standard documentation formats (like Doxygen's @brief and @param). This formal documentation makes the code's purpose clear not just for other developers, but also for automated tools.

Maintainable: The design emphasizes modularity. By encapsulating all tree logic within a BinarySearchTree class and separating tasks into distinct functions (e.g., loadCourses, displayCourse), the code is easier to debug and update. For example, if the file format changes, I only need to edit loadCourses, not the whole program. Using a C++ .gitignore file also ensures the repository remains clean and focused on source code, making it easier for others to manage.

Adaptable: The use of a class-based design means the data structure can be easily modified or extended. If a new requirement emerged (e.g., "delete a course"), it could be added as a new method to the BinarySearchTree class without breaking the existing menu logic in main().