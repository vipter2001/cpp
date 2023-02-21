#include <iostream>
using namespace std;

// main function -
// where the execution of program begins
int main()
{
#include <QtApplication>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QtApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Calculator");

    // Create the input fields
    QLineEdit *num1Edit = new QLineEdit(&window);
    QLineEdit *num2Edit = new QLineEdit(&window);
    QLineEdit *resultEdit = new QLineEdit(&window);
    resultEdit->setReadOnly(true);

    // Create the labels
    QLabel *num1Label = new QLabel("Number 1:", &window);
    QLabel *num2Label = new QLabel("Number 2:", &window);
    QLabel *resultLabel = new QLabel("Result:", &window);

    // Create the buttons
    QPushButton *addButton = new QPushButton("+", &window);
    QPushButton *subButton = new QPushButton("-", &window);
    QPushButton *mulButton = new QPushButton("*", &window);
    QPushButton *divButton = new QPushButton("/", &window);
    QPushButton *clearButton = new QPushButton("Clear", &window);

    // Create the layout
    QGridLayout *layout = new QGridLayout(&window);
    layout->addWidget(num1Label, 0, 0);
    layout->addWidget(num1Edit, 0, 1);
    layout->addWidget(num2Label, 1, 0);
    layout->addWidget(num2Edit, 1, 1);
    layout->addWidget(addButton, 2, 0);
    layout->addWidget(subButton, 2, 1);
    layout->addWidget(mulButton, 3, 0);
    layout->addWidget(divButton, 3, 1);
    layout->addWidget(resultLabel, 4, 0);
    layout->addWidget(resultEdit, 4, 1);
    layout->addWidget(clearButton, 5, 0, 1, 2);

    // Connect the buttons to the appropriate functions
    QObject::connect(addButton, &QPushButton::clicked, [&](){
        double num1 = num1Edit->text().toDouble();
        double num2 = num2Edit->text().toDouble();
        double result = num1 + num2;
        resultEdit->setText(QString::number(result));
    });

    QObject::connect(subButton, &QPushButton::clicked, [&](){
        double num1 = num1Edit->text().toDouble();
        double num2 = num2Edit->text().toDouble();
        double result = num1 - num2;
        resultEdit->setText(QString::number(result));
    });

    QObject::connect(mulButton, &QPushButton::clicked, [&](){
        double num1 = num1Edit->text().toDouble();
        double num2 = num2Edit->text().toDouble();
        double result = num1 * num2;
        resultEdit->setText(QString::number(result));
    });

    QObject::connect(divButton, &QPushButton::clicked, [&](){
        double num1 = num1Edit->text().toDouble();
        double num2 = num2Edit->text().toDouble();
        if (num2 == 0) {
            resultEdit->setText("Error: Division by zero");
        } else {
            double result = num1 / num2;
            resultEdit->setText(QString::number(result));
        }
    });

    QObject::connect(clearButton, &QPushButton::clicked, [&](){
        num1Edit->clear();
        num2Edit->clear();
        resultEdit->clear();
    });

    window.show();
    return app.exec();
}
}