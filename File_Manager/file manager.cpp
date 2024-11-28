#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

// Function to display the current directory contents
void displayDirContents(const std::string& dirPath) {
    std::filesystem::path dir(dirPath);
    if (std::filesystem::exists(dir) && std::filesystem::is_directory(dir)) {
        for (const auto& entry : std::filesystem::directory_iterator(dir)) {
            std::cout << entry.path().filename() << std::endl;
        }
    } else {
        std::cout << "Invalid directory path" << std::endl;
    }
}

// Function to create a new directory
void createDir(const std::string& dirPath) {
    std::filesystem::path dir(dirPath);
    if (!std::filesystem::exists(dir)) {
        std::filesystem::create_directory(dir);
        std::cout << "Directory created successfully" << std::endl;
    } else {
        std::cout << "Directory already exists" << std::endl;
    }
}

// Function to copy a file
void copyFile(const std::string& srcPath, const std::string& destPath) {
    std::filesystem::path src(srcPath), dest(destPath);
    if (std::filesystem::exists(src) && std::filesystem::is_regular_file(src)) {
        std::filesystem::copy_file(src, dest);
        std::cout << "File copied successfully" << std::endl;
    } else {
        std::cout << "Invalid source file path" << std::endl;
    }
}

// Function to move a file
void moveFile(const std::string& srcPath, const std::string& destPath) {
    std::filesystem::path src(srcPath), dest(destPath);
    if (std::filesystem::exists(src) && std::filesystem::is_regular_file(src)) {
        std::filesystem::rename(src, dest);
        std::cout << "File moved successfully" << std::endl;
    } else {
        std::cout << "Invalid source file path" << std::endl;
    }
}

int main() {
    std::string currentDir = ".";

    while (true) {
        std::cout << "FileManager>" << std::endl;
        std::cout << "1. Display directory contents" << std::endl;
        std::cout << "2. Create directory" << std::endl;
        std::cout << "3. Copy file" << std::endl;
        std::cout << "4. Move file" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayDirContents(currentDir);
                break;
            case 2:
                {
                    std::string newDirName;
                    std::cout << "Enter new directory name: ";
                    std::cin >> newDirName;
                    createDir(newDirName);
                }
                break;
            case 3:
                {
                    std::string srcPath, destPath;
                    std::cout << "Enter source file path: ";
                    std::cin >> srcPath;
                    std::cout << "Enter destination file path: ";
                    std::cin >> destPath;
                    copyFile(srcPath, destPath);
                }
                break;
            case 4:
                {
                    std::string srcPath, destPath;
                    std::cout << "Enter source file path: ";
                    std::cin >> srcPath;
                    std::cout << "Enter destination file path: ";
                    std::cin >> destPath;
                    moveFile(srcPath, destPath);
                }
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }

    return 0;
}