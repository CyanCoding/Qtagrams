#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>
#include <string>
#include <algorithm>

// Runs when the window is opened
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

// Runs when the window is closed
MainWindow::~MainWindow() {
    delete ui;
}

std::vector<std::string> guesses; // string permutations
// Finds every permutation (non-duplicate anagrams) of a string.
int inline decodeAnagram(std::string anagram) {
    std::sort(anagram.begin(), anagram.end());

    int attempts = 0;

    do {
        attempts++;
        guesses.push_back(anagram);
    } while (std::next_permutation(anagram.begin(), anagram.end()));

    return attempts;
}

// When the "Find" button is pressed
void MainWindow::on_pushButton_clicked() {
    QString anagram = ui->textEdit->toPlainText();

    guesses.clear(); // We have to clear our guesses before making new ones
    int amount = decodeAnagram(anagram.toStdString());

    QString results = "";
    for (std::string guess : guesses) {
        results += QString::fromStdString(guess) + "\n";
    }

    // Set the text
    ui->textEdit_2->setText(results);
    ui->label_2->setText("Anagrams (" + QString::number(amount) + ")");

}

