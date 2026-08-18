//============================================================================
// Name        : ProjectTwo.cpp
// Author      : Corey Peterson
// Version     : 1.0
// Description : Course Advising Program
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <fstream>  // For file input/output
#include <sstream>  // For parsing strings

using namespace std;

// Forward declaration of the BinarySearchTree class
class BinarySearchTree;

// =================================
// DATA STRUCTURES
// =================================

/**
 * @struct Course
 * @brief Represents a single course with its number, name, and prerequisites.
 */
struct Course {
    string courseNumber;
    string name;
    vector<string> prerequisites;

    // Default constructor
    Course() {}

    // Parameterized constructor for convenience
    Course(string num, string n) : courseNumber(num), name(n) {}
};

/**
 * @struct Node
 * @brief Represents a node in the Binary Search Tree, containing a Course object.
 */
struct Node {
    Course course;
    Node* left;
    Node* right;

    // Default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // Initialize with a course
    Node(Course aCourse) : Node() {
        this->course = aCourse;
    }
};

// =================================
// BINARY SEARCH TREE CLASS
// =================================

/**
 * @class BinarySearchTree
 * @brief Manages the collection of courses using a BST data structure.
 */
class BinarySearchTree {
private:
    Node* root;

    void addNode(Node* node, Course course);
    void inOrder(Node* node, const BinarySearchTree* bst) const; // Pass bst to search for prerequisite names
    Node* searchNode(Node* node, string courseNumber) const;

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void Insert(Course course);
    Course Search(string courseNumber);
    bool IsEmpty() const;
    void DestroyRecursive(Node* node);
};

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    DestroyRecursive(root);
}

/**
 * Recursively destroy the tree to free memory.
 */
void BinarySearchTree::DestroyRecursive(Node* node) {
    if (node) {
        DestroyRecursive(node->left);
        DestroyRecursive(node->right);
        delete node;
    }
}


/**
 * Check if the tree is empty.
 */
bool BinarySearchTree::IsEmpty() const {
    return root == nullptr;
}

/**
 * Public method to begin in-order traversal.
 */
void BinarySearchTree::InOrder() {
    this->inOrder(root, this);
}

/**
 * Public method to insert a course.
 */
void BinarySearchTree::Insert(Course course) {
    if (root == nullptr) {
        root = new Node(course);
    }
    else {
        this->addNode(root, course);
    }
}

/**
 * Public method to search for a course.
 * Returns the found course or an empty course object if not found.
 */
Course BinarySearchTree::Search(string courseNumber) {
    Node* resultNode = this->searchNode(root, courseNumber);
    if (resultNode != nullptr) {
        return resultNode->course;
    }
    // Return an empty course if not found
    return Course();
}

/**
 * Private recursive method to add a node to the tree.
 */
void BinarySearchTree::addNode(Node* node, Course course) {
    // If the new course number is smaller, go to the left subtree
    if (course.courseNumber.compare(node->course.courseNumber) < 0) {
        if (node->left == nullptr) {
            node->left = new Node(course);
        }
        else {
            this->addNode(node->left, course);
        }
    }
    // Else, go to the right subtree
    else {
        if (node->right == nullptr) {
            node->right = new Node(course);
        }
        else {
            this->addNode(node->right, course);
        }
    }
}

/**
 * Private recursive method for in-order traversal to print all courses.
 */
void BinarySearchTree::inOrder(Node* node, const BinarySearchTree* bst) const {
    if (node != nullptr) {
        inOrder(node->left, bst);
        cout << node->course.courseNumber << ", " << node->course.name << endl;
        inOrder(node->right, bst);
    }
}

/**
 * Private recursive method to search for a node by course number.
 */
Node* BinarySearchTree::searchNode(Node* node, string courseNumber) const {
    if (node == nullptr) {
        return nullptr;
    }

    // Compare course numbers (case-insensitive for robustness)
    string currentCourseNum = node->course.courseNumber;
    string targetCourseNum = courseNumber;
    // Simple transform to upper for comparison
    for (auto& c : currentCourseNum) c = toupper(c);
    for (auto& c : targetCourseNum) c = toupper(c);

    if (targetCourseNum.compare(currentCourseNum) == 0) {
        return node;
    }
    else if (targetCourseNum.compare(currentCourseNum) < 0) {
        return searchNode(node->left, courseNumber);
    }
    else {
        return searchNode(node->right, courseNumber);
    }
}


