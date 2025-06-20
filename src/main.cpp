// Advanced C++ Mastery Code Samples

// ==============================
// Module 1: Language Proficiency
// ==============================
#include <iostream>
#include <string>
#include <utility>

class Resource {
public:
    Resource(const std::string& name) : name_(name) {
        std::cout << "Acquiring resource: " << name_ << "\n";
    }
    ~Resource() {
        std::cout << "Releasing resource: " << name_ << "\n";
    }
    Resource(Resource&& other) noexcept : name_(std::move(other.name_)) {}
    Resource& operator=(Resource&& other) noexcept {
        name_ = std::move(other.name_);
        return *this;
    }
private:
    std::string name_;
};

void module1_demo() {
    Resource res1("FileHandle");
    Resource res2 = std::move(res1);
}

// ===============================
// Module 2: STL Containers/Algos
// ===============================
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    double gpa;
};

void module2_demo() {
    std::vector<Student> students = {{"Alice", 3.6}, {"Bob", 3.9}, {"Eve", 3.4}};
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.gpa > b.gpa;
    });
    for (const auto& s : students) {
        std::cout << s.name << " - " << s.gpa << "\n";
    }
}

// ==============================
// Module 3: Memory Management
// ==============================
#include <memory>

class FileHandler {
public:
    FileHandler(const std::string& path) {
        std::cout << "Opening file: " << path << "\n";
    }
    ~FileHandler() {
        std::cout << "Closing file.\n";
    }
};

void module3_demo() {
    std::unique_ptr<FileHandler> fh = std::make_unique<FileHandler>("/tmp/log.txt");
}

// =============================================
// Module 4: Dynamic Polymorphism & C++ Concepts
// =============================================

class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Circle\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Rectangle\n";
    }
};

void module4_demo() {
    Shape* s1 = new Circle();
    Shape* s2 = new Rectangle();
    s1->draw();
    s2->draw();
    delete s1;
    delete s2;
}

// ================================
// Module 5: System Call Wrappers
// ================================
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

class FileDescriptor {
public:
    FileDescriptor(const char* path) {
        fd_ = open(path, O_RDONLY);
        if (fd_ < 0) {
            perror("open");
        }
    }
    ~FileDescriptor() {
        if (fd_ >= 0) close(fd_);
    }
    void readFile() {
        char buf[128];
        ssize_t bytes = read(fd_, buf, sizeof(buf) - 1);
        if (bytes > 0) {
            buf[bytes] = '\0';
            std::cout << "Content: " << buf << "\n";
        }
    }
private:
    int fd_;
};

void module5_demo() {
    FileDescriptor fd("/etc/hostname");
    fd.readFile();
}

// ======================
// Main Function to Demo
// ======================

int main() {
    std::cout << "\nModule 1: Language Proficiency\n";
    module1_demo();

    std::cout << "\nModule 2: STL Containers and Algorithms\n";
    module2_demo();

    std::cout << "\nModule 3: Memory Management\n";
    module3_demo();

    std::cout << "\nModule 4: Dynamic Polymorphism\n";
    module4_demo();

    std::cout << "\nModule 5: System Call Wrappers\n";
    module5_demo();

    return 0;
}
