#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>
#include <filesystem>

//// SBExercise3561
void ex1() {
    for (auto n : {1, 2, 3, 4, 5}) std::cout << n << std::endl;
}

//// SBExercise3562
void ex2() {
    auto uniqueNums = [](std::vector<int>& numbers) {
        std::unordered_set<int> unique;
        auto result = std::make_unique<std::vector<int>>();

        for (auto n : numbers) {
            if (unique.count(n)) continue;
            result->push_back(n);
            unique.insert(n);
        }
        return result;
    };

    std::vector<int> numbers = {1,1,2,2,3,3,4,4,5,5,4,4};
    auto unique = uniqueNums(numbers);
    for (auto n : *(unique.get())) std::cout << n << ' ';
    std::cout << std::endl;
}

//// SBExercise3563
void ex3() {
    auto recursiveFileNamesByExt = [](std::filesystem::path& path, const std::string& extension) {
        auto result = std::make_unique<std::vector<std::string>>();
        for (auto& p: std::filesystem::recursive_directory_iterator(path)) {
            auto& filepath = p.path();
            if (filepath.extension().compare(extension) == 0) result->push_back(filepath.string());
        }
        return result;
    };

    std::cout << "Enter directory path and extension filter of files you want to display:" << std::endl;
    std::string path_input, extension;
    std::getline(std::cin, path_input);
    std::getline(std::cin, extension);

    if (extension.front() != '.') extension = '.' + extension;

    auto path = std::filesystem::path(path_input);
    auto names = recursiveFileNamesByExt(path, extension);

    for (auto& name : *names) std::cout << name << std::endl;
}

int main() {
    std::cout << "Exercise 35.6.1:" << std::endl;
    ex1();
    std::cout << std::endl;

    std::cout << "Exercise 35.6.2:" << std::endl;
    ex2();
    std::cout << std::endl;

    std::cout << "Exercise 35.6.3:" << std::endl;
    ex3();
    std::cout << std::endl;
    return 0;
}