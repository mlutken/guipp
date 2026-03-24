#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    w.setLayout(new QVBoxLayout{});

    auto button = new QPushButton("Hello world!");
    w.layout()->addWidget(button);
    w.show();

    return a.exec(); // .exec starts QApplication and related GUI, this line starts 'event loop'
}