// =================================
// HELPER FUNCTIONS & MAIN LOGIC
// =================================

/**
 * @brief Loads courses from a CSV file into the Binary Search Tree.
 *
 * @param csvPath The path to the CSV file.
 * @param bst A pointer to the BinarySearchTree to populate.
 */
void loadCourses(string csvPath, BinarySearchTree* bst) {
    cout << "Loading file: " << csvPath << endl;

    ifstream file(csvPath);
    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        // Skip empty lines or lines that might just have whitespace
        if (line.empty() || line.find_first_not_of(" \t\r\n") == string::npos) {
            continue;
        }

        stringstream ss(line);
        vector<string> tokens;
        string token;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        // A valid course line must have at least a number and a name.
        if (tokens.size() >= 2) {
            Course newCourse(tokens[0], tokens[1]);
            // If there are prerequisites, add them to the course object
            for (size_t i = 2; i < tokens.size(); ++i) {
                newCourse.prerequisites.push_back(tokens[i]);
            }
            bst->Insert(newCourse);
        }
        else {
            cout << "Warning: Ignoring invalid line: " << line << endl;
        }
    }
    file.close();
    cout << "Data loaded successfully." << endl;
}

/**
 * @brief Displays information for a single course.
 *
 * @param course The course object to display.
 * @param bst A pointer to the BST to look up prerequisite names.
 */
void displayCourse(const Course& course, BinarySearchTree* bst) {
    cout << course.courseNumber << ", " << course.name << endl;
    cout << "Prerequisites: ";
    if (course.prerequisites.empty()) {
        cout << "None" << endl;
    }
    else {
        for (size_t i = 0; i < course.prerequisites.size(); ++i) {
            // Find the full course name for the prerequisite
            Course prereq = bst->Search(course.prerequisites[i]);
            cout << prereq.courseNumber << " (" << prereq.name << ")";
            if (i < course.prerequisites.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

/**
 * @brief Main function containing the program's menu loop.
 */
int main() {
    BinarySearchTree* bst = new BinarySearchTree();
    string csvPath, courseKey;
    int choice = 0;

    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {
        cout << "\n  1. Load Data Structure." << endl;
        cout << "  2. Print Course List." << endl;
        cout << "  3. Print Course." << endl;
        cout << "  9. Exit" << endl;
        cout << "\nWhat would you like to do? ";
        cin >> choice;

        // Input validation for non-integer inputs
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(10000, '\n'); // Discard bad input
            choice = 0; // Reset choice to continue loop
            continue;
        }


        switch (choice) {
        case 1:
            cout << "Enter the file name (e.g., courses.csv): ";
            cin.ignore(); // Clear the input buffer
            getline(cin, csvPath); // Use the getline to read the entire name with spaces

            // Clear the tree before loading new data
            delete bst;
            bst = new BinarySearchTree();
            loadCourses(csvPath, bst);
            break;

        case 2:
            if (bst->IsEmpty()) {
                cout << "Please load data first (Option 1)." << endl;
            }
            else {
                cout << "\nHere is a sample schedule:" << endl;
                bst->InOrder();
            }
            break;

        case 3:
            if (bst->IsEmpty()) {
                cout << "Please load data first (Option 1)." << endl;
            }
            else {
                cout << "What course do you want to know about? ";
                cin >> courseKey;
                Course course = bst->Search(courseKey);

                if (!course.courseNumber.empty()) {
                    displayCourse(course, bst);
                }
                else {
                    cout << "Course '" << courseKey << "' not found." << endl;
                }
            }
            break;

        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;

        default:
            cout << choice << " is not a valid option." << endl;
            break;
        }
    }

    delete bst; // Clean up memory
    return 0;
}

