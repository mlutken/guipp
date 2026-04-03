#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "test_page_a1.h"
#include "data_source.h"


int main(int argc, char *argv[])
{
    data_source_playground_1();
    exit(0);    // FIXMENM

    QApplication a(argc, argv);

    test_page_a1 w;

    // QWidget w;
    // w.setLayout(new QVBoxLayout{});
    // auto button = new QPushButton("Hello world!");
    // w.layout()->addWidget(button);
    w.show();

    return a.exec(); // .exec starts QApplication and related GUI, this line starts 'event loop'
}

