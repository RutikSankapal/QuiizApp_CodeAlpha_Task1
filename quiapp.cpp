
#include <iostream>
#include <string>
#include <vector>

struct Question {
    std::string questionText;
    std::vector<std::string> options;
    int correctOption;
};

struct User {
    std::string username;
    int score;
};

int displayMenu() {
    int choice;
    std::cout << "\n1. Register\n2. Start Quiz\n3. Exit\nEnter your choice: ";
    std::cin >> choice;
    return choice;
}

std::string registerUser() {
    std::string username;
    std::cout << "\nEnter your username: ";
    std::cin >> username;
    return username;
}

int conductQuiz(const std::vector<Question>& questions) {
    int score = 0;
    for (const auto& question : questions) {
        std::cout << "\n" << question.questionText << "\n";
        for (size_t i = 0; i < question.options.size(); ++i) {
            std::cout << i + 1 << ". " << question.options[i] << "\n";
        }

        int userAnswer;
        std::cout << "Enter your choice (1-" << question.options.size() << "): ";
        std::cin >> userAnswer;

        if (userAnswer == question.correctOption) {
            std::cout << "Correct!\n";
            score++;
        } else {
            std::cout << "Incorrect! The correct answer is: " << question.correctOption << ". " << question.options[question.correctOption - 1] << "\n";
        }
    }
    return score;
}

int main() {
    std::vector<Question> quizQuestions = {
        {"What is the capital of France?", {"Berlin", "Paris", "Madrid", "Rome"}, 2},
        {"Which planet is known as the Red Planet?", {"Mars", "Venus", "Jupiter", "Saturn"}, 1},
        {"What is the largest mammal?", {"Elephant", "Blue Whale", "Giraffe", "Hippopotamus"}, 2}
        // Add more questions as needed
    };

    User user;
    user.score = 0;

    while (true) {
        int choice = displayMenu();

        switch (choice) {
            case 1:
                user.username = registerUser();
                std::cout << "Registration successful! Welcome, " << user.username << "!\n";
                break;

            case 2:
                if (user.username.empty()) {
                    std::cout << "Please register first.\n";
                } else {
                    user.score = conductQuiz(quizQuestions);
                    std::cout << "\nQuiz completed! Your score: " << user.score << "/" << quizQuestions.size() << "\n";
                }
                break;

            case 3:
                std::cout << "Exiting the quiz. Goodbye!\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

